#include <math.h>
#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(int x, int y, float radius, Color color) : Game_Object(x, y, radius, 0, color)
{
	center.x = x;
	center.y = y;
	this->radius = radius;

	startingBallSpeed = 5;
	speed.x = 2;
	speed.y = startingBallSpeed;

	isReleased = false;

	goingRight = true;
	goingUp = false;
}

void Ball::Move()
{
	if (goingRight)
	{
		center.x += speed.x;

		if (center.x + radius >= GetScreenWidth() - 50)
		{
			center.x = GetScreenWidth() - 50 - radius;
			goingRight = false;
		}
	}
	else
	{
		center.x -= speed.x;

		if (center.x - radius <= 50)
		{
			center.x = 50;
			goingRight = true;
		}
	}
	
	if (goingUp)
	{
		center.y -= speed.y;

		if (center.y - radius <= 0)
		{
			center.y = radius;
			goingUp = false;
		}
	}
	else
	{
		center.y += speed.y;

		if (center.y + radius >= GetScreenHeight())
		{
			center.y = GetScreenHeight() - radius;
			goingUp = true;
		}
	}
}

bool Ball::CheckColisionWithRect(Rectangle rect)
{
	bool returnMe = CheckCollisionCircleRec(center, radius, rect);

	if (returnMe)
	{
		if (!goingUp && center.y < rect.y && center.y + radius >= rect.y)
		{
			std::cout << "GORE" << std::endl;
			goingUp = true;
			center.y = rect.y - radius;
		}
		else if (goingUp && center.y > rect.y + rect.height && center.y - radius <= rect.y + rect.height)
		{
			std::cout << "DOLE" << std::endl;
			goingUp = false;
			center.y = rect.y + rect.height + radius;
		}
		else if (goingRight && center.x + radius >= rect.x)
		{
			std::cout << "LEVO" << std::endl;
			goingRight = false;

			center.x = rect.x - radius;
		}
		else if (!goingRight && center.x - radius <= rect.x + rect.width)
		{
			goingRight = true;
			std::cout << "DESNO" << std::endl;

			center.x = rect.x + rect.width + radius;
		}
	}

	return returnMe;
}

void Ball::DrawMe()
{
	DrawCircleV(center, radius, color);
}

void Ball::CheckCollisionWithPad(Pad *pad)
{
	auto rect = *(pad->getRect());

	if (CheckCollisionCircleRec(center, radius, rect))
	{
		float rectCenter = rect.x + (rect.width / 2);

		goingUp = true;

		float collision = center.x - rectCenter;
		goingRight = collision >= 0;

		speed.x = abs(collision) / (rect.width / 10);
		speed.y = startingBallSpeed + 1 - (speed.x / startingBallSpeed);

		center.y = rect.y - radius;
	}
}

void Ball::CheckCollisionWithBricks(std::vector<Brick*>& rects)
{
	for (int i = 0; i < rects.size(); i++)
	{
		if (!rects[i]->IsDisabled() && CheckColisionWithRect(*(rects[i]->getRect())))
		{
			rects[i]->DestroyMe();
		}
	}
}

Ball::~Ball()
{
}
