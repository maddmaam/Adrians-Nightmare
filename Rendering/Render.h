// Render.h : include file for Render include files
#ifndef RENDER_H
#define RENDER_H

#include "..\Global.h"

extern LPDIRECT3DDEVICE8 g_pd3dDevice;

HRESULT InitD3D();

void Render();

#endif