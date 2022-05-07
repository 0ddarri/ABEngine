#include "DXUT.h"
#include "CameraManager.h"

void CameraManager::AddCamera(Camera* cam)
{
	cameralist.push_back(cam);
}

Camera* CameraManager::GetCurCamera()
{
	return cameralist[curCamNumber];
}

void CameraManager::Exit()
{
	cameralist.clear();
}
