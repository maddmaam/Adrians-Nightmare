#include "Input.h"


ControllerInputApp::ControllerInputApp() : CXBApplication()
{
	m_dwNumInsertedGamepads = 0L;
	m_pGamepad = &m_DefaultGamepad;
}

void InitInput()
{
	XInitDevices(0, 0);
}