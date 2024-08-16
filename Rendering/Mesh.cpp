#include "Mesh.h"

//-----------------------------------------------------------------------------
// Name: RenderMesh()
// Desc: Renders the mesh geometry.
//-----------------------------------------------------------------------------
void RenderMesh(LPDIRECT3DDEVICE8 pd3dDevice, MESH_DATA meshData)
{
	//set position and rotation
	D3DXMATRIX renderMatrix = matrixWorld * meshData.matrix;
	g_pd3dDevice->SetTransform( D3DTS_WORLD, &renderMatrix); 
    // Actually drawing something here!
    for(DWORD i = 0; i < meshData.numMaterials; i++)
    {
        pd3dDevice->SetMaterial(&meshData.pMeshMaterials[i]);
        pd3dDevice->SetTexture(0, meshData.pMeshTextures[i]);
        meshData.mesh->DrawSubset(i);
    }
	//meshData.mesh->DrawSubset(0);
}