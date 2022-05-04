#include "DXUT.h"
#include "Transform.h"

Transform::Transform()
{
	name = L"Transform";
}

Transform::Transform(wstring name)
{
	this->name = name;
}

void Transform::Init()
{
}

void Transform::Update(float deltaTime)
{
}

void Transform::Render()
{
}

void Transform::Exit()
{
}
