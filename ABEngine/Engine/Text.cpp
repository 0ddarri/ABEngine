#include "DXUT.h"
#include "Text.h"

Text::Text()
{
}

Text::Text(float size, float weight, LPCWSTR fontname, wstring buff, int mylayer, D3DXCOLOR color)
{
	layer = mylayer;
	text = buff;
	this->color = color;
	D3DXCreateFont(DEVICE, 20 * size, 0, weight, 1, 0, 1, 0, 0, 0 || FF_DONTCARE, fontname, &font);
	RectSize = { 100,100 };
}

void Text::Init(GameObject* p)
{
	UI::Init(p);
}

void Text::Update(float deltaTime)
{
}

void Text::Render()
{
	if (font == nullptr) return;
	if (text == L"") return;


	RECT r;
	//SetRect(&r, (long)parent->transform->position.x, (long)parent->transform->position.y, 0, 0);
	SetRect(&r, (long)parent->transform->position.x - RectSize.x / 2, (long)parent->transform->position.y - RectSize.y / 2, (long)parent->transform->position.x + RectSize.x / 2, (long)parent->transform->position.y + RectSize.y / 2);
	font->DrawTextW(nullptr, text.c_str(), -1, &r, DT_CENTER | DT_VCENTER, color);
}

void Text::Exit()
{
	font->Release();
}