#pragma once
#include "../Engine/Scene.h"
#include "../Engine/GameObject.h"
#include "../Engine/MeshRenderer.h"
#include "../Engine/Camera.h"
#include "../Engine/CameraManager.h"
#include "../Engine/Image.h"
#include "../Engine/LightManager.h"

class TestScene final : public Scene
{
private:
public:
	TestScene(wstring n);

	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Exit() override;

	GameObject* testCam1;
	GameObject* testCam2;
	GameObject* testObject2;
	GameObject* testUI;
};

