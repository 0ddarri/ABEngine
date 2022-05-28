#include "DXUT.h"
#include "ObjectPool.h"


void ObjectPool::Initialize()
{
	CreateObjects();
}

void ObjectPool::CreateObjects()
{
	for (int i = 0; i < 10; i++)
	{
		GameObject* obj = new GameObject();
		obj->AddComp(new MeshRenderer(L"Resources/Mesh/Wall_Original.x", L"Original Wall"));
		SceneManager::Instance()->GetCurrentScene()->AddObj(obj);
		ObjectPool_Wall.push_back(obj);
	}

	PoolList.push_back({ L"OriginalWall", ObjectPool_Wall });
	cout << "object Pool Initialize" << endl;

	DisableObjects();
}

void ObjectPool::DisableObjects()
{
	for (GameObject* obj : ObjectPool_Wall)
	{
		obj->SetActive(false);
	}
}

GameObject* ObjectPool::SpawnObject(wstring poolName, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	for (int i = 0; i < PoolList.size(); i++)
	{
		if (PoolList[i].first == poolName)
		{
			for (GameObject* obj : PoolList[i].second)
			{
				if (!obj->Active)
				{
					obj->SetActive(true);
					obj->transform->position = pos;
					obj->transform->rotation = rot;
					cout << "Spawn Object" << endl;
					return obj;
				}
			}
		}
	}
	cout << "오브젝트 못찾음" << endl;
	return nullptr;
}

void ObjectPool::Exit()
{
	for (GameObject* it : ObjectPool_Wall)
	{
		it->Exit();
	}
	ObjectPool_Wall.clear();
}
