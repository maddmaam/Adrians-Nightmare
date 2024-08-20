#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Global.h"
#include "Scene.h"
#include "Rendering\Render.h"
#include "SystemIO.h"
#include "Time.h"
#include "Sound.h"

class GameScene : public Scene {
public:
	HRESULT Init();
	void Render();
	void Update();
private:
	CSound adrianCry;
};

#endif