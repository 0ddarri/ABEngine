#pragma once
#include "Light.h"

class PointLight : public Light
{
private:
public:
	PointLight();
	PointLight(float range, float falloff);

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	float range;
	float fallOffRange;
};

