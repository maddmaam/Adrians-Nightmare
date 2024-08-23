#include "StartMenuScene.h"

// Vertices for our image screen
CUSTOMVERTEX cvVertices[] =
{
	{ -1.0f, -1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 0.0f, 1.0f },  //Front face
    { -1.0f,  1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 0.0f, 0.0f },
    {  1.0f,  1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 1.0f, 0.0f },
    {  1.0f,  1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 1.0f, 0.0f },
    {  1.0f, -1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 1.0f, 1.0f },
    { -1.0f, -1.0f, 0.0f, D3DCOLOR_XRGB(255,255,255), 0.0f, 1.0f }
};

//-----------------------------------------------------------------------------
// Name: Init()
// Desc: Load the mesh and build the material and texture arrays
//-----------------------------------------------------------------------------
HRESULT StartMenuScene::Init()
{
	LoadTexture(g_pd3dDevice, "D:\\Media\\startMenu.bmp", &MainTexture);
	LoadTexture(g_pd3dDevice, "D:\\Media\\startMenu_noText.bmp", &MainTextureNoText);

	// Sets up background audio
	GameMusic.Create("adriansnightmare.wav");
	GameMusic.setLoop(DMUS_SEG_REPEAT_INFINITE);
	GameMusic.PlaySound(g_MusicAudioPath);


	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
void StartMenuScene::Render()
{
	int value = int(fTime * 2) % 2;
	if(value == 0)
	{
		RenderVertices(cvVertices, MainTexture);
	} else
	{
		RenderVertices(cvVertices, MainTextureNoText);
	}
}


//-----------------------------------------------------------------------------
// Name: Update()
// Desc: Updates the scene
//-----------------------------------------------------------------------------
void StartMenuScene::Update()
{
	if (StartButtonPressed()) {
		sceneManager.switchScene(1);
	}
}

//-----------------------------------------------------------------------------
// Name: Cleanup()
// Desc: Cleans the scene
//-----------------------------------------------------------------------------
void StartMenuScene::Cleanup()
{
	GameMusic.StopSound();
	MainTexture->Release();
	GameMusic.Release();
}
