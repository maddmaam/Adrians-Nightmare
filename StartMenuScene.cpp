#include "StartMenuScene.h"

CUSTOMVERTEX cvVertices[] = {
      // x      y      z           colour           tu     tv
   { -1.0f, -1.0f, -1.0f, D3DCOLOR_XRGB(255,0,0), 0.0f, 1.0f },  //Front face
   { -1.0f,  1.0f, -1.0f, D3DCOLOR_XRGB(255,0,0), 0.0f, 0.0f },
   {  1.0f,  1.0f, -1.0f, D3DCOLOR_XRGB(255,0,0), 1.0f, 0.0f },
   {  1.0f,  1.0f, -1.0f, D3DCOLOR_XRGB(255,0,0), 1.0f, 0.0f },
   {  1.0f, -1.0f, -1.0f, D3DCOLOR_XRGB(255,0,0), 1.0f, 1.0f },
   { -1.0f, -1.0f, -1.0f, D3DCOLOR_XRGB(255,0,0), 0.0f, 1.0f }
};

LPDIRECT3DTEXTURE8 Texture;

//-----------------------------------------------------------------------------
// Name: Init()
// Desc: Load the mesh and build the material and texture arrays
//-----------------------------------------------------------------------------
HRESULT StartMenuScene::Init()
{
	Texture = LoadTexture(g_pd3dDevice, "D:\\Media\\mainTexture.bmp");
	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
void StartMenuScene::Render()
{
	// Clear the backbuffer and the zbuffer
    g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
                         D3DCOLOR_XRGB(0,0,50), 1.0f, 0 );
    
	SetupMatrices();

	RenderTexture(cvVertices, Texture);

    // Present the backbuffer contents to the display
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}

void StartMenuScene::Update()
{
}
