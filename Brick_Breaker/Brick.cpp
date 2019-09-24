#include "Brick.h"

Brick::Brick()
{
}

Brick::Brick(int x, int y, int width, int height, Color color) : Rect_Object(x, y, width, height, color)
{
	isDisabled = false;
}

void Brick::DestroyMe()
{
	isDisabled = true;
}

void Brick::DrawMe()
{
	if (!isDisabled)
	{
		Rect_Object::DrawMe();
	}
}

bool Brick::IsDisabled()
{
	return isDisabled;
}

Brick::~Brick()
{
}
