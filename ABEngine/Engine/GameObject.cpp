#include "DXUT.h"
#include "GameObject.h"

GameObject::GameObject()
{
	tranform = new Transform();
	componentlist.push_back(tranform);
}

void GameObject::Init()
{
	for (Component* it : componentlist)
	{
		it->Init();
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
			cout << "�̹� ������Ʈ�� �����մϴ�" << endl;
			delete comp;
			return;
		}
	}
	comp->Init();
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
	cout << "������Ʈ�� �������� �ʽ��ϴ�" << endl;
	delete comp;
	return nullptr;
}
