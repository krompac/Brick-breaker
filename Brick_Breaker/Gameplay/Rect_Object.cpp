#include "Rect_Object.h"

Rect_Object::Rect_Object()
{
}

Rect_Object::Rect_Object(int x, int y, int width, int height, Color color) : Game_Object(x, y, width, height, color)
{
	rect = new Rectangle();
	rect->x = x;
	rect->y = y;
	rect->width = width;
	rect->height = height;

	isDisabled = false;
}

void Rect_Object::SetXpos(int value)
{
	Game_Object::SetXpos(value);
	rect->x = value;
}

void Rect_Object::SetYpos(int value)
{
	rect->y = value;
}

Rectangle *Rect_Object::getRect()
{
	return rect;
}

void Rect_Object::DrawMe()
{
	if (!isDisabled)
	{
		DrawRectangleRec(*rect, color);
	}
}

void Rect_Object::DisableMe()
{
	if (!isDisabled)
	{
		isDisabled = true;
	}
}


Rect_Object::~Rect_Object()
{
	std::cout << "Rect obj deleted" << std::endl;
	delete rect;
}
