#include "Input.h"
#include "Time.h"

#include <stdio.h>

XINPUT_GAMEPAD insertedGamePads[4];

//-----------------------------------------------------------------------------
// Name: InitInput()
// Desc: Initialises Input and Devices
//-----------------------------------------------------------------------------
HRESULT InitInput()
{
	XInitDevices(0, 0);
	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: GetGamePads()
// Desc: Reads Data from the Gamepads
//-----------------------------------------------------------------------------
void GetGamePads()
{
	DWORD controllerInsertions, controllerRemovals;
	XGetDeviceChanges(XDEVICE_TYPE_GAMEPAD, &controllerInsertions, &controllerRemovals);

	static HANDLE pluggedGamePads[4];

	// Loop over every gamepad
	for(int i = 0; i < (sizeof(insertedGamePads) / sizeof(XINPUT_GAMEPAD)); i++){
		if (controllerInsertions & (1 << i))
		{
			pluggedGamePads[i] = XInputOpen(XDEVICE_TYPE_GAMEPAD, i, XDEVICE_NO_SLOT, NULL); 
		}
	

		if (pluggedGamePads[i])
		{
			XINPUT_STATE currentInputStates;
			XInputGetState(pluggedGamePads[i], &currentInputStates);

			// Copy the input states to InsertedGamePad
			memcpy(&insertedGamePads[i], &currentInputStates.Gamepad, sizeof(XINPUT_GAMEPAD));
		}
	}
}

//-----------------------------------------------------------------------------
// Name: StartButtonPressed()
// Desc: Checks whether the start button has been pressed
//-----------------------------------------------------------------------------
bool StartButtonPressed()
{
	GetGamePads();

	if (insertedGamePads[CONTROLLER1].wButtons & XINPUT_GAMEPAD_START) 
	{
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
// Name: buttonPressed()
// Desc: Checks whether a button on the controller has been pressed
//-----------------------------------------------------------------------------
bool buttonPressed(int button)
{
	GetGamePads();

	if (insertedGamePads[CONTROLLER1].bAnalogButtons[button]) 
	{
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
// Name: getControllerAxis()
// Desc: Returns the controllers joystick axis
//-----------------------------------------------------------------------------
inputVectors getControllerAxis()
{
	GetGamePads();

	float deadZone = 0.03f;
	inputVectors out;

	out.rX = insertedGamePads[CONTROLLER1].sThumbRX *fSecsPerTick*D3DX_PI*500.f;
	out.rY = insertedGamePads[CONTROLLER1].sThumbRY *fSecsPerTick*D3DX_PI*500.f;

	if(out.rX < deadZone && out.rX > -deadZone)
		out.rX = 0;

	if(out.rY < deadZone && out.rY > -deadZone )
		out.rY = 0;


	out.lX = insertedGamePads[CONTROLLER1].sThumbLX *fSecsPerTick*D3DX_PI*500.f;
	out.lY = insertedGamePads[CONTROLLER1].sThumbLY *fSecsPerTick*D3DX_PI*500.f;

	if(out.lX < deadZone && out.lX > -deadZone)
		out.lX = 0;

	if(out.lY < deadZone && out.lY > -deadZone)
		out.lY = 0;

	return out;
}