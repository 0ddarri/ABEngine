#include "DXUT.h"
#include "Cursor.h"

D3DXVECTOR2 Cursor::GetMousePosition()
{
	return D3DXVECTOR2((float)p.x, (float)p.y);
}
