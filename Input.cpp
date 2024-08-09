#include "Input.h"

#define CONTROLLER1 1
#define CONTROLLER2 1 << 1
#define CONTROLLER3 1 << 2
#define CONTROLLER4 1 << 3

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
	XINPUT_GAMEPAD insertedGamePad;

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

		memcpy(&insertedGamePad, &currentInputStates, sizeof(XINPUT_GAMEPAD));
	}

	if (insertedGamePad.wButtons & XINPUT_GAMEPAD_START) 
	{
		return true;
	}
	return false;
}