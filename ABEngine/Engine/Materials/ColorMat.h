#pragma once
#include "Material.h"
#include "../MeshRenderer.h"

class ColorMat : public Material
{
private:
public:
	ColorMat();
	ColorMat(D3DXMATRIXA16 v, D3DXMATRIXA16 p, D3DXMATRIXA16 w);

	D3DXMATRIXA16 view;
	D3DXMATRIXA16 proj;
	D3DXMATRIXA16 world;

	virtual void Init();
	virtual void Render(MeshRenderer* m);
	virtual void Exit();
};

