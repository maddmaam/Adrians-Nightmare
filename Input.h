#pragma once

#include "Global.h"

#define CONTROLLER1 0
#define CONTROLLER2 1
#define CONTROLLER3 2
#define CONTROLLER4 3

HRESULT InitInput();

// Temporary struct for controller axis
struct inputVectors {
	float lX;
	float lY;
	float rX;
	float rY;
};

bool StartButtonPressed();

bool buttonPressed(int button);

inputVectors getControllerAxis();


// Comment cause borked