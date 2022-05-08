#pragma once
#include "Material.h"
#include "../MeshRenderer.h"
#include "../TextureManager.h"

class TextureMapping : public Material
{
private:
public:
	TextureMapping();
	TextureMapping(D3DXMATRIXA16 v, D3DXMATRIXA16 p, D3DXMATRIXA16 w);

	D3DXMATRIXA16 view;
	D3DXMATRIXA16 proj;
	D3DXMATRIXA16 world;

	virtual void Init();
	virtual void Render(MeshRenderer* m);
	virtual void Exit();
};

