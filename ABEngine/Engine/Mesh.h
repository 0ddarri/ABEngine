#pragma once
class Mesh
{
private:
	LPD3DXMESH originalMesh = nullptr;

	void Initialize();
public:
	Mesh();
	Mesh(wstring path);

	void SetMesh(wstring path);

	LPD3DXMESH mesh = nullptr;

	void Exit();
};

