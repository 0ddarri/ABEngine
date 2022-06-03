#include "DXUT.h"
#include "ObjectManager.h"

GameObject* ObjectManager::Instantiate(OBJECT_TYPE type, D3DXVECTOR3 pos)
{
	GameObject* obj = new GameObject();
	switch (type)
	{
	case WALL_ORIGINAL:
	{
		obj->AddComp(new MeshRenderer(L"Resources/Mesh/Wall_Original.x", L"Original Wall"));
	}
		break;
	case WALL_HOLE:
	{
		obj->AddComp(new MeshRenderer(L"Resources/Mesh/Wall_Broken1.x", L"Broken Wall 1"));
	}
		break;
	case LAMP:
	{
		obj->AddComp(new MeshRenderer(L"Resources/Mesh/Lamp.x", L"Lamp"));
	}
		break;
	default:
		break;
	}
	obj->transform->position = pos;
	SceneManager::Instance()->GetCurrentScene()->AddObj(obj);

	return obj;
}

void ObjectManager::Destroy(GameObject* obj)
{
	if (obj == NULL)
	{
		cout << "¹¹Áö ÀÌ ÂòÂòÇÔÀº? " << endl;
		return;
	}
	obj->Exit();
	SceneManager::Instance()->GetCurrentScene()->_Objectlist.remove(SceneManager::Instance()->GetCurrentScene()->FindObj(obj));
	SceneManager::Instance()->GetCurrentScene()->_UIlist.remove(SceneManager::Instance()->GetCurrentScene()->FindObj(obj));
	obj = NULL;
}