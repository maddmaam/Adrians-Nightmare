// Example_Project.cpp : Defines the entry point for the application.
#include "Example_Project.h"

SceneManager sceneManager;

//-----------------------------------------------------------------------------
// Name: main()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
void __cdecl main()
{
    // Initialize Direct3D
    if( FAILED( InitD3D() ) )
        return;

	if( FAILED( InitInput() ) )
		return;

    // Initialize Time
	if( FAILED( InitTime() ) )
        return;

	sceneManager.addScene(new StartMenuScene()); //scene 0
	sceneManager.addScene(new GameScene()); //scene 1

	//sceneManager.activeScene = new GameScene();
	sceneManager.switchScene(0);

    while( TRUE )
    {
        // What time is it?
        UpdateTime();
        // Update the world
        sceneManager.activeScene->Update();   
        // Render the scene
        sceneManager.activeScene->Render();
    }
}