#include "DXUT.h"
#include "ObjectBtnUI.h"

ObjectBtnUI::ObjectBtnUI()
{
	AddComp(new Button(L"Button", 0));
	//GetComponent<Button>().func(OnClick_Set);
}

ObjectBtnUI::ObjectBtnUI(int type)
{
	AddComp(new Button(L"Button", type));
	this->type = (OBJECT_TYPE)type;
}

void ObjectBtnUI::Init()
{
	GameObject::Init();
}

void ObjectBtnUI::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void ObjectBtnUI::Render()
{
	GameObject::Render();
}

void ObjectBtnUI::Exit()
{
	GameObject::Exit();
}

