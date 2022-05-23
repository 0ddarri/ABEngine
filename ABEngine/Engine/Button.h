#pragma once
#include "Component.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "InputManager.h"

class Button : public Component
{
private:
public:
	Button();
	Button(wstring textureName);

	Texture* image;

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	bool CheckIn();

	bool OnClick();
};

