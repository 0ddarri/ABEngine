#pragma once
#include "../Engine/Scene.h"
#include "../Engine/GameObject.h"
#include "../Engine/Camera.h"
#include "../Engine/CameraManager.h"
#include "../Engine/Image.h"
#include "../Engine/LightManager.h"
#include "../Engine/PointLight.h"
#include "../Engine/InputManager.h"
#include "../Engine/Button.h"
#include "../Engine/ObjectManager.h"
#include "../Engine/Text.h"
#include "../Engine/MeshRenderer.h"
#include "ObjectBtnUI.h"
#include "IngameObject.h"

class TestScene final : public Scene
{
private:
public:
	TestScene(wstring n);

	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Exit() override;

	GameObject* Cam;
	GameObject* testLight;

	GameObject* ground;
	GameObject* lamp;

	GameObject* ObjSpawnUI_BG;
	GameObject* ObjSelectUI_BG;

	vector<ObjectBtnUI*> ObjButtonList;
	OBJECT_TYPE SelectedType;

	void CameraMove(float deltaTime);

	GameObject* testInst;

	OBJECT_TYPE curtype;

	GameObject* CreatedObj;

	float MovingTime = 0.0f;
	void MoveSelectedObj(float deltaTime);

	D3DXVECTOR3 GroundUpperPosition;

	vector<IngameObject*> IngameObjList;
	void SetObectButtons();
	void MoveIngameObj(float deltaTime);
	void DeleteIngameObj();
};

