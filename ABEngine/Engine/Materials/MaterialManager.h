#pragma once
#include "../Singleton.h"
#include "Material.h"
#include "ColorMat.h"
#include "TextureMapping.h"
#include "SpecularMapping.h"

class MaterialManager : public Singleton<MaterialManager>
{
private:
	list<Material*> materialList;
public:
	void Initialize();
	void AddMaterial(Material* m);
	Material* GetMaterial(wstring name);

	void Exit();
};