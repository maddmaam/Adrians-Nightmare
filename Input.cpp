#include "Input.h"
#include "Rendering\Render.h"

#define CONTROLLER1 1
#define CONTROLLER2 1 << 1
#define CONTROLLER3 1 << 2
#define CONTROLLER4 1 << 3



HRESULT InitInput()
{
	XInitDevices(0, 0);
	return S_OK;
}

XINPUT_GAMEPAD insertedGamePad;

void GetNumber1GamePad();

/**
* Checks whether a controller has been inserted and whether the start button has been pressed
*/
bool StartButtonPressed()
{
	GetNumber1GamePad();

	if (insertedGamePad.wButtons & XINPUT_GAMEPAD_START) 
	{
		return true;
	}
	return false;
}

void GetNumber1GamePad()
{
	DWORD controllerInsertions, controllerRemovals;
	XGetDeviceChanges(XDEVICE_TYPE_GAMEPAD, &controllerInsertions, &controllerRemovals);

	static HANDLE pluggedGamePad;

	if (controllerInsertions & CONTROLLER1)
	{
		pluggedGamePad = XInputOpen(XDEVICE_TYPE_GAMEPAD, 0, XDEVICE_NO_SLOT, NULL); 
	}

	if (pluggedGamePad)
	{
		XINPUT_STATE currentInputStates;
		XInputGetState(pluggedGamePad, &currentInputStates);

		// Copy the input states to InsertedGamePad
		memcpy(&insertedGamePad, &currentInputStates, sizeof(XINPUT_GAMEPAD));
	}
}


void RotateWorldFromController()
{
	FLOAT fXRotate = insertedGamePad.sThumbLX*(timeGetTime()/50.f)*D3DX_PI*0.5f;
	FLOAT fYRotate = insertedGamePad.sThumbLY*(timeGetTime()/50.f)*D3DX_PI*0.5f;

	// This may just work now im not fully sure!
	D3DXMatrixRotationYawPitchRoll(&matWorldY, -fXRotate, -fYRotate, 0.0f);
	g_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorldY); 

	/**
	*	D3DXMatrixMultiply( &g_matWorld, &g_matWorld, &matRotate );
    *   m_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matWorld );
	*/
}