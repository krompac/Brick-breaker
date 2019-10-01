#include "Brick.h"

Brick::Brick()
{
}

Brick::Brick(int x, int y, int width, int height, Color color) : Rect_Object(x, y, width, height, color)
{
	isDisabled = false;
	numberOfActiveBricks++;
}

bool Brick::IsDisabled()
{
	return isDisabled;
}

void Brick::DisableMe()
{
	if (!isDisabled)
	{
		isDisabled = true;
		numberOfActiveBricks--;
	}
}

int Brick::GetNumberOfActiveBricks()
{
	return numberOfActiveBricks;
}

Brick::~Brick()
{
}

int Brick::numberOfActiveBricks = 0;