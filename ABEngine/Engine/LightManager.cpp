#include "DXUT.h"
#include "LightManager.h"

void LightManager::Initialize()
{
}

void LightManager::AddPointLight(PointLight* light)
{
	for (int i = 0; i < pointLightList.size(); i++)
	{
		if (pointLightList[i]->name == light->name)
		{
			cout << "Point Light Error : 이미 있는 이름입니다" << endl;
			return;
		}
	}
	wcout << "Add Light : " << light->name.c_str() << '\n';
	pointLightList.push_back(light);
}

PointLight* LightManager::GetPointLight(wstring name)
{
	for (int i = 0; i < pointLightList.size(); i++)
	{
		if (pointLightList[i]->name == name)
			return pointLightList[i];
	}
	cout << "Can't Find Point Light : " << name.c_str() << endl;
	return nullptr;
}
