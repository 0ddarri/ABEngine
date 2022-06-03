#include "DXUT.h"
#include "ColorMat.h"

ColorMat::ColorMat()
{
	Init();
}

ColorMat::ColorMat(D3DXMATRIXA16 v, D3DXMATRIXA16 p, D3DXMATRIXA16 w)
{
	Init();
	view = v;
	proj = p;
	world = w;
}

void ColorMat::Init()
{
	shader = LoadShader(L"Resources/Shader/ColorShader.fx");
	name = L"ColorMaterial";
	D3DXMatrixIdentity(&view);
	D3DXMatrixIdentity(&proj);
	D3DXMatrixIdentity(&world);
}

void ColorMat::Render(MeshRenderer* m)
{
	world = m->parent->transform->GetWorldMatrix();
	view = CameraManager::Instance()->GetCurCamera()->viewMat;
	proj = CameraManager::Instance()->GetCurCamera()->projMat;

	shader->SetMatrix((D3DXHANDLE)"gWorldMatrix", &world);
	shader->SetMatrix((D3DXHANDLE)"gViewMatrix", &view);
	shader->SetMatrix((D3DXHANDLE)"gProjectionMatrix", &proj);
	shader->SetVector((D3DXHANDLE)"gColor", &m->color);

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

void ColorMat::Exit()
{
	Material::Exit();
}
