#include "DXUT.h"
#include "Material.h"

Material::Material()
{
}

LPD3DXEFFECT Material::LoadShader(wstring path)
{
	LPD3DXEFFECT shader;

	auto isFail = D3DXCreateEffectFromFile(DEVICE, path.c_str(), NULL, NULL, 0, NULL, &shader, NULL);
	if (FAILED(isFail))
	{
		wcout << "Shader Load Fail : " << path.c_str() << endl;
		shader->Release();
		return nullptr;
	}
	wcout << "Shader Load Success! : " << path.c_str() << endl;
	return shader;
}

void Material::Initialize()
{
}

void Material::Exit()
{
	shader->Release();
}
