#pragma once
#include "../Engine/Scene.h"

class TestScene final : public Scene
{
private:
public:
	TestScene(wstring n);

	void Init() override;
	void Update() override;
	void Render() override;
	void Exit() override;
};

