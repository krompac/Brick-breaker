#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(int x, int y, float radius, Color color) : Game_Object(x, y, radius, 0, color)
{
	center.x = x;
	center.y = y;
	this->radius = radius;

	moveDirection.x = 2;
	moveDirection.y = 5;

	isReleased = false;
}

void Ball::Move()
{
	center.x += moveDirection.x;
	center.y += moveDirection.y;

	if (center.x <= 50)
	{
		center.x = 50;
		moveDirection.x *= -1;
	}
	else if (center.x + radius >= GetScreenWidth() - 50)
	{
		center.x = GetScreenWidth() - 50 - radius;
		moveDirection.x *= -1;
	}

	if (center.y - radius <= 0)
	{
		center.y = radius;
		moveDirection.y *= -1;
	}
	else if (center.y + radius >= GetScreenHeight())
	{
		center.y = GetScreenHeight() - radius;
		moveDirection.y *= -1;
	}
}

bool Ball::CheckColisionWithRect(Rectangle rect)
{
	bool returnMe = CheckCollisionCircleRec(center, radius, rect);

	if (returnMe)
	{
		if (center.x + radius <= rect.x)
		{
			std::cout << "LEVO" << std::endl;
			if (moveDirection.x < 0)
			{
				moveDirection.x *= -1;
			}
		}
		else if (center.x - radius >= rect.x + rect.width)
		{
			std::cout << "DESNO" << std::endl;
			if (moveDirection.x > 0)
			{
				moveDirection.x *= -1;
			}
		}
		else if (center.y + radius <= rect.y)
		{
			if (moveDirection.y > 0)
			{
				moveDirection.y *= -1;
			}
		}
		else if (center.y - radius <= rect.y + rect.height)
		{
			if (moveDirection.y < 0)
			{
				moveDirection.y *= -1;
			}
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

		moveDirection.y *= -1;

		moveDirection.x = (center.x - rectCenter) / 20;
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
