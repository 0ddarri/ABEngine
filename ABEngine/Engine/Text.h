#pragma once
#include "UI.h"
#include "GameObject.h"

class Text : public UI
{
private:
public:
	Text();
	Text(float size, float weight, LPCWSTR fontname, wstring buff, int mylayer, D3DXCOLOR color);

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	LPD3DXFONT font = nullptr;
	wstring text = L"";
	D3DXCOLOR color = { 1,1,1,1 };

	D3DXVECTOR2 RectSize = { 1,1 };
};

