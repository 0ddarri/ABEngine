#pragma once
#include "Component.h"
#include "UI.h"
#include "Transform.h"

class GameObject
{
private:
	list<Component*> componentlist;
protected:
public:
	bool Active;

	GameObject();
	GameObject(GameObject* obj);

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	void AddComp(Component* comp);
	bool IsComp(wstring compname);

	template <class T>
	T& GetComponent()
	{
		for (Component* it : componentlist)
		{
			if (nullptr != dynamic_cast<T*> (it))
				return *static_cast<T*>(it);
		}
	}

	GameObject* parent = nullptr;

	Transform* transform;

	void SetActive(bool b)
	{
		Active = b;
	}

	wstring name;
};

