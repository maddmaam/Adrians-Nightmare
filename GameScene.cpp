#include "GameScene.h"
#include "Input.h"

MESH_DATA mesh;

//-----------------------------------------------------------------------------
// Name: Init()
// Desc: Load the mesh and build the material and texture arrays
//-----------------------------------------------------------------------------
HRESULT GameScene::Init()
{
	mesh = LoadXMeshFile(g_pd3dDevice, "D:\\Media\\Tiger.x");

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

	RotateWorldFromController();

	RenderMesh(g_pd3dDevice, mesh);

    // Present the backbuffer contents to the display
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}

void GameScene::Update()
{
}
