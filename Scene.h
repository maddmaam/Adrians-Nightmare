#ifndef SCENE_H
#define SCENE_H

#include "Global.h"

class Scene
{
public:
	virtual HRESULT Init() = S_OK;
	virtual void Render() = 0;
	virtual void Update() = 0;
};

#endif