#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "..\Global.h"
#include "..\Scene.h"
#include "..\Rendering\Render.h"
#include "..\SystemIO.h"
#include "..\Time.h"
#include "..\Sound.h"

class GameScene : public Scene {
public:
	HRESULT Init();
	void Render();
	void Update();
	void Cleanup();
private:
	MESH_DATA AdrianMesh;
	MESH_DATA CfCardMesh;
	CSound Ambience;
	CSound AdrianCry[5];
	CSound HeyTeam;
	LPDIRECT3DTEXTURE8 GroundTexture;
};

#endif