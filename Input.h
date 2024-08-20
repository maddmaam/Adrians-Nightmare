#pragma once

#include "Global.h"

HRESULT InitInput();

struct inputVectors {
	float lX;
	float lY;
	float rX;
	float rY;
};

bool StartButtonPressed();
bool buttonPressed(int button);

inputVectors getControllerAxis();

void RotateWorldFromController();

extern XINPUT_GAMEPAD insertedGamePad;

// Comment cause borked