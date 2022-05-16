#include "DXUT.h"
#include "SpecularMapping.h"

SpecularMapping::SpecularMapping()
{
	Init();
	albedo = TextureManager::Instance()->GetTexture(L"Wall_Albedo");
	specular = TextureManager::Instance()->GetTexture(L"Wall_Specular");
	normal = TextureManager::Instance()->GetTexture(L"Wall_Normal");
}

SpecularMapping::SpecularMapping(wstring albedo, wstring specular, wstring normal)
{
	Init();
	this->albedo = TextureManager::Instance()->GetTexture(albedo);
	this->specular = TextureManager::Instance()->GetTexture(specular);
	this->normal = TextureManager::Instance()->GetTexture(normal);
}

void SpecularMapping::Init()
{
	shader = LoadShader(L"Resources/Shader/NormalMapping.fx");
	name = L"defaultMaterial";
}

void SpecularMapping::Render(MeshRenderer* m)
{
	D3DXMATRIXA16 matWorld = m->parent->transform->GetWorldMatrix();
	D3DXMATRIXA16 matView = CameraManager::Instance()->GetCurCamera()->viewMat;
	D3DXMATRIXA16 matProj = CameraManager::Instance()->GetCurCamera()->projMat;

	D3DXMATRIXA16 matWorldView;
	D3DXMATRIXA16 matWorldViewProj;
	D3DXMatrixMultiply(&matWorldView, &matWorld, &matView);
	D3DXMatrixMultiply(&matWorldViewProj, &matWorldView, &matProj);

	shader->SetMatrix((D3DXHANDLE)"gWorldMatrix", &matWorld);
	shader->SetMatrix((D3DXHANDLE)"gWorldViewProjectionMatrix", &matWorldViewProj);

	D3DXVECTOR4 lightPos(0, 0, 0, 1.0f);
	shader->SetVector((D3DXHANDLE)"gWorldLightPosition", &lightPos);
	D3DXVECTOR3 camPos3 = *CameraManager::Instance()->GetCurCamera()->parent->transform->position;
	D3DXVECTOR4 camPos4(camPos3.x, camPos3.y, camPos3.z, 1.0f);
	shader->SetVector((D3DXHANDLE)"gWorldCameraPosition", &camPos4);

	D3DXVECTOR4 lightcolor(1, 1, 1, 1);
	shader->SetVector((D3DXHANDLE)"gLightColor", &lightcolor);
	shader->SetTexture((D3DXHANDLE)"DiffuseMap_Tex", albedo->GetTexture());
	shader->SetTexture((D3DXHANDLE)"SpecularMap_Tex", specular->GetTexture());
	shader->SetTexture((D3DXHANDLE)"NormalMap_Tex", normal->GetTexture());

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

void SpecularMapping::Exit()
{
}
