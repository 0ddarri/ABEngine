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
			cout << "�̹� �ִ� ���͸���" << endl;
			return;
		}
	}
	materialList.push_back(m);
	wcout << "���͸��� �߰��� : " << m->name.c_str() << endl;
}

Material* MaterialManager::GetMaterial(wstring name)
{
	for (Material* mat : materialList)
	{
		if (mat->name == name)
		{
			cout << "���͸��� ã��" << endl;
			return mat;
		}
	}

	cout << "���͸��� ã�� ����" << endl;
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
