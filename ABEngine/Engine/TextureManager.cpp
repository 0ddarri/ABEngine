#include "DXUT.h"
#include "TextureManager.h"

void TextureManager::Initialize()
{
	D3DXCreateSprite(DEVICE, &sprite);

	Texture* ground_albedo = new Texture(L"Resources/Texture/Ground_Diffuse.png", L"Ground_Albedo");
	Texture* ground_specular = new Texture(L"Resources/Texture/Ground_Specular.png", L"Ground_Specular");
	Texture* ground_normal = new Texture(L"Resources/Texture/Ground_Normal.png", L"Ground_Normal");

	Texture* lamp_albedo = new Texture(L"Resources/Texture/Lamp_Diffuse.png", L"Lamp_Diffuse");
	Texture* lamp_specular = new Texture(L"Resources/Texture/Lamp_Specular.png", L"Lamp_Specular");
	Texture* lamp_normal = new Texture(L"Resources/Texture/Lamp_Normal.png", L"Lamp_Normal");

	Texture* wall_origin_albedo = new Texture(L"Resources/Texture/Wall_Original_Diffuse.png", L"Wall_Original_Diffuse");
	Texture* wall_origin_specular = new Texture(L"Resources/Texture/Wall_Original_Specular.png", L"Wall_Original_Specular");
	Texture* wall_origin_normal = new Texture(L"Resources/Texture/Wall_Original_Normal.png", L"Wall_Original_Normal");

	Texture* wall_borken1_diffuse = new Texture(L"Resources/Texture/Wall_Broken1_Diffuse.png", L"Wall_Broken1_Diffuse");
	Texture* wall_borken1_specular = new Texture(L"Resources/Texture/Wall_Broken1_Specular.png", L"Wall_Broken1_Specular");
	Texture* wall_borken1_normal = new Texture(L"Resources/Texture/Wall_Broken1_Normal.png", L"Wall_Broken1_Normal");
	cout << "TextureCount : " << texturelist.size() << endl;
}

Texture* TextureManager::GetTexture(wstring name)
{
	for (Texture* tex : texturelist)
	{
		if (tex->name == name)
		{
			wcout << "Find Texture : " << name.c_str() << endl;
			return tex;
		}
	}
	wcout << "텍스처를 찾지 못했습니다 : " << name.c_str() << endl;
	return nullptr;
}

void TextureManager::AddTexture(Texture* t)
{
	for (Texture* tex : texturelist)
	{
		if (tex->name == t->name)
		{
			wcout << "텍스처가 이미 있습니다 : " << tex->name << endl;
			return;
		}
	}
	texturelist.push_back(t);
	wcout << "Add Texture : " << t->name << endl;
}

void TextureManager::Exit()
{
	sprite->Release();
	for (Texture* texture : texturelist)
	{
		texture->Exit();
	}

}
