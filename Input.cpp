#include "Input.h"
#include "Rendering\Render.h"
#include "Time.h"

#include <stdio.h>

#define CONTROLLER1 1
#define CONTROLLER2 1 << 1
#define CONTROLLER3 1 << 2
#define CONTROLLER4 1 << 3

XINPUT_GAMEPAD insertedGamePad;

void GetNumber1GamePad();

HRESULT InitInput()
{
	XInitDevices(0, 0);
	return S_OK;
}



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

bool buttonPressed(int button)
{
	GetNumber1GamePad();

	if (insertedGamePad.bAnalogButtons[button]) 
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
		memcpy(&insertedGamePad, &currentInputStates.Gamepad, sizeof(XINPUT_GAMEPAD));
	}
}

inputVectors getControllerAxis()
{
	GetNumber1GamePad();

	inputVectors out;

	out.rX = insertedGamePad.sThumbRX *fSecsPerTick*D3DX_PI*500.f;
	out.rY = insertedGamePad.sThumbRY *fSecsPerTick*D3DX_PI*500.f;

	out.lX = insertedGamePad.sThumbLX *fSecsPerTick*D3DX_PI*500.f;
	out.lY = insertedGamePad.sThumbLY *fSecsPerTick*D3DX_PI*500.f;

	return out;
}