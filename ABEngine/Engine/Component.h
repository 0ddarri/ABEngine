#pragma once
class Component
{
private:
protected:
public:
	Component() {};

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Exit();

	wstring name = L"Component"; // �̸����� ������Ʈ �޾ƿ��� ���ѳ�
};