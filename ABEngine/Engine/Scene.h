#pragma once
#include"GameObject.h"

class Scene
{
private:
protected:
	list<GameObject*> _Objectlist; // ������Ʈ ���
public:
	Scene() {};

	wstring name;

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit() PURE;

	void AddObj(GameObject* obj);


};

