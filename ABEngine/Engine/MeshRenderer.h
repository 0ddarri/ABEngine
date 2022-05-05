#pragma once
#include "Component.h"
#include "Mesh.h"

class MeshRenderer : public Component
{
private:
protected:
public:
	MeshRenderer();
	MeshRenderer(wstring path);

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	Mesh* mesh;
};

