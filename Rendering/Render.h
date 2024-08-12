// Render.h : include file for Render include files
#ifndef RENDER_H
#define RENDER_H

#include "..\Global.h"

extern LPDIRECT3DDEVICE8 g_pd3dDevice;
extern D3DXMATRIX matWorldX;
extern D3DXMATRIX matWorldY;
extern D3DXMATRIX matWorldZ;

HRESULT InitD3D();

void Render();

#endif