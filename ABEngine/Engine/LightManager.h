#pragma once
#include "Singleton.h"
#include "PointLight.h"

class LightManager : public Singleton<LightManager>
{
private:
public:
	void Initialize();

	vector<PointLight*> pointLightList;
};

