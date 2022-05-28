#include "DXUT.h"
#include "Image.h"

Image::Image()
{
	name = L"Image";
	image = TextureManager::Instance()->GetTexture(L"Ground_Albedo");
	layer = 0;
}

Image::Image(wstring texName)
{
	name = L"Image";
	image = TextureManager::Instance()->GetTexture(texName);
	layer = 0;
}

Image::Image(wstring texName, int l)
{
	name = L"Image";
	image = TextureManager::Instance()->GetTexture(texName);
	layer = l;
}

void Image::Init(GameObject* p)
{
	Component::Init(p);
}

void Image::Update(float deltaTime)
{
}

void Image::Render()
{
	TextureManager::Instance()->Sprite()->Begin(D3DXSPRITE_ALPHABLEND);

	//D3DXMATRIXA16 worldMatrix = parent->transform->GetWorldMatrix();
	//DEVICE->SetTransform(D3DTS_WORLD, &worldMatrix);
	//D3DXMATRIXA16 viewMatrix = CameraManager::Instance()->GetCurCamera()->viewMat;
	//D3DXMATRIXA16 projMatrix = CameraManager::Instance()->GetCurCamera()->projMat;

	//D3DXMATRIXA16 worldviewproj = worldMatrix * viewMatrix * projMatrix;

	//D3DXVECTOR4 worldToScreen(0, 0, 0, 1);
	//D3DXVec4Transform(&worldToScreen, &worldToScreen, &worldviewproj);

	//float worldToScreenX = worldToScreen.x / worldToScreen.w;
	//float worldToScreenY = worldToScreen.y / worldToScreen.w;
	//float worldToScreenZ = worldToScreen.z / worldToScreen.w;

	//float screenNormalX = (worldToScreenX + 1) * 0.5f;
	//float screenNormalY = (worldToScreenY + 1) * 0.5f;
	//screenNormalY = 1.0f - screenNormalY;
	//
	//float screenX = screenNormalX * SCW;
	//float screenY = screenNormalY * SCH;

	TextureManager::Instance()->Sprite()->SetTransform(&parent->transform->GetWorldMatrix());
	D3DXVECTOR3 center(image->info.Width * 0.5f, image->info.Height * 0.5f, 0);
	TextureManager::Instance()->Sprite()->Draw(image->GetTexture(), &image->imgRect, &center, nullptr, D3DXCOLOR(1, 1, 1, 1));
	TextureManager::Instance()->Sprite()->End();
}

void Image::Exit()
{
}
