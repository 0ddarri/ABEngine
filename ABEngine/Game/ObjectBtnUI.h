#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Button.h"

class ObjectBtnUI : public GameObject
{
private:
public:
	ObjectBtnUI();
	ObjectBtnUI(int type);

	OBJECT_TYPE type;

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	void OnClick_Set();
};

