#pragma once
#include "Singleton.h"
#include "Texture.h"

class TextureManager : public Singleton<TextureManager>
{
private:
	LPD3DXSPRITE sprite;
	list<Texture*> texturelist;
public:
	void Initialize();

	LPD3DXSPRITE Sprite()
	{
		return sprite;
	}
	
	Texture* GetTexture(wstring name);
	void AddTexture(Texture* t);

	void Exit();
};

