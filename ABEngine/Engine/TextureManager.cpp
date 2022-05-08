#include "DXUT.h"
#include "TextureManager.h"

void TextureManager::Initialize()
{
	D3DXCreateSprite(DEVICE, &sprite);

	Texture* texture = new Texture(L"Resources/Texture/ground_Albedo.png", L"Ground_Albedo");
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
	wcout << "�ؽ�ó�� ã�� ���߽��ϴ� : " << name.c_str() << endl;
	return nullptr;
}

void TextureManager::AddTexture(Texture* t)
{
	for (Texture* tex : texturelist)
	{
		if (tex->name == t->name)
		{
			wcout << "�ؽ�ó�� �̹� �ֽ��ϴ� : " << tex->name << endl;
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
