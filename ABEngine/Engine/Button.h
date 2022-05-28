#pragma once
#include "UI.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "InputManager.h"

class Button : public UI
{
private:
public:
	Button();
	Button(wstring textureName);
	Button(wstring textureName, int l);

	Texture* image;

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	bool CheckIn();

	bool OnClick();

	template <typename T>
	void func(T t)
	{
		t();
	}
};

