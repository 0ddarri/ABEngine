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

	testCam1 = new GameObject();
	testCam1->AddComp(new Camera);
	AddObj(testCam1);

	testCam2 = new GameObject();
	testCam2->AddComp(new Camera);
	AddObj(testCam2);

	testObject2 = new GameObject();
	testObject2->AddComp(new MeshRenderer(L"Resources/Mesh/wall.x", L"defaultMaterial"));
	AddObj(testObject2);
	//testObject2->transform->scale = new D3DXVECTOR3(40, 40, 40);

	testCam1->transform->position = new D3DXVECTOR3(0.0f, 0.0f, -10.0f);
	testCam2->transform->position = new D3DXVECTOR3(-20.0f, 10.0f, -10.0f);
}

void TestScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);
	//if (testObject->GetComp(new Transform)->name == L"Transform")
	//	cout << "¾ßÈ£" << endl;

	//testObject2->transform->position->x -= deltaTime * 10;
	testObject2->transform->rotation->x -= deltaTime * 2;
	//testObject->tranform->position->x += deltaTime;

	if (DXUTWasKeyPressed(VK_F1))
	{
		CameraManager::Instance()->curCamNumber = 0;
	}
	if (DXUTWasKeyPressed(VK_F2))
	{
		CameraManager::Instance()->curCamNumber = 1;
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
