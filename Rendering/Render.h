// Render.h : include file for Render include files
#ifndef RENDER_H
#define RENDER_H

#include "..\Global.h"
#include <xgraphics.h>
#include <d3dx8.h>
#include <d3d8.h>
#include "Mesh.h"

extern LPDIRECT3DDEVICE8 g_pd3dDevice;
extern D3DXMATRIX matWorldX;
extern D3DXMATRIX matWorldY;
extern D3DXMATRIX matWorldZ;

extern LPDIRECT3DVERTEXBUFFER8 g_pVertexBuffer;

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1)

// A structure for our custom vertex type
struct CUSTOMVERTEX
{
	/*CUSTOMVERTEX() {}
	CUSTOMVERTEX(FLOAT startX, FLOAT startY, FLOAT startZ, DWORD startColour, FLOAT startTu, FLOAT startTv)
	{
		x = startX;
		y = startY;
		z = startZ;
		colour = startColour;
		tu = startTu;
		tv = startTv;
	}
	~CUSTOMVERTEX() {}*/

    FLOAT x, y, z; // The transformed position for the vertex.
    DWORD colour; // The vertex colour.
    FLOAT tu, tv;
};


HRESULT InitD3D();

VOID SetupMatrices();

void RenderTexture(CUSTOMVERTEX* cvVertices,  LPDIRECT3DTEXTURE8 pTexture);

#endif