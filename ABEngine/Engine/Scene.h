#pragma once
#include"GameObject.h"
#include"UI.h"

class Scene
{
private:
protected:

public:
	list<GameObject*> _Objectlist; // 오브젝트 목록
	list<GameObject*> _UIlist; // 오브젝트 목록

	Scene() {};

	static bool Comp(GameObject* a, GameObject* b)
	{
		return a->GetComponent<UI>().layer < b->GetComponent<UI>().layer;
	}

	wstring name;

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit() PURE;

	void AddObj(GameObject* obj);
	void AddUI(GameObject* ui);

	GameObject* FindObj(GameObject* obj);
};

