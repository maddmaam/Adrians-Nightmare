#pragma once



#define CONTROL_STARTBUTTON     4

class ControllerInputApp : public CXBApplication 
{
	    // Active gamepad
    DWORD              m_dwNumInsertedGamepads; // Need to add logic for each frame to detect input
    XBGAMEPAD*         m_pGamepad;

public:
	ControllerInputApp();
};

void InitInput();

// Comment cause borked