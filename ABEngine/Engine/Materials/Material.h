#pragma once
#include "../Mesh.h"

class MeshRenderer;

class Material
{
private:
protected:
public:
	Material();

	LPD3DXEFFECT LoadShader(wstring path);

	LPD3DXEFFECT shader;
	wstring name;

	virtual void Initialize();
	virtual void Render(MeshRenderer* m) PURE;
	virtual void Exit();
};

