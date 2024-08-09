// Time.h : include file for Time include files
#pragma once

#include "Global.h"

extern float SecsPerTick;
extern LARGE_INTEGER qwTime, qwLastTime, qwElapsedTime, qwAppTime, qwElapsedAppTime;
extern float fTime, fElapsedTime, fAppTime, fElapsedAppTime;

HRESULT InitTime();

void UpdateTime();