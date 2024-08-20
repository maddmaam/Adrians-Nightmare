#include "GameScene.h"
#include "Input.h"

CUSTOMVERTEX groundVertices[] =
{
	{ -30.0f, 0.0f, -30.0f, D3DCOLOR_XRGB(255,255,255),  0.0f, 10.0f },  //Front face
    { -30.0f, 0.0f,  30.0f, D3DCOLOR_XRGB(255,255,255),  0.0f,  0.0f },
    {  30.0f, 0.0f,  30.0f, D3DCOLOR_XRGB(255,255,255), 10.0f,  0.0f },
    {  30.0f, 0.0f,  30.0f, D3DCOLOR_XRGB(255,255,255), 10.0f,  0.0f },
    {  30.0f, 0.0f, -30.0f, D3DCOLOR_XRGB(255,255,255), 10.0f, 10.0f },
    { -30.0f, 0.0f, -30.0f, D3DCOLOR_XRGB(255,255,255),  0.0f, 10.0f }
};

MESH_DATA adrianMesh;
MESH_DATA cfCardMesh;
LPDIRECT3DTEXTURE8 groundTexture;

inputVectors screenRotation;

//-----------------------------------------------------------------------------
// Name: Init()
// Desc: Load the mesh and build the material and texture arrays
//-----------------------------------------------------------------------------
HRESULT GameScene::Init()
{
	adrianMesh = LoadXMeshFile(g_pd3dDevice, "D:\\Media\\adrian.x");
	cfCardMesh = LoadXMeshFile(g_pd3dDevice, "D:\\Media\\cfcard.x");
	
	D3DXMatrixTranslation(&cfCardMesh.translationMatrix, 5, 1, 0);

	groundTexture = LoadTexture(g_pd3dDevice, "D:\\Media\\grass.bmp");
	
	InitLighting();

	D3DXMatrixIdentity(&matrixWorld);
	
	adrianCry.Create("adrianCry.wav");

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
void GameScene::Render()
{
	// Clear the backbuffer and the zbuffer
    g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
                         D3DCOLOR_XRGB(50,0,0), 1.0f, 0 );
    
    // Setup the world, view, and projection matrices
    SetupMatrices();

	//ground

	screenRotation.rX += getControllerAxis().lX * 2;
	screenRotation.rY += getControllerAxis().lY;

	if(screenRotation.rY < -1.0)
		screenRotation.rY = -1.0f;
	if(screenRotation.rY > 0.1)
		screenRotation.rY = 0.1f;

	D3DXMatrixRotationYawPitchRoll(&matrixWorld, screenRotation.rX, cos(screenRotation.rX) * screenRotation.rY, sin(screenRotation.rX) * screenRotation.rY);
	g_pd3dDevice->SetTransform( D3DTS_WORLD, &matrixWorld); 
	
	RenderMesh(g_pd3dDevice, adrianMesh);
	RenderMesh(g_pd3dDevice, cfCardMesh);

	RenderTexture(groundVertices, groundTexture);

    // Present the backbuffer contents to the display
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}

void GameScene::Update()
{
	if(buttonPressed(XINPUT_GAMEPAD_X && !adrianCry.isPlaying())){
		adrianCry.PlaySound(g_SfxPath);
	}

	D3DXMatrixTranslation(&adrianMesh.translationMatrix, getControllerAxis().rX * 20, 0, getControllerAxis().rY * 20);
	D3DXMatrixRotationYawPitchRoll(&cfCardMesh.rotationMatrix, fTime, 90, 0);
}
