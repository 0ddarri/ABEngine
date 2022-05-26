#pragma once
#include "../Engine/Singleton.h"
#include "../Engine/GameObject.h"
#include "../Engine/MeshRenderer.h"
#include "../Engine/SceneManager.h"

class ObjectPool : public Singleton<ObjectPool>
{
private:
public:
	void Initialize();
	
	list<GameObject*> ObjectPool_Wall;

	vector<pair<wstring, list<GameObject*>>> PoolList;

	void CreateObjects();
	void DisableObjects();

	GameObject* SpawnObject(wstring poolName, D3DXVECTOR3 pos = { 0,0,0 }, D3DXVECTOR3 rot = { 0,0,0 });

	void Exit();
};

