#ifndef MESH_H
#define MESH_H

#include "..\Global.h"
#include <d3dx8.h>
#include <d3d8.h>
#include "Render.h"

// A Structure containing all mesh data.
struct MESH_DATA 
{
	LPD3DXBUFFER pMtrlBuffer;
    DWORD numMaterials;
	D3DMATERIAL8* pMeshMaterials;
	LPDIRECT3DTEXTURE8* pMeshTextures;
	D3DXMATERIAL* matMaterials;
	LPD3DXMESH mesh;

	D3DXMATRIX translationMatrix;
	D3DXMATRIX rotationMatrix;
	D3DXMATRIX scaleMatrix;
};

void RenderMesh(LPDIRECT3DDEVICE8 pd3dDevice, MESH_DATA mesh);

#endif