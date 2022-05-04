#include "DXUT.h"
#include "Scene.h"

void Scene::Init() // ¾À ÁøÀÔ
{
	for (GameObject* it : _Objectlist)
	{
		it->Init();
	}
}

void Scene::Update(float deltaTime) // ÇÁ·¹ÀÓ¸¶´Ù
{
	for (GameObject* it : _Objectlist)
	{
		it->Update(deltaTime);
	}
}

void Scene::Render() // ·»´õ¸µ
{
	for (GameObject* it : _Objectlist)
	{
		it->Render();
	}
}

void Scene::Exit() // ¾À Å»Ãâ
{
	for (GameObject* it : _Objectlist)
	{
		it->Exit();
	}
}

void Scene::AddObj(GameObject* obj)
{
	_Objectlist.push_back(obj);
}
