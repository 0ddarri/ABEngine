#pragma once
#include"GameObject.h"

class Scene
{
private:
protected:
	list<GameObject*> _Objectlist; // 오브젝트 목록
public:
	Scene() {};

	wstring name;

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Exit() PURE;
};

