#ifndef SYSTEMIO_H
#define SYSTEMIO_H

#include "Global.h"
#include <DMusicI.h>
#include "Rendering\Mesh.h"

extern IDirectMusicLoader* g_pLoader;

HRESULT InitIO();

HRESULT LoadSound(LPSTR filename, IDirectMusicSegment8** pSoundSegment);

HRESULT LoadXMeshFile(LPDIRECT3DDEVICE8 pd3dDevice, LPSTR filename, MESH_DATA* mesh);

HRESULT LoadTexture(LPDIRECT3DDEVICE8 pd3dDevice, LPSTR filename, LPDIRECT3DTEXTURE8* tex);

#endif