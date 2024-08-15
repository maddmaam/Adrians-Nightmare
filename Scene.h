#ifndef SCENE_H
#define SCENE_H

#include "Global.h"
#include <vector>

using namespace std;

class Scene
{
public:
	virtual HRESULT Init() = S_OK;
	virtual void Render() = 0;
	virtual void Update() = 0;
};

class SceneManager
{
private:
	vector<Scene*> scenes;
public:
	Scene* activeScene;
	void addScene(Scene* scene);
	void switchScene(int sceneID);
};

extern SceneManager sceneManager;

#endif