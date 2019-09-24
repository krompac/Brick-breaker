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

	Vector2 moveDirection;
	bool isReleased;

	bool CheckColisionWithRect(Rectangle rect);

public:
	Ball();
	Ball(int x, int y, float radius, Color color);

	void Move();
	void DrawMe();

	void CheckCollisionWithPad(Pad *pad);
	void CheckCollisionWithBricks(std::vector<Brick*> &rects);

	~Ball();
};

