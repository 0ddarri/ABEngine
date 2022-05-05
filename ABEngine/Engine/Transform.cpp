#include "DXUT.h"
#include "Transform.h"

Transform::Transform()
{
	name = L"Transform";

	position = new D3DXVECTOR3(0, 0, 0);
	rotation = new D3DXVECTOR3(0, 0, 0);
	scale = new D3DXVECTOR3(1, 1, 1);
}

Transform::Transform(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const D3DXVECTOR3 s)
{
	*position = pos;
	*rotation = rot;
	*scale = s;
}

void Transform::Init()
{
}

void Transform::Update(float deltaTime)
{
}

void Transform::SetMatrix()
{
	D3DXMATRIXA16 trans;
	D3DXMatrixTranslation(&trans, position->x, position->y, position->z);

	D3DXMATRIXA16 rot;
	D3DXMatrixRotationYawPitchRoll(&rot, rotation->x, rotation->y, rotation->z);

	D3DXMATRIXA16 scalemat;
	D3DXMatrixScaling(&scalemat, scale->x, scale->y, scale->z);

	worldMat = trans * rot * scalemat;

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
