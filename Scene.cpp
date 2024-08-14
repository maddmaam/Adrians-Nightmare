#include "Scene.h"
#include "Global.h"

void SceneManager::addScene(Scene* scene)
{
	scenes.push_back(scene);
}
void SceneManager::switchScene(int sceneID) {
	activeScene = scenes[sceneID];

	if( FAILED(activeScene->Init() ) )
        return;

}
