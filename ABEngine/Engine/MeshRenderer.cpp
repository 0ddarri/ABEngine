#include "DXUT.h"
#include "MeshRenderer.h"

MeshRenderer::MeshRenderer()
{
	name = L"MeshRenderer";
	mesh = new Mesh();
	material = MaterialManager::Instance()->GetMaterial(L"ColorMaterial");
}

MeshRenderer::MeshRenderer(wstring path, wstring matName)
{
	name = L"MeshRenderer";
	mesh = new Mesh(path);
	material = MaterialManager::Instance()->GetMaterial(matName);
}

void MeshRenderer::Init(GameObject* p)
{
	Component::Init(p);
}

void MeshRenderer::Update(float deltaTime)
{
}

void MeshRenderer::Render()
{
	material->Render(this);
}

void MeshRenderer::Exit()
{
	mesh->Exit();
}
