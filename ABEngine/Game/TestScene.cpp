#include "DXUT.h"
#include "TestScene.h"

TestScene::TestScene(wstring n)
{
	name = n;
}

void TestScene::Init()
{
	Scene::Init();
	cout << "Init" << endl;

	testCam2 = new GameObject();
	testCam2->AddComp(new Camera);
	AddObj(testCam2);

	testCam1 = new GameObject();
	testCam1->AddComp(new Camera);
	AddObj(testCam1);

	ground = new GameObject();
	ground->AddComp(new MeshRenderer(L"Resources/Mesh/Ground.x", L"Ground Mat"));
	wall_1 = new GameObject();
	wall_1->AddComp(new MeshRenderer(L"Resources/Mesh/Wall_Original.x", L"Original Wall"));
	wall_2 = new GameObject();
	wall_2->AddComp(new MeshRenderer(L"Resources/Mesh/Wall_Broken1.x", L"Broken Wall 1"));
	lamp = new GameObject();
	lamp->AddComp(new MeshRenderer(L"Resources/Mesh/Lamp.x", L"Lamp"));
	AddObj(ground);
	AddObj(wall_1);
	AddObj(wall_2);
	AddObj(lamp);

	button = new GameObject();
	button->AddComp(new Button(L"Ground_Albedo"));
	AddObj(button);

	testCam1->transform->position = new D3DXVECTOR3(0.0f, 0.0f, -10.0f);
	testCam2->transform->position = new D3DXVECTOR3(7, 3, -7);

	testLight = new GameObject();
	testLight->AddComp(new PointLight(2, 5, L"TestLight"));
	testLight->transform->position->y = 2.0f;

	wall_1->transform->position->x = -2.65f;
	wall_1->transform->position->y = 2.35f;

	wall_2->transform->position->z = 2.65f;
	wall_2->transform->position->y = 2.35f;

	lamp->transform->position->y = 0.35f;
}

void TestScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	if (DXUTIsKeyDown('W'))
	{
		CameraManager::Instance()->GetCurCamera()->MoveLocalZ(deltaTime * 6);
	}
	if (DXUTIsKeyDown('A'))
	{
		CameraManager::Instance()->GetCurCamera()->MoveLocalX(-deltaTime * 6);
	}
	if (DXUTIsKeyDown('D'))
	{
		CameraManager::Instance()->GetCurCamera()->MoveLocalX(deltaTime * 6);
	}
	if (DXUTIsKeyDown('S'))
	{
		CameraManager::Instance()->GetCurCamera()->MoveLocalZ(-deltaTime * 6);
	}
	if (DXUTIsKeyDown('E'))
	{
		CameraManager::Instance()->GetCurCamera()->MoveLocalY(deltaTime * 6);
	}
	if (DXUTIsKeyDown('Q'))
	{
		CameraManager::Instance()->GetCurCamera()->MoveLocalY(-deltaTime * 6);
	}

	if (DXUTWasKeyPressed(VK_F1))
	{
		CameraManager::Instance()->curCamNumber = 0;
	}
	if (DXUTWasKeyPressed(VK_F2))
	{
		CameraManager::Instance()->curCamNumber = 1;
	}

	if (DXUTIsKeyDown(VK_F5))
	{
		LightManager::Instance()->pointLightList[0]->range += deltaTime * 2;
		cout << LightManager::Instance()->pointLightList[0]->range << endl;
	}
	if (DXUTIsKeyDown(VK_F6))
	{
		LightManager::Instance()->pointLightList[0]->range -= deltaTime * 2;
		cout << LightManager::Instance()->pointLightList[0]->range << endl;
	}

	if (DXUTIsKeyDown(VK_F7))
	{
		LightManager::Instance()->pointLightList[0]->fallOffRange += deltaTime * 2;
		cout << LightManager::Instance()->pointLightList[0]->fallOffRange << endl;
	}
	if (DXUTIsKeyDown(VK_F8))
	{
		LightManager::Instance()->pointLightList[0]->fallOffRange -= deltaTime * 2;
		cout << LightManager::Instance()->pointLightList[0]->fallOffRange << endl;
	}
	if (DXUTIsKeyDown(VK_F9))
	{
		testLight->transform->position->y += deltaTime;
	}
	if (DXUTIsKeyDown(VK_F10))
	{
		testLight->transform->position->y -= deltaTime;
	}

	if (button->GetComponent<Button>().OnClick())
	{
		cout << "안에있다" << endl;
	}
}

void TestScene::Render()
{
	Scene::Render();
}

void TestScene::Exit()
{
	Scene::Exit();
	cout << "Exit" << endl;
}
