#include "DXUT.h"
#include "TestScene.h"

void ButtonClick()
{

}

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
	Cam->transform->position = D3DXVECTOR3(7, 3, -7);

	ground = new GameObject();
	ground->AddComp(new MeshRenderer(L"Resources/Mesh/Ground.x", L"Ground Mat"));

	lamp = new GameObject();
	lamp->AddComp(new MeshRenderer(L"Resources/Mesh/Lamp.x", L"Lamp"));
	lamp->transform->position.y = 0.35f;

	testLight = new GameObject();
	testLight->AddComp(new PointLight(2, 5, L"TestLight"));
	testLight->transform->position.y = 2.0f;

	ObjSpawnUI_BG = new GameObject();
	ObjSpawnUI_BG->AddComp(new Image(L"UI_Background", 0));
	AddUI(ObjSpawnUI_BG);

	ObjSpawnUI_BG->transform->scale = D3DXVECTOR3(0.5f, 0.5f, 0.5f);

	ObjSpawnUI_BG->transform->position.x = 100;
	ObjSpawnUI_BG->transform->position.y = 500;

	for (int i = 0; i < 3; i++)
	{
		ObjectBtnUI* btn = new ObjectBtnUI(i);
		AddUI(btn);
		btn->transform->position.x = 110;
		btn->transform->position.y = 100 * (i + 1);
		ObjButtonList.push_back(btn);
	}

	SelectedObj = new GameObject();
	SelectedObj->AddComp(new MeshRenderer(L"Resources/Mesh/Ground.x", L"Ground Mat"));
	SelectedObj->transform->position = D3DXVECTOR3(-10000, -10000, -100000);
	AddObj(SelectedObj);

	AddObj(Cam);
	AddObj(ground);
	AddObj(lamp);
	AddObj(testLight);

	cout << _Objectlist.size() << endl;
}

void TestScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	for (int i = 0; i < ObjButtonList.size(); i++)
	{
		if (ObjButtonList[i]->GetComponent<Button>().OnClick())
		{
			curtype = ObjButtonList[i]->type;
			if (SelectedObj != nullptr)
				ObjectManager::Instance()->Destroy(SelectedObj);
			SelectedObj = ObjectManager::Instance()->Instantiate(curtype, D3DXVECTOR3(0,0,0));
			cout << "현재 타입: " << curtype << endl;
		}
	}


	if (DXUTWasKeyPressed(VK_F12))
	{
		testInst = ObjectManager::Instance()->Instantiate(OBJECT_TYPE::LAMP, D3DXVECTOR3(0, 2, 0));
		cout << "asdf" << endl;
	}
	if (DXUTWasKeyPressed(VK_F11))
	{
		ObjectManager::Instance()->Destroy(testInst);
	}

	CameraMove(deltaTime);
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

void TestScene::CameraMove(float deltaTime)
{
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
