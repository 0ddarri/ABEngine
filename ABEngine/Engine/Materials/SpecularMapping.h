#pragma once
#include "Material.h"
#include "../MeshRenderer.h"
#include "../Texture.h"
#include "../TextureManager.h"
#include "../LightManager.h"
#include "../Transform.h"

class SpecularMapping : public Material
{
private:
public:
	Texture* albedo;
	Texture* specular;
	Texture* normal;

	SpecularMapping();
	SpecularMapping(wstring albedo, wstring specular, wstring normal);

	virtual void Init();
	virtual void Render(MeshRenderer* m);
	virtual void Exit();
};

