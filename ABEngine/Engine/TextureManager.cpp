#include "DXUT.h"
#include "TextureManager.h"

void TextureManager::Initialize()
{
	D3DXCreateSprite(DEVICE, &sprite);

	Texture* texture = new Texture(L"Resources/Texture/Texture_Ground_Diffuse.png", L"Ground_Albedo");

	Texture* albedo = new Texture(L"Resources/Texture/Texture_Wall_1_Diffuse.png", L"Wall_Albedo");
	Texture* specular = new Texture(L"Resources/Texture/Texture_Wall_1_Specular.png", L"Wall_Specular");
	Texture* normal = new Texture(L"Resources/Texture/Texture_Wall_1_Normal.png", L"Wall_Normal");
	Texture* uispecular = new Texture(L"Resources/Texture/specular.jpg", L"UI_Specular");
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
