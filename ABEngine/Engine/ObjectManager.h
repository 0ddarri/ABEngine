#pragma once
#include "Singleton.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "SceneManager.h"


class ObjectManager : public Singleton<ObjectManager>
{
private:
public:
	GameObject* Instantiate(OBJECT_TYPE type, D3DXVECTOR3 pos);

	void Destroy(GameObject* obj);
};

