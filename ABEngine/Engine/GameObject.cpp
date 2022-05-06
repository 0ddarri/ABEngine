#include "DXUT.h"
#include "GameObject.h"

GameObject::GameObject()
{
	transform = new Transform();
	AddComp(transform);
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
	for (Component* it : componentlist)
	{
		it->Update(deltaTime);
	}
}

void GameObject::Render()
{
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

Component* GameObject::GetComp(Component* comp)
{
	for (Component* it : componentlist)
	{
		if (it->name == comp->name)
		{
			delete comp;
			return it;
		}
	}
	cout << "컴포넌트가 존재하지 않습니다" << endl;
	delete comp;
	return nullptr;
}
