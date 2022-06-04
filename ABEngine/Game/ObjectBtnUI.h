#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Button.h"
#include "../Engine/Text.h"

class ObjectBtnUI : public GameObject
{
private:
public:
	ObjectBtnUI();
	ObjectBtnUI(int type, wstring objName);

	OBJECT_TYPE type;
	wstring objName;
	wstring materialName;

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();


	void SetName(wstring n);
};

