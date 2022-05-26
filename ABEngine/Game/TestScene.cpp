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

	Cam = new GameObject();
	Cam->AddComp(new Camera);
	Cam->transform->position = new D3DXVECTOR3(7, 3, -7);

	ground = new GameObject();
	ground->AddComp(new MeshRenderer(L"Resources/Mesh/Ground.x", L"Ground Mat"));

	lamp = new GameObject();
	lamp->AddComp(new MeshRenderer(L"Resources/Mesh/Lamp.x", L"Lamp"));
	lamp->transform->position->y = 0.35f;

	testLight = new GameObject();
	testLight->AddComp(new PointLight(2, 5, L"TestLight"));
	testLight->transform->position->y = 2.0f;

	ObjSpawnUI_BG = new GameObject();
	ObjSpawnUI_BG->AddComp(new Image(L"UI_Background"));


	AddObj(Cam);
	AddObj(ground);
	AddObj(lamp);
	AddObj(testLight);
	AddObj(ObjSpawnUI_BG);

	cout << _Objectlist.size() << endl;
}

void TestScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	if (DXUTWasKeyPressed(VK_F12))
	{
		ObjectManager::Instance()->Instantiate(OBJECT_TYPE::WALL_HOLE, D3DXVECTOR3(0, 0, 0));
		cout << "asdf" << endl;
	}

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