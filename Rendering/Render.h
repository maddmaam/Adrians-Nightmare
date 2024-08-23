// Render.h : include file for Render include files
#ifndef RENDER_H
#define RENDER_H

#include "..\Global.h"
#include <xgraphics.h>
#include <d3dx8.h>
#include <d3d8.h>

extern LPDIRECT3DDEVICE8 g_pd3dDevice;
extern LPDIRECT3DVERTEXBUFFER8 g_pVertexBuffer;
extern D3DXMATRIX worldMatrix;
extern D3DXMATRIX worldTranslationMatrix;

// Defining a macro for our custom vertex structure
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1)

// A structure for our custom vertex type
struct CUSTOMVERTEX
{
    FLOAT x, y, z; // The transformed position for the vertex.
    DWORD colour; // The vertex colour.
    FLOAT tu, tv; // texture mapping positions
};

HRESULT InitD3D();

VOID EnableLighting();
VOID EnableFog();

VOID SetupMatrices();

void RenderVertices(CUSTOMVERTEX* cvVertices,  LPDIRECT3DTEXTURE8 pTexture);

void DisplayText(char * szStr, long xpos=100, long ypos=100, D3DCOLOR color = D3DCOLOR_XRGB(30,255,20));

#endif