// Time.cpp : Defines time related things //TODO
#include "Time.h"

float			SecsPerTick;
LARGE_INTEGER	qwTime, qwLastTime, qwElapsedTime, qwAppTime, qwElapsedAppTime;
float			fTime, fElapsedTime, fAppTime, fElapsedAppTime, fSecsPerTick;

HRESULT InitTime()
{
    // Get the frequency of the timer
	LARGE_INTEGER qwTicksPerSec;
    QueryPerformanceFrequency( &qwTicksPerSec );
    fSecsPerTick = 1.0f / (FLOAT)qwTicksPerSec.QuadPart;

    // Save the start time
    QueryPerformanceCounter( &qwTime );
    qwLastTime.QuadPart = qwTime.QuadPart;

    qwAppTime.QuadPart        = 0;
    qwElapsedTime.QuadPart    = 0;
    qwElapsedAppTime.QuadPart = 0;

	return S_OK;
}

void UpdateTime()
{
    
    QueryPerformanceCounter( &qwTime );
    qwElapsedTime.QuadPart = qwTime.QuadPart - qwLastTime.QuadPart;
    qwLastTime.QuadPart    = qwTime.QuadPart;
    qwElapsedAppTime.QuadPart = qwElapsedTime.QuadPart;
    qwAppTime.QuadPart    += qwElapsedAppTime.QuadPart;

    // Store the current time values as floating point
    fTime           = fSecsPerTick * ((FLOAT)(qwTime.QuadPart));
    fElapsedTime    = fSecsPerTick * ((FLOAT)(qwElapsedTime.QuadPart));
    fAppTime        = fSecsPerTick * ((FLOAT)(qwAppTime.QuadPart));
    fElapsedAppTime = fSecsPerTick * ((FLOAT)(qwElapsedAppTime.QuadPart));
}
