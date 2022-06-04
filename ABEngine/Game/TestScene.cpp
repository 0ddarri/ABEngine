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

	isCreating = false;

	Cam = new GameObject();
	Cam->AddComp(new Camera);
	Cam->transform->position = D3DXVECTOR3(7, 3, -7);

	ground = new GameObject();
	ground->AddComp(new MeshRenderer(L"Resources/Mesh/Ground.x", L"Ground Mat"));
	ground->name = L"Ground";
	GroundUpperPosition = { 0,0.15,0 };

	lamp = new GameObject();
	lamp->AddComp(new MeshRenderer(L"Resources/Mesh/Lamp.x", L"Lamp"));
	lamp->name = L"Lamp";
	lamp->transform->position.y = 0.35f;

	testLight = new GameObject();
	testLight->AddComp(new PointLight(2, 5, L"TestLight"));
	testLight->name = L"Point Light";
	testLight->transform->position.y = 2.0f;

	ObjSpawnUI_BG = new GameObject();
	ObjSpawnUI_BG->AddComp(new Image(L"UI_Background", 0));
	ObjSpawnUI_BG->transform->scale = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
	ObjSpawnUI_BG->transform->position.x = 50;
	ObjSpawnUI_BG->transform->position.y = 300;
	AddUI(ObjSpawnUI_BG);

	ObjSelectUI_BG = new GameObject();
	ObjSelectUI_BG->AddComp(new Image(L"UI_Background", 0));
	ObjSelectUI_BG->transform->scale = D3DXVECTOR3(-0.5f, 0.5f, 0.5f);
	ObjSelectUI_BG->transform->position.x = 1230;
	ObjSelectUI_BG->transform->position.y = 300;
	AddUI(ObjSelectUI_BG);

	for (int i = 0; i < 3; i++)
	{
		ObjectBtnUI* btn = new ObjectBtnUI(i, L"OriginalWall");
		switch (i)
		{
		case 0:
			btn->SetName(L"Original Wall");
			btn->materialName = L"Original Wall";
			break;
		case 1:
			btn->SetName(L"Broken Wall");
			btn->materialName = L"Broken Wall 1";
			break;
		case 2:
			btn->SetName(L"Lamp");
			btn->materialName = L"Lamp";
			break;
		default:
			break;
		}
		btn->transform->scale = { 0.5,0.5,0.5 };
		AddUI(btn);
		btn->transform->position.x = 43;
		btn->transform->position.y = 80 + (30 * i);
		ObjButtonList.push_back(btn);
	}

	CreatedObj = new GameObject();
	CreatedObj->AddComp(new MeshRenderer(L"Resources/Mesh/Ground.x", L"Ground Mat"));
	CreatedObj->transform->position = D3DXVECTOR3(-10000, -10000, -100000);
	AddObj(CreatedObj);
	//CreatedObj = nullptr;

	AddObj(Cam);
	AddObj(ground);
	AddObj(lamp);
	AddObj(testLight);

	IngameObject* temp1 = new IngameObject(ground);
	IngameObjList.push_back(temp1);
	AddUI(temp1);
	AddObj(temp1->middleCircle);

	IngameObject* temp2 = new IngameObject(lamp);
	IngameObjList.push_back(temp2);
	AddUI(temp2);
	AddObj(temp2->middleCircle);

	IngameObject* temp3 = new IngameObject(testLight);
	IngameObjList.push_back(temp3);
	AddUI(temp3);
	AddObj(temp3->middleCircle);

	for (int i = 0; i < IngameObjList.size(); i++)
	{
		IngameObjList[i]->transform->scale = { 0.5,0.5,0.5 };
		IngameObjList[i]->transform->position = D3DXVECTOR3(1235, 100 + (20 * i), 0);
		IngameObjList[i]->GetComponent<Text>().text = IngameObjList[i]->selectedObject->name;
	}

	MovingTime = 0.0f;

	cout << _Objectlist.size() << endl;
}

void TestScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	for (int i = 0; i < ObjButtonList.size(); i++)
	{
		if (ObjButtonList[i]->GetComponent<Button>().OnClick())
		{
			isCreating = true;
			curtype = ObjButtonList[i]->type;
			//if (CreatedObj != nullptr)
			//	ObjectManager::Instance()->Destroy(CreatedObj);
			//CreatedObj = ObjectManager::Instance()->Instantiate(curtype, D3DXVECTOR3(0, 0.35f, 0));
			CreatedObj->GetComponent<MeshRenderer>().Refresh(ObjectManager::Instance()->ObjPathlist.at(curtype),ObjButtonList[i]->materialName);
			CreatedObj->transform->position = D3DXVECTOR3(0, 0.35f, 0);
			CreatedObj->name = ObjButtonList[i]->name;
			CreatedObj->GetComponent<MeshRenderer>().color = { 0.5,0,0.5,1 };
			cout << "현재 타입: " << curtype << endl;
		}
	}

	if (isCreating)
	{
		MoveSelectedObj(deltaTime);
		if (DXUTWasKeyPressed(VK_END))
		{
			// 맨아래 좌표에 맞추는 기능 넣기
		}

		if (DXUTWasKeyPressed(VK_BACK))
		{
			ObjectManager::Instance()->Destroy(CreatedObj);
		}

		if (DXUTWasKeyPressed(VK_RETURN))
		{
			isCreating = false;
			GameObject* obj = new GameObject();
			obj->AddComp(new MeshRenderer(CreatedObj->GetComponent<MeshRenderer>().meshPath, CreatedObj->GetComponent<MeshRenderer>().materialName));
			obj->transform->position = CreatedObj->transform->position;
			obj->name = CreatedObj->name;
			obj->GetComponent<MeshRenderer>().color = { 1,1,1,1 };
			CreatedObj->transform->position = { -10000,-10000,-10000 };

			IngameObject* ingameObj = new IngameObject(obj);
			ingameObj->GetComponent<Text>().text = obj->name;
			ingameObj->transform->scale = { 0.5,0.5,0.5 };
			ingameObj->transform->position = D3DXVECTOR3(1235, 100 + (20 * (IngameObjList.size())), 0);
			IngameObjList.push_back(ingameObj);

			AddObj(obj);
			AddUI(ingameObj);
		}
	}
	else
	{
		SetObectButtons();
		MoveIngameObj(deltaTime);
		DeleteIngameObj();
	}

	if (DXUTIsKeyDown(VK_F1))
	{
		CreatedObj->transform->rotation.x -= deltaTime;
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

void TestScene::MoveSelectedObj(float deltaTime)
{
	if (DXUTWasKeyPressed(VK_LEFT) || DXUTWasKeyPressed(VK_RIGHT) || DXUTWasKeyPressed(VK_UP) || DXUTWasKeyPressed(VK_DOWN))
		MovingTime = 0.1f;

	if (DXUTIsKeyDown(VK_MENU)) // LAlt
	{
		if (DXUTIsKeyDown(VK_LEFT))
		{
			MovingTime += deltaTime;
			if (MovingTime > 0.1f)
			{
				CreatedObj->transform->rotation.x -= 15;
				MovingTime = 0.0f;
			}
		}
		else if (DXUTIsKeyDown(VK_RIGHT))
		{
			MovingTime += deltaTime;
			if (MovingTime > 0.1f)
			{
				CreatedObj->transform->rotation.x += 15;
				MovingTime = 0.0f;
			}
		}
		if (DXUTIsKeyDown(VK_LCONTROL))
		{
			if (DXUTIsKeyDown(VK_UP))
			{
				MovingTime += deltaTime;
				if (MovingTime > 0.1f)
				{
					CreatedObj->transform->rotation.y -= 15;
					MovingTime = 0.0f;
				}
			}
			else if (DXUTIsKeyDown(VK_DOWN))
			{
				MovingTime += deltaTime;
				if (MovingTime > 0.1f)
				{
					CreatedObj->transform->rotation.y += 15;
					MovingTime = 0.0f;
				}
			}
		}
		else
		{
			if (DXUTIsKeyDown(VK_UP))
			{
				MovingTime += deltaTime;
				if (MovingTime > 0.1f)
				{
					CreatedObj->transform->rotation.z -= 15;
					MovingTime = 0.0f;
				}
			}
			else if (DXUTIsKeyDown(VK_DOWN))
			{
				MovingTime += deltaTime;
				if (MovingTime > 0.1f)
				{
					CreatedObj->transform->rotation.z += 15;
					MovingTime = 0.0f;
				}
			}
		}
	}
	else
	{
		if (DXUTIsKeyDown(VK_LEFT))
		{
			MovingTime += deltaTime;
			if (MovingTime > 0.1f)
			{
				CreatedObj->transform->position.x -= 0.265f;
				MovingTime = 0.0f;
			}
		}
		else if (DXUTIsKeyDown(VK_RIGHT))
		{
			MovingTime += deltaTime;
			if (MovingTime > 0.1f)
			{
				CreatedObj->transform->position.x += 0.265f;
				MovingTime = 0.0f;
			}
		}

		if (DXUTIsKeyDown(VK_LCONTROL))
		{
			if (DXUTIsKeyDown(VK_UP))
			{
				MovingTime += deltaTime;
				if (MovingTime > 0.1f)
				{
					CreatedObj->transform->position.y += 0.235f;
					MovingTime = 0.0f;
				}
			}
			if (DXUTIsKeyDown(VK_DOWN))
			{
				MovingTime += deltaTime;
				if (MovingTime > 0.1f)
				{
					CreatedObj->transform->position.y -= 0.235f;
					MovingTime = 0.0f;
				}
			}
		}
		else
		{
			if (DXUTIsKeyDown(VK_UP))
			{
				MovingTime += deltaTime;
				if (MovingTime > 0.1f)
				{
					CreatedObj->transform->position.z += 0.265f;
					MovingTime = 0.0f;
				}

			}
			if (DXUTIsKeyDown(VK_DOWN))
			{
				MovingTime += deltaTime;
				if (MovingTime > 0.1f)
				{
					CreatedObj->transform->position.z -= 0.265f;
					MovingTime = 0.0f;
				}
			}
		}
	}
}

void TestScene::SetObectButtons()
{
	for (int i = 0; i < IngameObjList.size(); i++)
	{
		if (IngameObjList[i]->GetComponent<Button>().OnClick())
		{
			for (int j = 0; j < IngameObjList.size(); j++)
			{
				if(j != i)
					IngameObjList[j]->isSelected = false;
			}
			IngameObjList[i]->isSelected = !IngameObjList[i]->isSelected;
		}
	}
}

void TestScene::MoveIngameObj(float deltaTime)
{
	for (int i = 0; i < IngameObjList.size(); i++)
	{
		GameObject* obj = IngameObjList[i]->isSelected ? IngameObjList[i]->selectedObject : nullptr;
		if (obj != nullptr)
		{
			if (DXUTWasKeyPressed(VK_LEFT) || DXUTWasKeyPressed(VK_RIGHT) || DXUTWasKeyPressed(VK_UP) || DXUTWasKeyPressed(VK_DOWN))
				MovingTime = 0.1f;

			if (DXUTIsKeyDown(VK_MENU)) // LAlt
			{
				if (DXUTIsKeyDown(VK_LEFT))
				{
					MovingTime += deltaTime;
					if (MovingTime > 0.1f)
					{
						obj->transform->rotation.x -= 15;
						MovingTime = 0.0f;
					}
				}
				else if (DXUTIsKeyDown(VK_RIGHT))
				{
					MovingTime += deltaTime;
					if (MovingTime > 0.1f)
					{
						obj->transform->rotation.x += 15;
						MovingTime = 0.0f;
					}
				}
				if (DXUTIsKeyDown(VK_LCONTROL))
				{
					if (DXUTIsKeyDown(VK_UP))
					{
						MovingTime += deltaTime;
						if (MovingTime > 0.1f)
						{
							obj->transform->rotation.y -= 15;
							MovingTime = 0.0f;
						}
					}
					else if (DXUTIsKeyDown(VK_DOWN))
					{
						MovingTime += deltaTime;
						if (MovingTime > 0.1f)
						{
							obj->transform->rotation.y += 15;
							MovingTime = 0.0f;
						}
					}
				}
				else
				{
					if (DXUTIsKeyDown(VK_UP))
					{
						MovingTime += deltaTime;
						if (MovingTime > 0.1f)
						{
							obj->transform->rotation.z -= 15;
							MovingTime = 0.0f;
						}
					}
					else if (DXUTIsKeyDown(VK_DOWN))
					{
						MovingTime += deltaTime;
						if (MovingTime > 0.1f)
						{
							obj->transform->rotation.z += 15;
							MovingTime = 0.0f;
						}
					}
				}
			}
			else
			{
				if (DXUTIsKeyDown(VK_LEFT))
				{
					MovingTime += deltaTime;
					if (MovingTime > 0.1f)
					{
						obj->transform->position.x -= 0.265f;
						MovingTime = 0.0f;
					}
				}
				else if (DXUTIsKeyDown(VK_RIGHT))
				{
					MovingTime += deltaTime;
					if (MovingTime > 0.1f)
					{
						obj->transform->position.x += 0.265f;
						MovingTime = 0.0f;
					}
				}

				if (DXUTIsKeyDown(VK_LCONTROL))
				{
					if (DXUTIsKeyDown(VK_UP))
					{
						MovingTime += deltaTime;
						if (MovingTime > 0.1f)
						{
							obj->transform->position.y += 0.235f;
							MovingTime = 0.0f;
						}
					}
					if (DXUTIsKeyDown(VK_DOWN))
					{
						MovingTime += deltaTime;
						if (MovingTime > 0.1f)
						{
							obj->transform->position.y -= 0.235f;
							MovingTime = 0.0f;
						}
					}
				}
				else
				{
					if (DXUTIsKeyDown(VK_UP))
					{
						MovingTime += deltaTime;
						if (MovingTime > 0.1f)
						{
							obj->transform->position.z += 0.265f;
							MovingTime = 0.0f;
						}

					}
					if (DXUTIsKeyDown(VK_DOWN))
					{
						MovingTime += deltaTime;
						if (MovingTime > 0.1f)
						{
							obj->transform->position.z -= 0.265f;
							MovingTime = 0.0f;
						}
					}
				}
			}
		}
	}
}

void TestScene::DeleteIngameObj()
{
	for (int i = 0; i < IngameObjList.size(); i++)
	{
		GameObject* obj = IngameObjList[i]->isSelected ? IngameObjList[i]->selectedObject : nullptr;
		if (obj != nullptr)
		{
			if (DXUTWasKeyPressed(VK_DELETE))
			{
				ObjectManager::Instance()->Destroy(IngameObjList[i]);
				//ObjectManager::Instance()->Destroy(obj);
				//ObjectManager::Instance()->Destroy(IngameObjList[i]->middleCircle);
				vector<IngameObject*> newObjlist;
				for (int j = 0; j < IngameObjList.size(); j++)
				{
					if (j == i)
						continue;
					newObjlist.push_back(IngameObjList[j]);
				}
				IngameObjList.clear();
				IngameObjList = { newObjlist.begin(), newObjlist.end() };
				for (int j = 0; j < IngameObjList.size(); j++)
				{
					IngameObjList[j]->transform->position = D3DXVECTOR3(1235, 100 + (20 * j), 0);
				}
			}
		}
	}
}
