#include <iostream>
#include <thread>
#include <chrono>

#include "raylib.h"
#include "Pad.h"
#include "Ball.h"

void sleep()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	auto pad = new Pad(0, 430, 100, 20, BLACK);
	auto ball = new Ball(707, 40, 5, ORANGE);

	std::vector<Brick*> bricks;

	int xPos = 75;
	int yPos = 30;
	int diff = 52;

	for (int i = 0; i < 60; i++)
	{
		bricks.push_back(new Brick(xPos, yPos, 51, 25, BLACK));
		xPos += diff;

		if (bricks.size() % 12 == 0)
		{
			xPos = 75;
			yPos += 26;
		}
	}
	
	InitWindow(screenWidth, screenHeight, "Brick Breaker");
	DisableCursor();

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);
		DrawRectangle(0, 0, 50, screenHeight, GRAY);
		DrawRectangle(screenWidth - 50, 0, 50, screenHeight, GRAY);

		pad->DrawMe();
		pad->Move();

		ball->DrawMe();
		ball->Move();

		for (auto brick : bricks)
		{
			brick->DrawMe();
		}

		ball->CheckCollisionWithPad(pad);
		ball->CheckCollisionWithBricks(bricks);

		EndDrawing();

		sleep();

		if (IsKeyDown(KEY_ESCAPE))
		{
			break;
		}
	}

	CloseWindow();

	delete ball;
	delete pad;

	for (auto brick : bricks)
	{
		delete brick;
	}

	system("Pause");

	return 0;
}