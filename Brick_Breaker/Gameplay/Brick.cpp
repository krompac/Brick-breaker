#include "Brick.h"

bool Brick::checkNeighbour(Brick * brick)
{
	return brick || brick->IsDisabled();;
}

Brick::Brick()
{
}

Brick::Brick(int x, int y, int width, int height, Color color) : Rect_Object(x, y, width, height, color)
{
	upperBrick = nullptr;
	rightBrick = nullptr;
	lowerBrick = nullptr;
	leftBrick = nullptr;

	isDisabled = false;
	numberOfActiveBricks++;
}

bool Brick::IsDisabled()
{
	return isDisabled;
}

bool Brick::IsBreakable()
{
	return checkNeighbour(upperBrick) || checkNeighbour(rightBrick) || checkNeighbour(lowerBrick) || checkNeighbour(leftBrick);
}

void Brick::DisableMe()
{
	if (!isDisabled)
	{
		isDisabled = true;
		numberOfActiveBricks--;
	}
}

std::vector<Brick*> Brick::GetNeighbourBreakableBricks()
{
	auto returnMe = std::vector<Brick*>();

	auto addBrickForReturn = [](Brick *brick, std::vector<Brick*> &returnValue)
	{
		if (brick && brick->IsBreakable())
		{
			returnValue.push_back(brick);
		}
	};

	addBrickForReturn(upperBrick, returnMe);
	addBrickForReturn(rightBrick, returnMe);
	addBrickForReturn(lowerBrick, returnMe);
	addBrickForReturn(leftBrick, returnMe);

	return returnMe;
}

void Brick::SetBrick(Side side, Brick *brick)
{
	switch (side)
	{
		case UP:
			this->upperBrick = brick;
			break;
		case RIGHT:
			this->rightBrick = brick;
			break;
		case DOWN:
			this->lowerBrick = brick;
			break;
		case LEFT:
			this->leftBrick = brick;
			break;
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