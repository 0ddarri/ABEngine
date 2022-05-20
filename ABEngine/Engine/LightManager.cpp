#include "DXUT.h"
#include "LightManager.h"

void LightManager::Initialize()
{
	PointLight* light1 = new PointLight();
	pointLightList.push_back(light1);

	cout << "Light Initialize" << '\n';
}
