#include "DXUT.h"
#include "Transform.h"

Transform::Transform()
{
	name = L"Transform";

	position = D3DXVECTOR3(0, 0, 0);
	rotation = D3DXVECTOR3(0, 0, 0);
	scale = D3DXVECTOR3(1, 1, 1);
}

Transform::Transform(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const D3DXVECTOR3 s)
{
	position = pos;
	rotation = rot;
	scale = s;
}

void Transform::Init(GameObject* p)
{
	Component::Init(p);
}

void Transform::Update(float deltaTime)
{
}

void Transform::SetMatrix()
{
	D3DXMATRIXA16 trans;
	D3DXMatrixTranslation(&trans, position.x, position.y, position.z);

	D3DXVECTOR3 rot(rotation);
	D3DXMATRIXA16 rotX;
	D3DXMatrixRotationX(&rotX, D3DXToRadian(rot.x));
	D3DXMATRIXA16 rotY;
	D3DXMatrixRotationY(&rotY, D3DXToRadian(rot.y));
	D3DXMATRIXA16 rotZ;
	D3DXMatrixRotationZ(&rotZ, D3DXToRadian(rot.z));

	D3DXMATRIXA16 angle = rotX * rotY * rotZ;

	D3DXMATRIXA16 scalemat;
	D3DXMatrixScaling(&scalemat, scale.x, scale.y, scale.z);

	worldMat = angle * scalemat * trans;

	DEVICE->SetTransform(D3DTS_WORLD, &worldMat);
}

void Transform::Render()
{
	SetMatrix();
}

void Transform::Exit()
{
}

D3DXMATRIXA16 Transform::GetWorldMatrix()
{
	return worldMat;
}