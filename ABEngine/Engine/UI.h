#pragma once
#include "Component.h"

class UI : public Component
{
private:
public:
	UI() {};

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	int layer;
};

