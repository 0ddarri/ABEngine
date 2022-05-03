#include "DXUT.h"
#include "SceneManager.h"

void SceneManager::ChangeScene(wstring name) // ¾À º¯°æ
{
	wcout << "ChangeScene: " << name.c_str() << endl;
	if (curScene != nullptr)
		curScene->Exit();
	curScene = FindScene(name);
	curScene->Init();
}

Scene* SceneManager::FindScene(wstring name) // ¾À Ã£±â
{
	for (Scene* scene : _SceneList)
	{
		if (scene->name == name) return scene;
	}
	cout << "ERROR! : Can't Find Scene" << endl;
	return nullptr;
}

Scene* SceneManager::GetCurrentScene() // ÇöÀç ¾À ¹Þ¾Æ¿À±â
{
	return curScene;
}

void SceneManager::Initialize() // ¸ðµç ¾À Ãß°¡
{
	Scene* testScene = new TestScene(L"Test");
	_SceneList.push_back(testScene);
	cout << "Scene Initialize" << endl;
}
