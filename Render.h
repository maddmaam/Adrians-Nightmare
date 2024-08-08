// Time.h : include file for Time include files
#pragma once

#include <xtl.h>

extern LPDIRECT3DDEVICE8 g_pd3dDevice;

HRESULT InitD3D();
HRESULT InitVB();
void Render();