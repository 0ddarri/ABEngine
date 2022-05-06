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
	D3DXMATRIXA16 viewMat;
	//DEVICE->GetTransform(D3DTS_VIEW, &viewMat);
	D3DXVECTOR3 vEyePt(0.0f, 0.0f, -200.0f);
	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&viewMat, &vEyePt, &vLookatPt, &vUpVec);

	D3DXMATRIXA16 projMat;
	//DEVICE->GetTransform(D3DTS_PROJ, &projMat);
	D3DXMatrixPerspectiveFovLH(&projMat, FOV, ASPECT_RATIO, NEAR_PLANE, FAR_PLANE);

	D3DXMATRIXA16 worldMat = m->parent->transform->GetWorldMatrix();

	shader->SetMatrix((D3DXHANDLE)"gWorldMatrix", &worldMat);
	shader->SetMatrix((D3DXHANDLE)"gViewMatrix", &viewMat);
	shader->SetMatrix((D3DXHANDLE)"gProjectionMatrix", &projMat);

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
