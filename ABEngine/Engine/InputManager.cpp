#include "DXUT.h"
#include "InputManager.h"

void InputManager::InputUpdate()
{
	if (OnMouseDown)
	{
		OnMouseDown = false;
		OnMouseUp = false;
		OnMouse = true;
	}
	if (OnMouseUp)
	{
		OnMouseDown = false;
		OnMouse = false;
		OnMouseUp = false;
	}

	GetCursorPos(&cursor->p);
	ScreenToClient(DXUTGetHWND(), &cursor->p);
}
