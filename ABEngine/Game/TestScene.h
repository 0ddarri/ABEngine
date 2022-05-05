#pragma once
#include "../Engine/Scene.h"
#include "../Engine/GameObject.h"
#include "../Engine/MeshRenderer.h"

class TestScene final : public Scene
{
private:
public:
	TestScene(wstring n);

	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Exit() override;

	GameObject* testObject;
	GameObject* testObject2;
};

