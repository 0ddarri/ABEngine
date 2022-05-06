#pragma once
#include "Component.h"
#include "Mesh.h"
#include "Transform.h"
#include "Materials/MaterialManager.h"
#include "GameObject.h"

class MeshRenderer : public Component
{
private:
protected:
public:
	MeshRenderer();
	MeshRenderer(wstring path, wstring matName);

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	Mesh* mesh;

	Material* material;
};

