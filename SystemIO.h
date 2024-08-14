#ifndef SYSTEMIO_H
#define SYSTEMIO_H

#include "Global.h"
#include "Rendering\Mesh.h"
#include <d3dx8.h>
#include <d3d8.h>

MESH_DATA LoadXMeshFile(LPDIRECT3DDEVICE8 pd3dDevice, LPSTR filename);

#endif