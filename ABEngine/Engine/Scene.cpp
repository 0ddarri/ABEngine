#include "DXUT.h"
#include "Scene.h"

void Scene::Init() // 씬 진입
{
	for (GameObject* it : _Objectlist)
	{
		it->Init();
	}

	for (GameObject* it : _UIlist)
	{
		it->Init();
	}
}

void Scene::Update(float deltaTime) // 프레임마다
{
	for (GameObject* it : _Objectlist)
	{
		it->Update(deltaTime);
	}

	for (GameObject* it : _UIlist)
	{
		it->Update(deltaTime);
	}
}

void Scene::Render() // 렌더링
{
	for (GameObject* it : _Objectlist)
	{
		it->Render();
	}

	for (GameObject* it : _UIlist)
	{
		it->Render();
	}
}

void Scene::Exit() // 씬 탈출
{
	for (GameObject* it : _Objectlist)
	{
		it->Exit();
	}

	for (GameObject* it : _UIlist)
	{
		it->Exit();
	}
}

void Scene::AddObj(GameObject* obj)
{
	_Objectlist.push_back(obj);
}

void Scene::AddUI(GameObject* ui)
{
	_UIlist.push_back(ui);
	_UIlist.sort(Comp);
}

GameObject* Scene::FindObj(GameObject* obj)
{
	auto f = find(_Objectlist.begin(), _Objectlist.end(), obj);
	if (f != _Objectlist.end())
	{
		cout << "Find Object In Scene" << endl;
		return *f;
	}

	auto d = find(_UIlist.begin(), _UIlist.end(), obj);
	if (d != _UIlist.end())
	{
		cout << "Find UIObject In Scene" << endl;
		return *d;
	}

	wcout << "ERROR! : 오브젝트를 씬에서 찾지 못했습니다 : " << obj->name.c_str() << endl;
	return nullptr;
}
