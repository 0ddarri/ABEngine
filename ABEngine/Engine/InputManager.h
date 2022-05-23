#pragma once
#include "Singleton.h"
#include "Cursor.h"

class InputManager : public Singleton<InputManager>
{
private:
public:
	bool OnMouseDown = false;
	bool OnMouse = false;
	bool OnMouseUp = false;

	void InputUpdate();

	Cursor* cursor = new Cursor();
};

