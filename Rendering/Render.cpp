#include "Render.h"

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
LPDIRECT3D8             g_pD3D       = NULL; // Used to create the D3DDevice
LPDIRECT3DDEVICE8       g_pd3dDevice = NULL; // Our rendering device
LPDIRECT3DVERTEXBUFFER8 g_pVB        = NULL;
D3DXMATRIX				matWorldX;// Buffer to hold vertices
D3DXMATRIX				matWorldY;
D3DXMATRIX				matWorldZ;


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
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD;

    // Create the Direct3D device.
    if( FAILED( g_pD3D->CreateDevice( 0, D3DDEVTYPE_HAL, NULL,
                                      D3DCREATE_HARDWARE_VERTEXPROCESSING,
                                      &d3dpp, &g_pd3dDevice ) ) )
        return E_FAIL;

    // Turn on the zbuffer
    g_pd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );

    // Turn on ambient lighting 
    g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );

    return S_OK;
}


//-----------------------------------------------------------------------------
// Name: SetupMatrices()
// Desc: Sets up the world, view, and projection transform matrices.
//-----------------------------------------------------------------------------
VOID SetupMatrices()
{
    // For our world matrix, we will just leave it as the identity
	D3DXMatrixRotationZ( &matWorldY, 0);
	g_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorldY);

    // Set up our view matrix. A view matrix can be defined given an eye point,
    // a point to lookat, and a direction for which way is up. Here, we set the
    // eye five units back along the z-axis and up three units, look at the 
    // origin, and define "up" to be in the y-direction.
    const D3DXVECTOR3 vEyePos( 0.0f, 3.0f,-5.0f );
    const D3DXVECTOR3 vLookAt( 0.0f, 0.0f, 0.0f );
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
    D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/4, 1.0f, 1.0f, 100.0f );
    g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );
}

void RenderTexture(CUSTOMVERTEX vertices[], LPDIRECT3DTEXTURE8 pTexture)
{
	LPDIRECT3DVERTEXBUFFER8 g_pVertexBuffer;
	VOID* pVertices;

	//Create the vertex buffer from our device
	g_pd3dDevice->CreateVertexBuffer(3 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_pVertexBuffer);

	//Get a pointer to the vertex buffer vertices and lock the vertex buffer
	g_pVertexBuffer->Lock(0, sizeof(vertices), (BYTE**)&pVertices, 0);

	//Copy our stored vertices values into the vertex buffer
    memcpy(pVertices, vertices, sizeof(vertices));

	//Unlock the vertex buffer
    g_pVertexBuffer->Unlock();

	//Unlock the vertex buffer
    g_pVertexBuffer->Unlock();

	//Rendering our triangle
    g_pd3dDevice->SetStreamSource(0, g_pVertexBuffer, sizeof(CUSTOMVERTEX));
    g_pd3dDevice->SetVertexShader(D3DFVF_CUSTOMVERTEX);

    //Set our background to use our texture buffer
    g_pd3dDevice->SetTexture(0, pTexture);
    g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}