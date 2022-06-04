#include "DXUT.h"
#include "MeshRenderer.h"

MeshRenderer::MeshRenderer()
{
	color = { 1,1,1,1 };
	name = L"MeshRenderer";
	mesh = new Mesh();
	material = MaterialManager::Instance()->GetMaterial(L"ColorMaterial");

	meshPath = L"";
	materialName = L"ColorMaterial";
}

MeshRenderer::MeshRenderer(wstring path, wstring matName)
{
	color = { 1,1,1,1 };
	name = L"MeshRenderer";
	mesh = new Mesh(path);
	material = MaterialManager::Instance()->GetMaterial(matName);
	meshPath = path;
	materialName = matName;
}

void MeshRenderer::Init(GameObject* p)
{
	Component::Init(p);
}

void MeshRenderer::Update(float deltaTime)
{
}

void MeshRenderer::Refresh(wstring path, wstring matName)
{
	if (mesh != nullptr)
		mesh->Exit();
	mesh = new Mesh(path);
	meshPath = path;
	material = MaterialManager::Instance()->GetMaterial(matName);
	materialName = matName;
}

void MeshRenderer::Render()
{
	material->Render(this);
}

void MeshRenderer::Exit()
{	
	mesh->Exit();
}
