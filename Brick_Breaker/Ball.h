#pragma once
#include <vector>

#include "Game_Object.h"
#include "Moveable_Object.h"
#include "Pad.h"
#include "Brick.h"

class Ball : public Game_Object, public Moveable_Object
{
	private:
		Vector2 center;
		float radius;

		int startingBallSpeed;
		Vector2 speed;

		bool isReleased;
		bool goingRight;
		bool goingUp;

		bool directionChanged;

		bool CheckColisionWithRect(Rectangle rect);
		bool CheckCollisionPointBall(int x, int y);

	public:
		Ball();
		Ball(int x, int y, float radius, Color color);

		void Move();
		void DrawMe();

		void CheckCollisionWithPad(Pad *pad);
		void CheckCollisionWithBricks(std::vector<Brick*> &bricks);

		~Ball();
};

