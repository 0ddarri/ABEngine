#pragma once
#include "Light.h"

class PointLight : public Light
{
private:
public:
	PointLight();
	PointLight(float range, float falloff);
	PointLight(float range, float falloff, wstring n);

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	float range;
	float fallOffRange;
};

