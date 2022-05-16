#include "DXUT.h"
#include "MaterialManager.h"

void MaterialManager::Initialize()
{
	Material* texturemapping = new TextureMapping();
	AddMaterial(texturemapping);
	Material* colorMat = new ColorMat();
	AddMaterial(colorMat);
	Material* specularmapping = new SpecularMapping();
	AddMaterial(specularmapping);
}

void MaterialManager::AddMaterial(Material* m)
{
	for (Material* mat : materialList)
	{
		if (mat->name == m->name)
		{
			cout << "이미 있는 머터리얼" << endl;
			return;
		}
	}
	materialList.push_back(m);
	wcout << "머터리얼 추가됨 : " << m->name.c_str() << endl;
}

Material* MaterialManager::GetMaterial(wstring name)
{
	for (Material* mat : materialList)
	{
		if (mat->name == name)
		{
			cout << "머터리얼 찾음" << endl;
			return mat;
		}
	}

	cout << "머터리얼 찾지 못함" << endl;
 	return nullptr;
}

void MaterialManager::Exit()
{
	for (Material* mat : materialList)
	{
		mat->shader->Release();
	}
	materialList.clear();
}
