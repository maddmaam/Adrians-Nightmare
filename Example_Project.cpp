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

	if( FAILED( InitInput() ) )
		return;

    // Initialize Time
	if( FAILED( InitTime() ) )
        return;

	GameScene MenuScene;

	if( FAILED( MenuScene.Init() ) )
        return;

    while( TRUE )
    {
        // What time is it?
        UpdateTime();
        // Update the world
        MenuScene.Update();   
        // Render the scene
        MenuScene.Render();
    }
}