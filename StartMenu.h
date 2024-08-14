#ifndef STARTMENU_H
#define STARTMENU_H

#include "Global.h"
#include "Scene.h"
#include "Rendering\Render.h"
#include "SystemIO.h"

class StartMenu : public Scene {
public:
	HRESULT Init();
	void Render();
	void Update();
};

#endif