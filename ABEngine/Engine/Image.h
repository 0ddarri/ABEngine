#pragma once
#include "UI.h"
#include "CameraManager.h"
#include "TextureManager.h"
#include "Transform.h"
#include "GameObject.h"

class Image : public UI
{
private:
protected:
public:
	Image();
	Image(wstring texName);
	Image(wstring texName, int l);

	Texture* image;

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();
};

