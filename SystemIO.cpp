#include "SystemIO.h"
#include <stdio.h>

IDirectMusicLoader* g_pLoader = NULL;

//-----------------------------------------------------------------------------
// Name: InitIO()
// Desc: Initialize IO and file loading
//-----------------------------------------------------------------------------
HRESULT InitIO()
{
	// Create audio file loader
	HRESULT result;
	if( FAILED(result = DirectMusicCreateInstance(CLSID_DirectMusicLoader, NULL, IID_IDirectMusicLoader8, (VOID**)&g_pLoader)))
	{
		return result;
	}
	if( FAILED(result = g_pLoader->SetSearchDirectory(GUID_DirectMusicAllTypes, "D:\\Media\\", FALSE)))
	{
		return result;
	}

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: LoadSound()
// Desc: Loads a sound file
//-----------------------------------------------------------------------------
HRESULT LoadSound(LPSTR filename, IDirectMusicSegment8** pSoundSegment)
{
	HRESULT result;
	if( FAILED(result = g_pLoader->LoadObjectFromFile(CLSID_DirectMusicSegment, IID_IDirectMusicSegment8 , filename, (VOID**) pSoundSegment)))
	{
		return result;
	}
	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: LoadXMeshFile()
// Desc: loads a .x file into a MESH_DATA struct
//-----------------------------------------------------------------------------
HRESULT LoadXMeshFile(LPDIRECT3DDEVICE8 pd3dDevice, LPSTR filename, MESH_DATA* outMesh)
{

	HRESULT result;
	if( FAILED(result = D3DXLoadMeshFromX( filename, D3DXMESH_VB_DYNAMIC, pd3dDevice, NULL, &outMesh->pMtrlBuffer, (PDWORD)&(outMesh->numMaterials), &(outMesh->mesh))))
	{
		return result;
	}
	
    //Create two arrays. One to hold the materials and only to hold the textures
    outMesh->pMeshMaterials = new D3DMATERIAL8[outMesh->numMaterials];
    outMesh->pMeshTextures  = new LPDIRECT3DTEXTURE8[outMesh->numMaterials];
    outMesh->matMaterials = (D3DXMATERIAL*)outMesh->pMtrlBuffer->GetBufferPointer();

    // Loop through each described material
    for(DWORD i = 0; i < outMesh->numMaterials; i++)
    {
		//Copy the material
        outMesh->pMeshMaterials[i] = outMesh->matMaterials[i].MatD3D;

        //Set the ambient color for the material (D3DX does not do this)
        outMesh->pMeshMaterials[i].Ambient = outMesh->pMeshMaterials[i].Diffuse;

        //Create the texture
        if(FAILED(D3DXCreateTextureFromFile(pd3dDevice, outMesh->matMaterials[i].pTextureFilename, &(outMesh->pMeshTextures[i]))))
        {
			outMesh->pMeshTextures[i] = NULL;
        };
    }

	// Setup default Matrices
	D3DXMatrixIdentity( &outMesh->rotationMatrix);
	D3DXMatrixIdentity( &outMesh->translationMatrix);
	D3DXMatrixIdentity( &outMesh->scaleMatrix);

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: LoadTexture()
// Desc: loads a texture file
//-----------------------------------------------------------------------------
HRESULT LoadTexture(LPDIRECT3DDEVICE8 pd3dDevice, LPSTR filename, LPDIRECT3DTEXTURE8 *tex)
{
	D3DXCreateTextureFromFile(pd3dDevice, filename, tex);
	return S_OK;
}