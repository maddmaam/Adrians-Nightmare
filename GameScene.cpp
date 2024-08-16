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

MESH_DATA mesh;
LPDIRECT3DTEXTURE8 groundTexture;

inputVector screenRotation;

//-----------------------------------------------------------------------------
// Name: Init()
// Desc: Load the mesh and build the material and texture arrays
//-----------------------------------------------------------------------------
HRESULT GameScene::Init()
{
	mesh = LoadXMeshFile(g_pd3dDevice, "D:\\Media\\adrian.x");
	groundTexture = LoadTexture(g_pd3dDevice, "D:\\Media\\grass.bmp");
	
	InitLighting();

	D3DXMatrixIdentity(&matrixWorld);
	// Load geometry from the XBG file
    //if( FAILED( LoadXBGFile( "D:\\Media\\Tiger.xbg" ) ) )
    //    return E_FAIL;
	
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

	screenRotation.x += getControllerAxis().x;
	screenRotation.y += getControllerAxis().y;

	if(screenRotation.y < -1.0)
		screenRotation.y = -0.99f;
	if(screenRotation.y > 0.1)
		screenRotation.y = 0.09f;

	D3DXMatrixRotationYawPitchRoll(&matrixWorld, screenRotation.x, cos(screenRotation.x) * screenRotation.y, sin(screenRotation.x) * screenRotation.y);
	g_pd3dDevice->SetTransform( D3DTS_WORLD, &matrixWorld); 
	
	RenderMesh(g_pd3dDevice, mesh);

	RenderTexture(groundVertices, groundTexture);

    // Present the backbuffer contents to the display
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}

void GameScene::Update()
{
}
