#include "DXUT.h"
#include "ObjectBtnUI.h"

ObjectBtnUI::ObjectBtnUI()
{
	AddComp(new Button(L"Button", 0));
	AddComp(new Text(1, 700, L"Arial", L"", 2, D3DXCOLOR(0, 0, 0, 1)));
	GetComponent<Text>().RectSize = { (float)GetComponent<Button>().image->imgRect.right, (float)GetComponent<Button>().image->imgRect.bottom };
	cout << GetComponent<Text>().RectSize.x << " " << GetComponent<Text>().RectSize.y << endl;
	GetComponent<Text>().text = objName;
}

ObjectBtnUI::ObjectBtnUI(int type, wstring objName)
{
	AddComp(new Button(L"Button", type));
	this->type = (OBJECT_TYPE)type;
	AddComp(new Text(0.7, 700, L"Arial", L"", 2, D3DXCOLOR(0, 0, 0, 1)));
	GetComponent<Text>().RectSize = { (float)GetComponent<Button>().image->imgRect.right, (float)GetComponent<Button>().image->imgRect.bottom - 13 };
	cout << GetComponent<Text>().RectSize.x << " " << GetComponent<Text>().RectSize.y << endl;
	GetComponent<Text>().text = objName;
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

void ObjectBtnUI::SetName(wstring n)
{
	name = n;
	GetComponent<Text>().text = name;
}

