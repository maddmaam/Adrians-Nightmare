#include "Render.h"
#include <xfont.h>
#include <stdio.h>

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
LPDIRECT3D8             g_pD3D       = NULL; // Used to create the D3DDevice
LPDIRECT3DDEVICE8       g_pd3dDevice = NULL; // Our rendering device
LPDIRECT3DVERTEXBUFFER8 g_pVertexBuffer = NULL; // vertex buffer for texture rendering
D3DXMATRIX				worldMatrix;
D3DXMATRIX				worldTranslationMatrix;

//-----------------------------------------------------------------------------
// Name: InitD3D()
// Desc: Initializes Direct3D
//-----------------------------------------------------------------------------
HRESULT InitD3D()
{
    // Create the D3D object.
    if( NULL == ( g_pD3D = Direct3DCreate8( D3D_SDK_VERSION ) ) )
        return E_FAIL;

    // Set up the structure used to create the D3DDevice.
    D3DPRESENT_PARAMETERS d3dpp; 
    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.BackBufferWidth        = 640;
    d3dpp.BackBufferHeight       = 480;
    d3dpp.BackBufferFormat       = D3DFMT_X8R8G8B8;
    d3dpp.BackBufferCount        = 1;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
    d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD;

    // Create the Direct3D device.
    if( FAILED( g_pD3D->CreateDevice( 0, D3DDEVTYPE_HAL, NULL, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice ) ) )
        return E_FAIL;

    // Turn on the zbuffer
    g_pd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );

	// Turn off lighting by default
	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	// Set up Texture settings
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
    g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);

    return S_OK;
}

//-----------------------------------------------------------------------------
// Name: EnableLighting()
// Desc: Initializes Lighting for a scene
//-----------------------------------------------------------------------------
VOID EnableLighting() 
{
	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	g_pd3dDevice->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(255,255,255));
}

//-----------------------------------------------------------------------------
// Name: EnableFog()
// Desc: Initializes Fog for a scene
//-----------------------------------------------------------------------------
VOID EnableFog() 
{
	DWORD Color = D3DCOLOR_XRGB(0,0,0);
	DWORD Mode = D3DFOG_LINEAR;
	float Start   = 20.0f;    // For linear mode
    float End     = 40.0f;
    float Density = 0.66f;   // For exponential modes
 
    // Enable fog blending.
    g_pd3dDevice->SetRenderState(D3DRS_FOGENABLE, TRUE);
 
    // Set the fog color.
    g_pd3dDevice->SetRenderState(D3DRS_FOGCOLOR, Color);
    
    // Set fog parameters.
    if( Mode == D3DFOG_LINEAR )
    {
        g_pd3dDevice->SetRenderState(D3DRS_FOGTABLEMODE, Mode);
        g_pd3dDevice->SetRenderState(D3DRS_FOGSTART, *(DWORD *)(&Start));
        g_pd3dDevice->SetRenderState(D3DRS_FOGEND,   *(DWORD *)(&End));
    }
    else
    {
        g_pd3dDevice->SetRenderState(D3DRS_FOGTABLEMODE, Mode);
        g_pd3dDevice->SetRenderState(D3DRS_FOGDENSITY, *(DWORD *)(&Density));
    }
}

//-----------------------------------------------------------------------------
// Name: SetupMatrices()
// Desc: Sets up the world, view, and projection transform matrices.
//-----------------------------------------------------------------------------
VOID SetupMatrices()
{
    // Set up our view matrix. A view matrix can be defined given an eye point,
    // a point to lookat, and a direction for which way is up. Here, we set the
    // eye five units back along the z-axis and up three units, look at the 
    // origin, and define "up" to be in the y-direction.
    const D3DXVECTOR3 vEyePos( 0.0f, 2.0f, -12.0f );
    const D3DXVECTOR3 vLookAt( 0.0f, 2.0f, 0.0f );
    const D3DXVECTOR3 vUp    ( 0.0f, 1.0f, 0.0f );
    D3DXMATRIX matView;
    D3DXMatrixLookAtLH( &matView, &vEyePos, &vLookAt, &vUp );
    g_pd3dDevice->SetTransform( D3DTS_VIEW, &matView );

    // For the projection matrix, we set up a perspective transform (which
    // transforms geometry from 3D view space to 2D viewport space, with
    // a perspective divide making objects smaller in the distance). To build
    // a perspective transform, we need the field of view (1/4 pi is common),
    // the aspect ratio, and the near and far clipping planes (which define at
    // what distances geometry should be no longer be rendered).
    D3DXMATRIX matProj;
    D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/4, ((float)600 / (float)400), 1.0f, 100.0f );
    g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );
}

//-----------------------------------------------------------------------------
// Name: RenderVertices()
// Desc: Renders a set of vertices
//-----------------------------------------------------------------------------
void RenderVertices(CUSTOMVERTEX* cvVertices,  LPDIRECT3DTEXTURE8 pTexture)
{
	VOID* pVertices;

	//Create the vertex buffer from our device
	g_pd3dDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_pVertexBuffer);

	//Get a pointer to the vertex buffer vertices and lock the vertex buffer
	g_pVertexBuffer->Lock(0, 6 * sizeof(CUSTOMVERTEX), (BYTE**)&pVertices, 0);

	//Copy our stored vertices values into the vertex buffer
    memcpy(pVertices, cvVertices, 6 * sizeof(CUSTOMVERTEX));

	//Unlock the vertex buffer
    g_pVertexBuffer->Unlock();

	//Rendering our triangle
	g_pd3dDevice->SetStreamSource(0, g_pVertexBuffer, sizeof(CUSTOMVERTEX));
    g_pd3dDevice->SetVertexShader(D3DFVF_CUSTOMVERTEX);

    //Set our background to use our texture buffer
    g_pd3dDevice->SetTexture(0, pTexture);
    g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

	g_pVertexBuffer->Release();
}

//-----------------------------------------------------------------------------
// Name: DisplayText()
// Desc: Displays Text used for debugging
//-----------------------------------------------------------------------------
void DisplayText(char * szStr, long xpos, long ypos, D3DCOLOR color )
{
    // Create DirectX text buffers
    XFONT* pFont; 
    LPDIRECT3DSURFACE8 pBackBuffer;

	// Initialise fonts
	g_pd3dDevice->GetBackBuffer( 0,D3DBACKBUFFER_TYPE_MONO,&pBackBuffer);
    XFONT_OpenDefaultFont( &pFont );

	// Pushes string to a buffer
    WCHAR szbuff[200] = {0};
    swprintf(szbuff, L"%S", szStr);

	// Sets the texts color
    pFont->SetTextColor(color);

    //Display our text.
    pFont->TextOut( pBackBuffer, szbuff, -1, (long)xpos, (long)ypos );

    //Release our TextBuffers
    pFont->Release();
    pBackBuffer->Release();
}