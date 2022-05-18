#include "DXUT.h"
#include "Camera.h"
#include "CameraManager.h"

void Camera::SetViewMat()
{
	D3DXVECTOR3 eyepos = *parent->transform->position;
	D3DXVECTOR3 look = { 0,0,0 };
	D3DXVECTOR3 up = { 0,1,0 };

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

void Camera::Init()
{
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
