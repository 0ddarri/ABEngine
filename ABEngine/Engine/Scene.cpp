#include "DXUT.h"
#include "Scene.h"

void Scene::Init() // �� ����
{
	for (GameObject* it : _Objectlist)
	{
		it->Init();
	}
}

void Scene::Update(float deltaTime) // �����Ӹ���
{
	for (GameObject* it : _Objectlist)
	{
		it->Update(deltaTime);
	}
}

void Scene::Render() // ������
{
	for (GameObject* it : _Objectlist)
	{
		it->Render();
	}
}

void Scene::Exit() // �� Ż��
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
