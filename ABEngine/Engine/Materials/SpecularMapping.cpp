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
	shader = LoadShader(L"Resources/Shader/defaultShader.fx");
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

	D3DXVECTOR4 lightPos1 = D3DXVECTOR4(0, 10, 0, 1.0f);
	D3DXVECTOR4 lightPos2 = D3DXVECTOR4(0, 10, 0, 1.0f);
	D3DXVECTOR4 lightPos3 = D3DXVECTOR4(10, 0, 10, 1.0f);
	D3DXVECTOR4 lightPos4 = D3DXVECTOR4(0, 0, 10, 1.0f);
	shader->SetVector((D3DXHANDLE)"gLightPosition1", &lightPos1);
	shader->SetVector((D3DXHANDLE)"gLightPosition2", &lightPos2);
	shader->SetFloat((D3DXHANDLE)"lightRange", 10.0f);
	shader->SetFloat((D3DXHANDLE)"lightEndRange", 20.0f);
	//shader->SetVector((D3DXHANDLE)"gWorldLightPosition", &lightPos3);
	//shader->SetVector((D3DXHANDLE)"gWorldLightPosition", &lightPos4);
	D3DXVECTOR3 camPos3 = *CameraManager::Instance()->GetCurCamera()->parent->transform->position;
	D3DXVECTOR4 camPos4(camPos3.x, camPos3.y, camPos3.z, 1.0f);
	shader->SetVector((D3DXHANDLE)"gWorldCameraPosition", &camPos4);

	D3DXVECTOR4 lightcolor(1, 1, 1, 1);
	shader->SetVector((D3DXHANDLE)"gLightColor", &lightcolor);
	shader->SetTexture((D3DXHANDLE)"DiffuseMap", albedo->GetTexture());
	shader->SetTexture((D3DXHANDLE)"SpecularMap", specular->GetTexture());
	shader->SetTexture((D3DXHANDLE)"NormalMap", normal->GetTexture());

	float A, B, Alpha;
	A = 0;
	B = 100;
	Alpha = 0.5;
	cout << A * (1 - Alpha) + B * Alpha << endl;

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
