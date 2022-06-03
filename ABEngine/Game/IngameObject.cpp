#include "DXUT.h"
#include "IngameObject.h"
#include "../Engine/MeshRenderer.h"

IngameObject::IngameObject()
{
	AddComp(new Button(L"Button", 1));
	AddComp(new Text(1, 700, L"Arial", L"", 2, D3DXCOLOR(0, 0, 0, 1)));
	GetComponent<Text>().RectSize = { (float)GetComponent<Button>().image->imgRect.right, (float)GetComponent<Button>().image->imgRect.bottom };
	cout << GetComponent<Text>().RectSize.x << " " << GetComponent<Text>().RectSize.y << endl;

	middleCircle = new GameObject();
	middleCircle->AddComp(new MeshRenderer(L"Resources/Mesh/SphereWithTangent.x", L"ColorMaterial"));
	middleCircle->name = L"MiddleCircle";
	middleCircle->transform->scale = { 0.001,0.001,0.001 };
}
IngameObject::IngameObject(GameObject* obj)
{
	AddComp(new Button(L"Button", 1));
	AddComp(new Text(1, 700, L"Arial", L"", 2, D3DXCOLOR(0, 0, 0, 1)));
	GetComponent<Text>().RectSize = { (float)GetComponent<Button>().image->imgRect.right, (float)GetComponent<Button>().image->imgRect.bottom };
	cout << GetComponent<Text>().RectSize.x << " " << GetComponent<Text>().RectSize.y << endl;

	selectedObject = obj;

	middleCircle = new GameObject();
	middleCircle->AddComp(new MeshRenderer(L"Resources/Mesh/SphereWithTangent.x", L"ColorMaterial"));
	middleCircle->name = L"MiddleCircle";
	middleCircle->transform->scale = { 0.001,0.001,0.001 };
	middleCircle->transform->position = selectedObject->transform->position;
}


void IngameObject::Init()
{
	GameObject::Init();
}

void IngameObject::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	middleCircle->transform->position = selectedObject->transform->position;

	if (selectedObject->IsComp(L"MeshRenderer"))
	{
		if (isSelected)
		{
			selectedObject->GetComponent<MeshRenderer>().color = { 1,1,0,0.5f };
			middleCircle->GetComponent<MeshRenderer>().color = { 1,1,0,1 };
		}
		else
		{
			middleCircle->GetComponent<MeshRenderer>().color = { 1,1,1,1 };
			selectedObject->GetComponent<MeshRenderer>().color = { 1,1,1,1 };
		}
	}
	else
	{
		if (isSelected)
		{
			middleCircle->GetComponent<MeshRenderer>().color = { 1,1,0,1 };
		}
		else
		{
			middleCircle->GetComponent<MeshRenderer>().color = { 1,1,1,1 };
		}
	}
}

void IngameObject::Render()
{
	GameObject::Render();
}

void IngameObject::Exit()
{
	GameObject::Exit();
	ObjectManager::Instance()->Destroy(selectedObject);
	ObjectManager::Instance()->Destroy(middleCircle);
}
