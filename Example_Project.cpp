// Example_Project.cpp : Defines the entry point for the application.
#include "Example_Project.h"

//-----------------------------------------------------------------------------
// Name: main()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
void __cdecl main()
{
    // Initialize Direct3D
    if( FAILED( InitD3D() ) )
        return;

	// Initialize Input
	if( FAILED( InitInput() ) )
		return;

    // Initialize Time
	if( FAILED( InitTime() ) )
        return;

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
        // Render the Scene
        sceneManager.activeScene->Render();
    }
}