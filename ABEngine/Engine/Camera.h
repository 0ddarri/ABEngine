#pragma once
#include "Component.h"
#include "Transform.h"
#include "GameObject.h"

class Camera : public Component
{
private:
	void SetViewMat();
	void SetProjMat();

	D3DXVECTOR3 Look = { 0,2,0 };
	D3DXVECTOR3 Up = { 0,1,0 };
	D3DXVECTOR3 View = { 0,0,0 };
	D3DXVECTOR3 Cross = { 0,0,0 };
protected:
public:
	Camera();

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	void MoveLocalX(float speed);
	void MoveLocalY(float speed);
	void MoveLocalZ(float speed);

	D3DXMATRIXA16 viewMat;
	D3DXMATRIXA16 projMat;
};

