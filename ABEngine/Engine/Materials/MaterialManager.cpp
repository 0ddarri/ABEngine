#include "DXUT.h"
#include "MaterialManager.h"

void MaterialManager::Initialize()
{
	Material* texturemapping = new TextureMapping();
	AddMaterial(texturemapping);

	Material* colorMat = new ColorMat();
	AddMaterial(colorMat);

	Material* groundMaterial = new SpecularMapping(L"Ground_Albedo", L"Ground_Specular", L"Ground_Normal");
	groundMaterial->name = L"Ground Mat";
	AddMaterial(groundMaterial);

	Material* originwallmat = new SpecularMapping(L"Wall_Original_Diffuse", L"Wall_Original_Specular", L"Wall_Original_Normal");
	originwallmat->name = L"Original Wall";
	AddMaterial(originwallmat);

	Material* brokenwall1mat = new SpecularMapping(L"Wall_Broken1_Diffuse", L"Wall_Broken1_Specular", L"Wall_Broken1_Normal");
	brokenwall1mat->name = L"Broken Wall 1";
	AddMaterial(brokenwall1mat);

	Material* lampMat = new SpecularMapping(L"Lamp_Diffuse", L"Lamp_Specular", L"Lamp_Normal");
	lampMat->name = L"Lamp";
	AddMaterial(lampMat);
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
