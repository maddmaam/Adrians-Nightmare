#include "SystemIO.h"
#include <stdio.h>
#include "Rendering\Mesh.h"

//-----------------------------------------------------------------------------
// Name: LoadXMeshFile()
// Desc: 
//-----------------------------------------------------------------------------
MESH_DATA LoadXMeshFile(LPDIRECT3DDEVICE8 pd3dDevice, LPSTR filename)
{
	MESH_DATA mesh;

	D3DXLoadMeshFromX( filename, D3DXMESH_VB_DYNAMIC, pd3dDevice, NULL, &mesh.pMtrlBuffer, &mesh.numMaterials, &mesh.mesh);
	
    //Create two arrays. One to hold the materials and only to hold the textures
    mesh.pMeshMaterials = new D3DMATERIAL8[mesh.numMaterials];
    mesh.pMeshTextures  = new LPDIRECT3DTEXTURE8[mesh.numMaterials];
    mesh.matMaterials = (D3DXMATERIAL*)mesh.pMtrlBuffer->GetBufferPointer();

    // Loads of allocation etc here!
    for(DWORD i = 0; i < mesh.numMaterials; i++)
    {
		//Copy the material
        mesh.pMeshMaterials[i] = mesh.matMaterials[i].MatD3D;

        //Set the ambient color for the material (D3DX does not do this)
        mesh.pMeshMaterials[i].Ambient = mesh.pMeshMaterials[i].Diffuse;

        //Create the texture

        if(FAILED(D3DXCreateTextureFromFile(pd3dDevice, mesh.matMaterials[i].pTextureFilename, &mesh.pMeshTextures[i])))
        {
			mesh.pMeshTextures[i] = NULL;
        };
    }

	D3DXMatrixIdentity(&mesh.rotationMatrix);
	D3DXMatrixIdentity(&mesh.translationMatrix);

	return mesh;
}

LPDIRECT3DTEXTURE8 LoadTexture(LPDIRECT3DDEVICE8 pd3dDevice, LPSTR filename)
{
	LPDIRECT3DTEXTURE8 tex;
	D3DXCreateTextureFromFile(pd3dDevice, filename, &tex);
	return (LPDIRECT3DTEXTURE8)tex;
}