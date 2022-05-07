#pragma once
#include "Component.h"
#include "Transform.h"
#include "GameObject.h"

class Camera : public Component
{
private:
	void SetViewMat();
	void SetProjMat();
protected:
public:
	Camera();

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	D3DXMATRIXA16 viewMat;
	D3DXMATRIXA16 projMat;
};

