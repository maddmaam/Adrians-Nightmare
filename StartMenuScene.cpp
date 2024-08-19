#include "StartMenuScene.h"

CUSTOMVERTEX cvVertices[] =
{
	{ -1.0f, -1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 0.0f, 1.0f },  //Front face
    { -1.0f,  1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 0.0f, 0.0f },
    {  1.0f,  1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 1.0f, 0.0f },
    {  1.0f,  1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 1.0f, 0.0f },
    {  1.0f, -1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 1.0f, 1.0f },
    { -1.0f, -1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 0.0f, 1.0f }
};
LPDIRECT3DTEXTURE8 Texture;

//-----------------------------------------------------------------------------
// Name: Init()
// Desc: Load the mesh and build the material and texture arrays
//-----------------------------------------------------------------------------
HRESULT StartMenuScene::Init()
{
	Texture = LoadTexture(g_pd3dDevice, "D:\\Media\\startMenu.bmp");	

	//TEMP
	g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(150,0,0), 1.0f, 0 );
	g_pd3dDevice->BeginScene();

	//SetupMatrices();

	RenderTexture(cvVertices, Texture);

	g_Sound.Create("D:\\Media\\becky.wma");
	g_Sound.PlaySound();

	g_pd3dDevice->EndScene();
    // Present the backbuffer contents to the display
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );

	

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
void StartMenuScene::Render()
{
	// Clear the backbuffer and the zbuffer
	//DisplayText("TEST", 10L, 10L);
}

void StartMenuScene::Update()
{
	if (StartButtonPressed()) {
		sceneManager.switchScene(1);
	}
}
