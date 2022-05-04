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

	wstring name = L"Component"; // 이름으로 컴포넌트 받아오기 위한놈
};