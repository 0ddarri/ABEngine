#pragma once
#include "Component.h"
#include "CameraManager.h"
#include "TextureManager.h"
#include "Transform.h"
#include "GameObject.h"

class Image : public Component
{
private:
protected:
public:
	Image();
	Image(wstring path);

	Texture* image;

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();
};

