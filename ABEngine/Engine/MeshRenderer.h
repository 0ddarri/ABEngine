#pragma once
#include "Component.h"
#include "Mesh.h"
#include "Transform.h"
#include "Materials/MaterialManager.h"
#include "GameObject.h"
#include "SceneManager.h"

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

	D3DXVECTOR4 color;

	wstring meshPath;
	wstring materialName;

	void Refresh(wstring path, wstring matName);
};

