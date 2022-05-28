#pragma once
#include "Component.h"

class Transform : public Component
{
private:
	D3DXMATRIXA16 worldMat;

	void SetMatrix();
protected:
public:
	Transform();
	Transform(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const D3DXVECTOR3 s);

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 scale;

	D3DXMATRIXA16 GetWorldMatrix();
};

