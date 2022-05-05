#include "DXUT.h"
#include "Mesh.h"

void Mesh::Initialize()
{
	auto isFail = D3DXLoadMeshFromX(L"Resources/mesh/SphereWithTangent.x", D3DXMESH_MANAGED, DEVICE, nullptr, nullptr, nullptr, nullptr, &originalMesh);
	if (FAILED(isFail))
		cout << "OriginMesh Failed" << endl;
}

Mesh::Mesh()
{
	Initialize();
}

Mesh::Mesh(wstring path)
{
	Initialize();
	SetMesh(path);
}

void Mesh::SetMesh(wstring path)
{
	auto isFail = D3DXLoadMeshFromX(path.c_str(), D3DXMESH_MANAGED, DEVICE, nullptr, nullptr, nullptr, nullptr, &mesh);
	if (FAILED(isFail))
	{
		wcout << "Mesh Load Fail! : " << path.c_str() << endl;
		mesh = originalMesh;
		return;
	}
	wcout << "Mesh Load Success! : " << path.c_str() << endl;
}

void Mesh::Exit()
{
	if(originalMesh)
		originalMesh->Release();
	if(mesh != NULL)
		mesh->Release();
}