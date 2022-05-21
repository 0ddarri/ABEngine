#pragma once
#include "Component.h"

class Light : public Component
{
private:
public:
	Light()
	{
		color = D3DXVECTOR4(1, 1, 1, 1);
	}

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime) {};
	virtual void Render() {};
	virtual void Exit() {};

	D3DXVECTOR4 color;
	wstring name = L"";
};

