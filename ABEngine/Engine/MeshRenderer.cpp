#include "DXUT.h"
#include "MeshRenderer.h"

MeshRenderer::MeshRenderer()
{
	name = L"MeshRenderer";
	mesh = new Mesh();
}

MeshRenderer::MeshRenderer(wstring path)
{
	mesh = new Mesh(path);
}

void MeshRenderer::Init()
{
}

void MeshRenderer::Update(float deltaTime)
{
}

void MeshRenderer::Render()
{
	mesh->mesh->DrawSubset(0);
}

void MeshRenderer::Exit()
{
	mesh->Exit();
}
