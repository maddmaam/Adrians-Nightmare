// Example_Project.cpp : Defines the entry point for the application.
#include "Example_Project.h"
// #include "Input.h" BORKED ATM, NEED FIX

#define CONTROL_STARTBUTTON     4

//-----------------------------------------------------------------------------
// Name: Update()
// Desc: Updates the world for the next frame
//-----------------------------------------------------------------------------
void Update()
{

    D3DXMATRIX matRotate;
    D3DXMATRIX matWorld;
    g_pd3dDevice->GetTransform( D3DTS_WORLD, &matWorld );
    FLOAT fZRotate = -fElapsedTime*D3DX_PI*0.5f;
    D3DXMatrixRotationYawPitchRoll( &matRotate, 0.0f, 0.0f, fZRotate );
    D3DXMatrixMultiply( &matWorld, &matWorld, &matRotate );
    g_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld );
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

    // Initialize the vertex buffer
    InitVB();

    InitTime();

    while( TRUE )
    {
        // What time is it?
        UpdateTime();
        // Update the world
        Update();   
        // Render the scene
        Render();

        // Present the backbuffer contents to the display
        g_pd3dDevice->Present( NULL, NULL, NULL, NULL );

    }
}


