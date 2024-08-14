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

HRESULT InitD3D();

VOID SetupMatrices();

#endif