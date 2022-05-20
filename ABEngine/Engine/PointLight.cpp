#include "DXUT.h"
#include "PointLight.h"

PointLight::PointLight()
{
	range = 5;
	fallOffRange = 20;
}

PointLight::PointLight(float range, float falloff)
{
	this->range = range;
	fallOffRange = falloff;
}

void PointLight::Init(GameObject* p)
{
}

void PointLight::Update(float deltaTime)
{
}

void PointLight::Render()
{
}

void PointLight::Exit()
{
}
