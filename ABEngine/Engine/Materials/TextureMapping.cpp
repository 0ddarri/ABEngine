#include "DXUT.h"
#include "TextureMapping.h"

TextureMapping::TextureMapping()
{
	Init();
	texture = TextureManager::Instance()->GetTexture(L"Ground_Albedo");
}

TextureMapping::TextureMapping(wstring texName)
{
	Init();
	texture = TextureManager::Instance()->GetTexture(texName);
}

void TextureMapping::Init()
{
	shader = LoadShader(L"Resources/Shader/TextureMapping.fx");
	name = L"TextureMapping";
	D3DXMatrixIdentity(&world);
	D3DXMatrixIdentity(&view);
	D3DXMatrixIdentity(&proj);
}

void TextureMapping::Render(MeshRenderer* m)
{
	world = m->parent->transform->GetWorldMatrix();
	view = CameraManager::Instance()->GetCurCamera()->viewMat;
	proj = CameraManager::Instance()->GetCurCamera()->projMat;

	shader->SetMatrix((D3DXHANDLE)"gWorldMatrix", &world);
	shader->SetMatrix((D3DXHANDLE)"gViewMatrix", &view);
	shader->SetMatrix((D3DXHANDLE)"gProjectionMatrix", &proj);
	shader->SetTexture((D3DXHANDLE)"DiffuseMap_Tex", texture->GetTexture());

	UINT numPass = 0;
	shader->Begin(&numPass, NULL);
	for (UINT i = 0; i < numPass; i++)
	{
		shader->BeginPass(i);
		m->mesh->mesh->DrawSubset(0);
		shader->EndPass();
	}
	shader->End();
}

void TextureMapping::Exit()
{
}
