#include "DXUT.h"
#include "Camera.h"
#include "CameraManager.h"

void Camera::SetViewMat()
{
	D3DXVECTOR3 eyepos = parent->transform->position;
	D3DXVECTOR3 look = Look;
	D3DXVECTOR3 up = Up;
	D3DXVec3Normalize(&View, &(look - parent->transform->position));
	D3DXVec3Cross(&Cross, &up, &View);

	D3DXMatrixLookAtLH(&viewMat, &eyepos, &look, &up);
	DEVICE->SetTransform(D3DTS_VIEW, &viewMat);
}

void Camera::SetProjMat()
{
	D3DXMatrixPerspectiveFovLH(&projMat, FOV, ASPECT_RATIO, NEAR_PLANE, FAR_PLANE);
	DEVICE->SetTransform(D3DTS_PROJECTION, &projMat);
}

Camera::Camera()
{
	D3DXMatrixIdentity(&viewMat);
	D3DXMatrixIdentity(&projMat);
	CameraManager::Instance()->AddCamera(this);
}

void Camera::Init(GameObject* p)
{
	Component::Init(p);
}

void Camera::Update(float deltaTime)
{
}

void Camera::Render()
{
	SetViewMat();
	SetProjMat();
}
void Camera::Exit()
{
}

void Camera::MoveLocalX(float speed)
{
	D3DXVECTOR3 moveX;
	D3DXVec3Normalize(&moveX, &Cross);
	moveX *= speed;
	parent->transform->position += moveX;
	//Look += moveX;
}

void Camera::MoveLocalY(float speed)
{
	D3DXVECTOR3 moveY;
	D3DXVec3Normalize(&moveY, &Up);
	moveY *= speed;
	parent->transform->position += moveY;
	//Look += moveY;
}

void Camera::MoveLocalZ(float speed)
{
	D3DXVECTOR3 moveZ = View;
	moveZ *= speed;
	parent->transform->position += moveZ;
	//Look += moveZ;
}
