#include "SystemIO.h"
#include <stdio.h>
#include <xgraphics.h>
#include "Mesh.h"

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
BYTE* g_pResourceSysMemData = NULL; // Sysmem data for the packed resource
BYTE* g_pResourceVidMemData = NULL; // Vidmem data for the packed resource

//-----------------------------------------------------------------------------
// Name: FindResourceByName()
// Desc: Loads all the texture resources from the given XPR.
//-----------------------------------------------------------------------------
VOID* FindResourceByName( const CHAR* strName )
{
    if( NULL==g_pResourceSysMemData || NULL==strName )
        return NULL;

	/* for ( int i = 0; i < resource_NUM_RESOURCES; i++ ) {
		if( !_stricmp( strName, //TODO  resource name at i? ) ) {
			return g_pResourceSysMemData[i];
		}
	} */

	// For this simple tutorial, this is hard-coded.
    if( !_stricmp( strName, "Tiger.bmp" ) )
        return &g_pResourceSysMemData[0UL];

    return NULL;
}

//-----------------------------------------------------------------------------
// Name: LoadPackedResource()
// Desc: Loads all the texture resources from the given XPR.
//-----------------------------------------------------------------------------
HRESULT LoadPackedResource( const CHAR* strResourceFilename )
{
    // Open the file to read the XPR headers
    FILE* file = fopen( strResourceFilename, "rb" );
    if( NULL == file )
        return E_FAIL;

    // Read in and verify the XPR magic header
    XPR_HEADER xprh;
    if( fread( &xprh, sizeof(XPR_HEADER), 1, file ) != 1 )
    {
        fclose(file);
        return E_FAIL;
    }

    if( xprh.dwMagic != XPR_MAGIC_VALUE )
    {
        OutputDebugStringA( "ERROR: Invalid Xbox Packed Resource (.xpr) file" );
        fclose( file );
        return E_INVALIDARG;
    }

    // Compute memory requirements
    DWORD dwSysMemDataSize = xprh.dwHeaderSize - sizeof(XPR_HEADER);
    DWORD dwVidMemDataSize = xprh.dwTotalSize - xprh.dwHeaderSize;

    // Allocate memory
    g_pResourceSysMemData = new BYTE[dwSysMemDataSize];
    g_pResourceVidMemData = (BYTE*)D3D_AllocContiguousMemory( dwVidMemDataSize, D3DTEXTURE_ALIGNMENT );

    // Read in the data from the file
    if( fread( g_pResourceSysMemData, dwSysMemDataSize, 1, file ) != 1 ||
        fread( g_pResourceVidMemData, dwVidMemDataSize, 1, file ) != 1 )
        
    {
        delete[] g_pResourceSysMemData;
        D3D_FreeContiguousMemory( g_pResourceVidMemData );
        fclose( file );
        return E_FAIL;
    }

    // Done with the file
    fclose( file );
    
    // Loop over resources, calling Register()
    BYTE* pData = g_pResourceSysMemData;

    for( DWORD i = 0; i < resource_NUM_RESOURCES; i++ )
    {
        // Get the resource
        LPDIRECT3DRESOURCE8 pResource = (LPDIRECT3DRESOURCE8)pData;

        // Register the resource
        pResource->Register( g_pResourceVidMemData );
    
        // Advance the pointer
        switch( pResource->GetType() )
        {
            case D3DRTYPE_TEXTURE:       pData += sizeof(D3DTexture);       break;
            case D3DRTYPE_VOLUMETEXTURE: pData += sizeof(D3DVolumeTexture); break;
            case D3DRTYPE_CUBETEXTURE:   pData += sizeof(D3DCubeTexture);   break;
            case D3DRTYPE_VERTEXBUFFER:  pData += sizeof(D3DVertexBuffer);  break;
            case D3DRTYPE_INDEXBUFFER:   pData += sizeof(D3DIndexBuffer);   break;
            case D3DRTYPE_PALETTE:       pData += sizeof(D3DPalette);       break;
            default:                     return E_FAIL;
        }
    }

    return S_OK;
}

