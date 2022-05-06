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
	//testObject->AddComp(new Transform);
	AddObj(testObject);
	testObject2 = new GameObject();
	testObject2->AddComp(new MeshRenderer(L"Resources/Mesh/SphereWithTangent.x", L"ColorMaterial"));
	AddObj(testObject2);

}

void TestScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);
	//if (testObject->GetComp(new Transform)->name == L"Transform")
	//	cout << "¾ßÈ£" << endl;

	//testObject2->tranform->position->x -= deltaTime;
	//testObject->tranform->position->x += deltaTime;
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
