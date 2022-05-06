#pragma once

class GameObject;

class Component
{
private:
protected:
public:
	Component() {};

	virtual void Init(GameObject* p);
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	wstring name = L"Component"; // �̸����� ������Ʈ �޾ƿ��� ���ѳ�

	GameObject* parent;
};