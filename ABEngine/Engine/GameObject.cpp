#include "DXUT.h"
#include "GameObject.h"

GameObject::GameObject()
{
	transform = new Transform();
	AddComp(transform);
	Active = true;
	name = L"GameObject";
}

GameObject::GameObject(GameObject* obj)
{
	componentlist = obj->componentlist;
	transform = obj->transform;
	name = obj->name;
	Active = obj->Active;
}

void GameObject::Init()
{
	for (Component* it : componentlist)
	{
		it->Init(this);
	}
}

void GameObject::Update(float deltaTime)
{
	if (!Active) return;
	for (Component* it : componentlist)
	{
		it->Update(deltaTime);
	}
}

void GameObject::Render()
{
	if (!Active) return;
	for (Component* it : componentlist)
	{
		it->Render();
	}
}

void GameObject::Exit()
{
	for (Component* it : componentlist)
	{
		it->Exit();
	}
}

void GameObject::AddComp(Component* comp)
{
	for (Component* it : componentlist)
	{
		if (it->name == comp->name)
		{
			cout << "이미 컴포넌트가 존재합니다" << endl;
			delete comp;
			return;
		}
	}
	comp->Init(this);
	componentlist.push_back(comp);
}

bool GameObject::IsComp(wstring compname)
{
	for (Component* it : componentlist)
	{
		if (it->name == compname)
		{
			return true;
		}
	}
	return false;
}
