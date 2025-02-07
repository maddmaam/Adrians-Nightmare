// Example_Project.cpp : Defines the entry point for the application.
#include "Example_Project.h"

#include "Scenes/StartMenuScene.h"
#include "Scenes/GameScene.h"

//-----------------------------------------------------------------------------
// Name: main()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
void __cdecl main()
{
    // Initialize Direct3D
    if( FAILED( InitD3D() ) )
        return; //critical failure

	// Initialize Time
	if( FAILED( InitTime() ) )
        return; //critical failure

	// Initialize Input
	if( FAILED( InitInput() ) )
		return; // TODO print to debug

	// Initialize Sound
	if( FAILED( InitSound() ) )
		return; // TODO print to debug

	// Initialize IO
	if( FAILED( InitIO() ) )
		return; // TODO print to debug


	// Create pointer to the Start menu scene
	StartMenuScene StartMenu;
	StartMenuScene* StartMenuPtr = &StartMenu;

	// Create pointer to the Game scene 
	GameScene Game;
	GameScene* GamePtr = &Game;

	// Add scenes to SceneManager
	sceneManager.addScene(StartMenuPtr); //scene 0
	sceneManager.addScene(GamePtr); //scene 1

	// switch to the Start menu scene
	sceneManager.switchScene(0);


	// Loop for forever
    while( TRUE )
    {
        // Update Time
        UpdateTime();
        // Update the Scene
        sceneManager.activeScene->Update();

		// Clear the backbuffer and the zbuffer
		g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,0,0), 1.0f, 0 );
		g_pd3dDevice->BeginScene();

        // Render the Scene
        sceneManager.activeScene->Render();

		// Present the backbuffer contents to the display
		g_pd3dDevice->EndScene();
		g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
    }
}