//-----------------------------------------------------------------------------
// Name: LoadXBGFile()
// Desc: 
//-----------------------------------------------------------------------------
HRESULT LoadXBGFile( const CHAR* strMeshFilename )
{
    // Open the file
    FILE* file = fopen( strMeshFilename, "rb" );
    if( file == NULL )
    {
        OutputDebugStringA( "ERROR: Mesh file not found!\n" );
        return E_FAIL;
    }

    // Read the magic number
    DWORD dwFileID;
    fread( &dwFileID, 1, sizeof(DWORD), file ); 

    // The magic number to identify .xbg files
    const DWORD XBG_FILE_ID  = (((DWORD)'X'<<0)|(((DWORD)'B'<<8))|(((DWORD)'G'<<16))|(2<<24));

    if( dwFileID != XBG_FILE_ID )
    {
        OutputDebugStringA( "ERROR: Invalid XBG file type!\n" );
        fclose( file );
        return E_FAIL;
    }

    // Read in header
    DWORD dwNumFrames;  // Number of mesh frames in the file
    DWORD dwSysMemSize; // Num bytes needed for system memory objects
    DWORD dwVidMemSize; // Num bytes needed for video memory objects

    fread( &dwNumFrames,  1, sizeof(DWORD), file );
    fread( &dwSysMemSize, 1, sizeof(DWORD), file );
    fread( &dwVidMemSize, 1, sizeof(DWORD), file );

    // Read in system memory objects
    g_pMeshSysMemData = (VOID*)new BYTE[dwSysMemSize];
    fread( g_pMeshSysMemData, dwSysMemSize, 1, file );

    // Read in video memory objects
    g_pMeshVidMemData = D3D_AllocContiguousMemory( dwVidMemSize, D3DVERTEXBUFFER_ALIGNMENT );
    fread( g_pMeshVidMemData, dwVidMemSize, 1, file ); 
    
    // Done with the file
    fclose( file );

    // Now we need to patch the mesh data. Any pointers read from the file were
    // stored as file offsets. So, we simply need to add a base address to patch
    // things up.
    g_pMeshFrames = (XBMESH_FRAME*)g_pMeshSysMemData;
    g_dwNumMeshFrames = dwNumFrames;

    for( DWORD i=0; i<g_dwNumMeshFrames; i++ )
    {
        XBMESH_FRAME* pFrame = &g_pMeshFrames[i];
        XBMESH_DATA*  pMesh  = &g_pMeshFrames[i].m_MeshData;

        if( pFrame->m_pChild )
            pFrame->m_pChild  = (XBMESH_FRAME*)( (DWORD)pFrame->m_pChild - 16 + (DWORD)g_pMeshFrames );
        if( pFrame->m_pNext )
            pFrame->m_pNext   = (XBMESH_FRAME*)( (DWORD)pFrame->m_pNext  - 16 + (DWORD)g_pMeshFrames );
        if( pMesh->m_pSubsets )
            pMesh->m_pSubsets = (XBMESH_SUBSET*)( (DWORD)pMesh->m_pSubsets - 16 + (DWORD)g_pMeshFrames);
        
        if( pMesh->m_dwNumIndices )
            pMesh->m_IB.Data  = pMesh->m_IB.Data - 16 + (DWORD)g_pMeshFrames;
        if( pMesh->m_dwNumVertices )
            pMesh->m_VB.Register( g_pMeshVidMemData );
    }

    // Finally, create any textures used by the meshes' subsets. In this 
    // implementation, we are pulling textures out of the global resource.
    for( DWORD i=0; i<g_dwNumMeshFrames; i++ )
    {
        XBMESH_DATA* pMesh = &g_pMeshFrames[i].m_MeshData;

        for( DWORD j = 0; j < pMesh->m_dwNumSubsets; j++ )
        {
            XBMESH_SUBSET* pSubset = &pMesh->m_pSubsets[j];

            pSubset->pTexture = (LPDIRECT3DTEXTURE8)FindResourceByName( pSubset->strTexture );
        }
    }

    return S_OK;
}