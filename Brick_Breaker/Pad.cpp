#include "Pad.h"

Pad::Pad()
{
}

Pad::Pad(int x, int y, int width, int height, Color color) : Rect_Object(x, y, width, height, color)
{
	xPosDifference = 0;
	currentMouseX = x;
}

void Pad::Move()
{
	xPosDifference = GetMouseX() - currentMouseX;
	currentMouseX = GetMouseX();

	if (x + 100 + xPosDifference <= (GetScreenWidth() - 50) && xPosDifference >= 0)
	{
		x += xPosDifference;
	}
	else if (x + xPosDifference >= 50 && xPosDifference <= 0)
	{
		x += xPosDifference;
	}

	this->SetXpos(x);
}

Pad::~Pad()
{
}
