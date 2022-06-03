#include "DXUT.h"
#include "Scene.h"

void Scene::Init() // �� ����
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

void Scene::Update(float deltaTime) // �����Ӹ���
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

void Scene::Render() // ������
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

void Scene::Exit() // �� Ż��
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

	wcout << "ERROR! : ������Ʈ�� ������ ã�� ���߽��ϴ� : " << obj->name.c_str() << endl;
	return nullptr;
}
