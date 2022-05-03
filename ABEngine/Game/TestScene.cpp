#include "DXUT.h"
#include "TestScene.h"

TestScene::TestScene(wstring n)
{
	name = n;
}

void TestScene::Init()
{
	cout << "Init" << endl;
}

void TestScene::Update()
{
}

void TestScene::Render()
{
}

void TestScene::Exit()
{
	cout << "Exit" << endl;
}
