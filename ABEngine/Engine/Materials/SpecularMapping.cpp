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

	D3DXVECTOR3 lightPos = LightManager::Instance()->pointLightList[0]->parent->transform->position;
	D3DXVECTOR4 lightPos1 = D3DXVECTOR4(lightPos.x, lightPos.y, lightPos.z, 1.0f);
	shader->SetVector((D3DXHANDLE)"gLightPosition1", &lightPos1);
	shader->SetFloat((D3DXHANDLE)"lightRange", LightManager::Instance()->pointLightList[0]->range);
	shader->SetFloat((D3DXHANDLE)"lightEndRange", LightManager::Instance()->pointLightList[0]->fallOffRange);
	//shader->SetVector((D3DXHANDLE)"gWorldLightPosition", &lightPos3);
	//shader->SetVector((D3DXHANDLE)"gWorldLightPosition", &lightPos4);
	D3DXVECTOR3 camPos3 = CameraManager::Instance()->GetCurCamera()->parent->transform->position;
	D3DXVECTOR4 camPos4(camPos3.x, camPos3.y, camPos3.z, 1.0f);
	shader->SetVector((D3DXHANDLE)"gWorldCameraPosition", &camPos4);

	shader->SetVector((D3DXHANDLE)"gLightColor", &LightManager::Instance()->pointLightList[0]->color);
	shader->SetVector((D3DXHANDLE)"gObjectColor", &m->color);
	shader->SetTexture((D3DXHANDLE)"DiffuseMap", albedo->GetTexture());
	shader->SetTexture((D3DXHANDLE)"SpecularMap", specular->GetTexture());
	shader->SetTexture((D3DXHANDLE)"NormalMap", normal->GetTexture());
	shader->SetFloat((D3DXHANDLE)"gSpecularPower", 1.0f);

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
