#pragma once
#include "Singleton.h"
#include "Camera.h"

class CameraManager : public Singleton<CameraManager>
{
private:
	vector<Camera*> cameralist;
public:
	void AddCamera(Camera* cam);

	Camera* GetCurCamera();

	int curCamNumber = 0;
	void Exit();
};

