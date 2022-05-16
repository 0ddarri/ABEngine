#pragma once


class Texture
{
private:
	LPDIRECT3DTEXTURE9 texture;
	D3DXIMAGE_INFO info;

protected:
public:
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

