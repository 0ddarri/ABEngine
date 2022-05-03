#pragma once
#include "Singleton.h"
#include "Scene.h"
#include "../Game/TestScene.h"

class SceneManager final : public Singleton<SceneManager>
{
private:
	list<Scene*> _SceneList;
	Scene* curScene;
protected:
public:
	void Initialize();

	void ChangeScene(wstring name);
	Scene* FindScene(wstring name);
	Scene* GetCurrentScene();
};

