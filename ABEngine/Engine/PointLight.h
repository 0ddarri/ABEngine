#pragma once
#include "Light.h"

class PointLight : public Light
{
private:
public:
	PointLight();

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();
};

