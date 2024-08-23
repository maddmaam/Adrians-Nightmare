#include "GameScene.h"
#include "..\Input.h"

CUSTOMVERTEX groundVertices[] =
{
	{ -100.0f, 0.0f, -100.0f, D3DCOLOR_XRGB(255,255,255),  0.0f, 50.0f },  //Front face
    { -100.0f, 0.0f,  100.0f, D3DCOLOR_XRGB(255,255,255),  0.0f,  0.0f },
    {  100.0f, 0.0f,  100.0f, D3DCOLOR_XRGB(255,255,255), 50.0f,  0.0f },
    {  100.0f, 0.0f,  100.0f, D3DCOLOR_XRGB(255,255,255), 50.0f,  0.0f },
    {  100.0f, 0.0f, -100.0f, D3DCOLOR_XRGB(255,255,255), 50.0f, 50.0f },
    { -100.0f, 0.0f, -100.0f, D3DCOLOR_XRGB(255,255,255),  0.0f, 50.0f }
};

inputVectors screenRotation;

float xpos;
float ypos;
int index = 3;

//-----------------------------------------------------------------------------
// Name: Init()
// Desc: Load the mesh and build the material and texture arrays
//-----------------------------------------------------------------------------
HRESULT GameScene::Init()
{
	EnableLighting();
	EnableFog();

	LoadXMeshFile(g_pd3dDevice, "D:\\Media\\adrian.x", &AdrianMesh);
	LoadXMeshFile(g_pd3dDevice, "D:\\Media\\cfcard.x", &CfCardMesh);
	
	LoadTexture(g_pd3dDevice, "D:\\Media\\grass.bmp", &GroundTexture);

	Ambience.Create("ambience.wav");

	AdrianCry[0].Create("adrianCry.wav");
	AdrianCry[1].Create("CMinus.wav");
	AdrianCry[2].Create("Ethics.wav");
	AdrianCry[3].Create("HeyTeam.wav");
	AdrianCry[4].Create("Subreddits.wav");

	HeyTeam.Create("HeyTeam.wav");
	HeyTeam.PlaySound(g_SfxPath);

	Ambience.PlaySound(g_MusicAudioPath);

	// Set CfCard Position
	D3DXMatrixTranslation(&CfCardMesh.translationMatrix, 5, 1, 0);

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
void GameScene::Render()
{
    // Setup the world, view, and projection matrices
    SetupMatrices();

	// Set up camera changes
	screenRotation.rX -= getControllerAxis().rX * 2;
	screenRotation.rY += getControllerAxis().rY;

	if(screenRotation.rY < -1.0)
		screenRotation.rY = -1.0f;
	if(screenRotation.rY > 0.1)
		screenRotation.rY = 0.1f;

	D3DXMatrixTranslation(&worldTranslationMatrix, -xpos, 0, -ypos);
	D3DXMatrixRotationYawPitchRoll(&worldMatrix, screenRotation.rX, cos(screenRotation.rX) * screenRotation.rY, sin(screenRotation.rX) * screenRotation.rY);

	worldMatrix = worldTranslationMatrix * worldMatrix;

	
	RenderMesh(g_pd3dDevice, AdrianMesh);
	RenderMesh(g_pd3dDevice, CfCardMesh);

	RenderVertices(groundVertices, GroundTexture);
}
//-----------------------------------------------------------------------------
// Name: Update()
// Desc: Updates the scene
//-----------------------------------------------------------------------------
void GameScene::Update()
{
	if(buttonPressed(XINPUT_GAMEPAD_A) && AdrianCry[index].isPlaying()){
		index = ((index + 1) % (sizeof(AdrianCry) / sizeof(CSound)));
		AdrianCry[index].PlaySound(g_SfxPath);
	}

	xpos += 3 * ((cos(screenRotation.rX) * getControllerAxis().lX) - (sin(screenRotation.rX) * getControllerAxis().lY));
	ypos += 3 * ((sin(screenRotation.rX) * getControllerAxis().lX) + (cos(screenRotation.rX) * getControllerAxis().lY));

	// Update Adrian mesh Position
	D3DXMatrixTranslation(&AdrianMesh.translationMatrix, xpos, 0, ypos);
	// Update CfCard Rotation
	D3DXMatrixRotationYawPitchRoll(&CfCardMesh.rotationMatrix, fTime, 70, 0);
}

//-----------------------------------------------------------------------------
// Name: Cleanup()
// Desc: Cleans the scene
//-----------------------------------------------------------------------------
void GameScene::Cleanup()
{
	Ambience.StopSound();
	GroundTexture->Release();

	for(int i = 0; i < (sizeof(AdrianCry) / sizeof(CSound)); i++)
	{
		AdrianCry[i].Release();
	}
	HeyTeam.Release();
	Ambience.Release();
}
