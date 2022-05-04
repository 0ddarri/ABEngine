#pragma once
#include "Component.h"

class Transform : public Component
{
private:
protected:
public:
	Transform();
	Transform(wstring name);

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();
};

