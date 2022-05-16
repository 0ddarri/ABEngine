#pragma once
#include "Material.h"
#include "../MeshRenderer.h"
#include "../Texture.h"
#include "../TextureManager.h"

class SpecularMapping : public Material
{
private:
	Texture* albedo;
	Texture* specular;
	Texture* normal;
public:
	SpecularMapping();
	SpecularMapping(wstring albedo, wstring specular, wstring normal);

	virtual void Init();
	virtual void Render(MeshRenderer* m);
	virtual void Exit();
};

