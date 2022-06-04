#pragma once
#include "Singleton.h"
#include "GameObject.h"
#include "UI.h"
#include "SceneManager.h"


class ObjectManager : public Singleton<ObjectManager>
{
private:
public:
	void Initialize();

	GameObject* Instantiate(OBJECT_TYPE type, D3DXVECTOR3 pos);

	void Destroy(GameObject* obj);

	map<OBJECT_TYPE, wstring> ObjPathlist;
};

