#include "Mesh.h"

VOID* g_pMeshSysMemData = NULL;
VOID* g_pMeshVidMemData = NULL;
XBMESH_FRAME* g_pMeshFrames = NULL;
DWORD g_dwNumMeshFrames = 0UL; 

//-----------------------------------------------------------------------------
// Name: RenderMesh()
// Desc: Renders the mesh geometry.
//-----------------------------------------------------------------------------
HRESULT RenderMesh( LPDIRECT3DDEVICE8 pd3dDevice, XBMESH_DATA* pMesh )
{
    if( pMesh->m_dwNumVertices == 0 )
        return S_OK;

    // Set the vertex stream
    pd3dDevice->SetStreamSource( 0, &pMesh->m_VB, pMesh->m_dwVertexSize );
    pd3dDevice->SetIndices( &pMesh->m_IB, 0 );

    // Set the FVF code, unless the user asked us not to
    pd3dDevice->SetVertexShader( pMesh->m_dwFVF );

    // Render the subsets
    for( DWORD i = 0; i < pMesh->m_dwNumSubsets; i++ )
    {
        // Set the material
        pd3dDevice->SetMaterial( &pMesh->m_pSubsets[i].mtrl );

        // Set the texture.
        pd3dDevice->SetTexture( 0, pMesh->m_pSubsets[i].pTexture );

        // Draw the mesh subset
        if( D3DPT_TRIANGLESTRIP == pMesh->m_dwPrimType )
            pd3dDevice->DrawIndexedPrimitive( pMesh->m_dwPrimType, 0, 
                                              pMesh->m_pSubsets[i].dwIndexCount,
                                              pMesh->m_pSubsets[i].dwIndexStart, 
                                              pMesh->m_pSubsets[i].dwIndexCount-2 );
        else // D3DPT_TRIANGLELIST
            pd3dDevice->DrawIndexedPrimitive( pMesh->m_dwPrimType, 0, 
                                              pMesh->m_pSubsets[i].dwIndexCount,
                                              pMesh->m_pSubsets[i].dwIndexStart, 
                                              pMesh->m_pSubsets[i].dwIndexCount/3 );
    }

    return S_OK;
}