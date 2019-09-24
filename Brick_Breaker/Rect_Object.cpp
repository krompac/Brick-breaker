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
}

void Rect_Object::SetXpos(int value)
{
	rect->x = value;
}

void Rect_Object::DrawMe()
{
	DrawRectangleRec(*rect, color);
}

Rect_Object::~Rect_Object()
{
	std::cout << "Rect obj deleted" << std::endl;
	delete rect;
}
