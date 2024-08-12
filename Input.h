#pragma once

#include "Global.h"

HRESULT InitInput();

bool StartButtonPressed();

void RotateWorldFromController();

extern XINPUT_GAMEPAD insertedGamePad;

// Comment cause borked