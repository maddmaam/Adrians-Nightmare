// Time.h : include file for Time include files
#pragma once

extern float SecsPerTick;
extern LARGE_INTEGER qwTime, qwLastTime, qwElapsedTime, qwAppTime, qwElapsedAppTime;
extern float fTime, fElapsedTime, fAppTime, fElapsedAppTime;

void InitTime();

void UpdateTime();