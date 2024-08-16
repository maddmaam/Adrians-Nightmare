#pragma once

#include "Global.h"

HRESULT InitInput();

struct inputVector {
	float x;
	float y;
};

bool StartButtonPressed();

inputVector getControllerAxis();

void RotateWorldFromController();

extern XINPUT_GAMEPAD insertedGamePad;

// Comment cause borked