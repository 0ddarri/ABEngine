#include "DXUT.h"
#include "Button.h"

Button::Button()
{
	name = L"Button";
	layer = 0;
}

Button::Button(wstring textureName)
{
	name = L"Button";
	image = TextureManager::Instance()->GetTexture(textureName);
	layer = 0;
}

Button::Button(wstring textureName, int l)
{
	name = L"Button";
	image = TextureManager::Instance()->GetTexture(textureName);
	layer = l;
}

void Button::Init(GameObject* p)
{
	Component::Init(p);
}

void Button::Update(float deltaTime)
{
}

void Button::Render()
{
	TextureManager::Instance()->Sprite()->Begin(D3DXSPRITE_ALPHABLEND);

	TextureManager::Instance()->Sprite()->SetTransform(&parent->transform->GetWorldMatrix());
	D3DXVECTOR3 center(image->info.Width * 0.5f, image->info.Height * 0.5f, 0);
	TextureManager::Instance()->Sprite()->Draw(image->GetTexture(), &image->imgRect, &center, nullptr, D3DXCOLOR(1, 1, 1, 1));
	TextureManager::Instance()->Sprite()->End();
}

void Button::Exit()
{
}

bool Button::CheckIn()
{
	if (image == nullptr) return false;

	float left =  parent->transform->position.x - image->info.Width / 2;
	float right =  parent->transform->position.x + image->info.Width / 2;
	float top =  parent->transform->position.y + image->info.Height / 2;
	float bottom =  parent->transform->position.y - image->info.Height / 2;

	D3DXVECTOR2 mousePos = InputManager::Instance()->cursor->GetMousePosition();
	if (mousePos.x > left && mousePos.x < right && mousePos.y > bottom && mousePos.y < top)
	{
		return true;
	}
	return false;
}

bool Button::OnClick()
{
	if (image == nullptr) return false;

	if (InputManager::Instance()->OnMouseDown)
	{
		if (CheckIn())
		{
			return true;
		}
	}
	return false;
}
