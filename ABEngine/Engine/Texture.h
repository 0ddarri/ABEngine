#pragma once

class Texture
{
private:

protected:
public:
	D3DXIMAGE_INFO info;
	LPDIRECT3DTEXTURE9 texture;
	RECT imgRect;
	Texture();
	Texture(wstring path);
	Texture(wstring path, wstring name);

	LPDIRECT3DTEXTURE9 SetTexture(wstring path);
	LPDIRECT3DTEXTURE9 SetTexture(LPDIRECT3DTEXTURE9 texture);

	LPDIRECT3DTEXTURE9 GetTexture()
	{
		return texture;
	}

	void Exit();
	wstring name = L"Texture";
};

