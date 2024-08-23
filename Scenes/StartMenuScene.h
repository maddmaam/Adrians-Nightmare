#ifndef STARTMENUSCENE_H
#define STARTMENUSCENE_H

#include "..\Global.h"
#include "..\Scene.h"
#include "..\Time.h"
#include "..\Input.h"
#include "..\Rendering\Render.h"
#include "..\SystemIO.h"
#include "..\Sound.h"

class StartMenuScene : public Scene {
public:
	HRESULT Init();
	void Render();
	void Update();
	void Cleanup();

private:
	CSound GameMusic;
	LPDIRECT3DTEXTURE8 MainTexture;
	LPDIRECT3DTEXTURE8 MainTextureNoText;
};

#endif