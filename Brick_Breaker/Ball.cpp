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

	directionChanged = false;
}

void Ball::Move()
{
	/*if (IsMouseButtonDown(0))
	{
		center = GetMousePosition();
	}*/

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

	if (returnMe && !directionChanged)
	{
		int x = center.x;
		int y = center.y;
		int rectZ = rect.y + rect.height;

		if (CheckCollisionPointBall(rect.x, rect.y))
		{
			goingRight = false;
			goingUp = true;
		}
		else if (CheckCollisionPointBall(rect.x + rect.width, rect.y))
		{
			goingRight = true;
			goingUp = true;
		}
		else if (CheckCollisionPointBall(rect.x, rect.y + rect.height))
		{
			goingRight = false;
			goingUp = false;
		}
		else if (CheckCollisionPointBall(rect.x + rect.width, rect.y + rect.height))
		{
			goingRight = true;
			goingUp = false;
		}
		else if ((int)y > rect.y && y < rectZ)
		{
			if (goingRight && center.x + radius >= rect.x)
			{
				std::cout << "LEVO" << std::endl;
				goingRight = false;
			}
			else if (!goingRight && center.x - radius <= (rect.x + rect.width))
			{
				goingRight = true;
				std::cout << "DESNO" << std::endl;
			}
		}
		else
		{
			if (x >= rect.x && x <= rect.x + rect.width)
			{
				if (!goingUp && center.y + radius >= rect.y && center.y + radius < rect.y + rect.height)
				{
					std::cout << "GORE" << std::endl;
					goingUp = true;
				}
				else if (goingUp && center.y - radius <= rect.y + rect.height)
				{
					std::cout << "DOLE" << std::endl;
					goingUp = false;
				}
			}
		}

		directionChanged = true;
	}

	return returnMe;
}

bool Ball::CheckCollisionPointBall(int x, int y)
{
	auto point = Vector2();
	point.x = x;
	point.y = y;

	return CheckCollisionPointCircle(point, center, radius);
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
		speed.x = (int)speed.x;
		speed.y = (int)speed.y;

		center.y = rect.y - radius;
	}
}

void Ball::CheckCollisionWithBricks(std::vector<Brick*>& rects)
{
	auto destroyCounter = 0;
	directionChanged = false;
	for (int i = 0; i < rects.size(); i++)
	{
		if (!rects[i]->IsDisabled() && CheckColisionWithRect(*(rects[i]->getRect())))
		{
			rects[i]->DestroyMe();
			destroyCounter++;
		}
	}

	if (destroyCounter > 0)
	std::cout << "DESTROY COUNTER: " << destroyCounter << std::endl;
}

Ball::~Ball()
{
}
