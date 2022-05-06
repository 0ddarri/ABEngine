#pragma once
#include "Component.h"
#include "Transform.h"

class GameObject
{
private:
	list<Component*> componentlist;
protected:
public:
	GameObject();

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	void AddComp(Component* comp);
	Component* GetComp(Component* comp);

	GameObject* parent = nullptr;

	Transform* transform;
};

