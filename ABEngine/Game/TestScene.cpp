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

	testObject = new GameObject();
	testObject->AddComp(new Transform);
	AddObj(testObject);
}

void TestScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);
	//if (testObject->GetComp(new Transform)->name == L"Transform")
	//	cout << "¾ßÈ£" << endl;
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
