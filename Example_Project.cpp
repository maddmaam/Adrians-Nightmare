// Example_Project.cpp : Defines the entry point for the application.
#include "Example_Project.h"

//-----------------------------------------------------------------------------
// Name: Update()
// Desc: Updates the world for the next frame
//-----------------------------------------------------------------------------
void Update()
{

}

//-----------------------------------------------------------------------------
// Name: InitGeometry()
// Desc: Load the mesh and build the material and texture arrays
//-----------------------------------------------------------------------------
HRESULT InitGeometry()
{
    // Load the packed resource (containing the app's textures)
    if( FAILED( LoadPackedResource( "D:\\Media\\Resource.xpr" ) ) )
        return E_FAIL;

    // Load geometry from the XBG file
    if( FAILED( LoadXBGFile( "D:\\Media\\Tiger.xbg" ) ) )
        return E_FAIL;

    return S_OK;
}

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

	if( FAILED( InitGeometry() ) )
        return;

    while( TRUE )
    {
        // What time is it?
        UpdateTime();
        // Update the world
        Update();   
        // Render the scene
        Render();
    }
}