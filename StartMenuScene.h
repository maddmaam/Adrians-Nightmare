#ifndef STARTMENUSCENE_H
#define STARTMENUSCENE_H

#include "Global.h"
#include "Scene.h"
#include "Rendering\Render.h"
#include "SystemIO.h"

class StartMenuScene : public Scene {
public:
	HRESULT Init();
	void Render();
	void Update();
};

#endif