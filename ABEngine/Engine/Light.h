#pragma once
#include "Component.h"

class Light : public Component
{
private:
public:
	Light();

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();
};

