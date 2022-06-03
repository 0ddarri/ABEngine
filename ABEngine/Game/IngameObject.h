#pragma once
#include "../Engine/GameObject.h"
#include "../Engine/Button.h"
#include "../Engine/Text.h"

class IngameObject : public GameObject
{
private:
public:
	IngameObject();
	IngameObject(GameObject* obj);

	GameObject* selectedObject;
	GameObject* middleCircle;
	bool isSelected = false;

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();
};