#pragma once
#include "Material.h"
#include "../MeshRenderer.h"
#include "../Texture.h"
#include "../TextureManager.h"
#include "../Transform.h"

class TextureMapping : public Material
{
private:
	Texture* texture;
public:
	TextureMapping();
	TextureMapping(wstring texName);

	D3DXMATRIXA16 view;
	D3DXMATRIXA16 proj;
	D3DXMATRIXA16 world;

	virtual void Init();
	virtual void Render(MeshRenderer* m);
	virtual void Exit();
};

