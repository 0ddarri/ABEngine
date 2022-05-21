#include "DXUT.h"
#include "PointLight.h"
#include "LightManager.h"

PointLight::PointLight()
{
	range = 2;
	fallOffRange = 5;
	name = L"Point Light";
	LightManager::Instance()->AddPointLight(this);
}

PointLight::PointLight(float range, float falloff)
{
	this->range = range;
	fallOffRange = falloff;
	name = L"Point Light";
	LightManager::Instance()->AddPointLight(this);
}

PointLight::PointLight(float range, float falloff, wstring n)
{
	this->range = range;
	fallOffRange = falloff;
	name = n;
	LightManager::Instance()->AddPointLight(this);
}

void PointLight::Init(GameObject* p)
{
	Light::Init(p);
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
