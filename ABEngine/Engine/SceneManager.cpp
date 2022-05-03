#include "DXUT.h"
#include "SceneManager.h"

void SceneManager::ChangeScene(wstring name) // �� ����
{
	wcout << "ChangeScene: " << name.c_str() << endl;
	if (curScene != nullptr)
		curScene->Exit();
	curScene = FindScene(name);
	curScene->Init();
}

Scene* SceneManager::FindScene(wstring name) // �� ã��
{
	for (Scene* scene : _SceneList)
	{
		if (scene->name == name) return scene;
	}
	cout << "ERROR! : Can't Find Scene" << endl;
	return nullptr;
}

Scene* SceneManager::GetCurrentScene() // ���� �� �޾ƿ���
{
	return curScene;
}

void SceneManager::Initialize() // ��� �� �߰�
{
	Scene* testScene = new TestScene(L"Test");
	_SceneList.push_back(testScene);
	cout << "Scene Initialize" << endl;
}
