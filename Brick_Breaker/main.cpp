#include <iostream>
#include <thread>
#include <chrono>

#include "raylib.h"
#include "Pad.h"

void sleep()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	int x = 0;
	auto test = new Pad(x, 430, 100, 20, BLACK);

	float currX = GetMouseX();
	float diff = 0;

	InitWindow(screenWidth, screenHeight, "Brick Breaker");
	DisableCursor();

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);
		test->DrawMe();
		test->Move();

		EndDrawing();

		sleep();

		if (IsKeyDown(KEY_ESCAPE))
		{
			break;
		}
	}

	CloseWindow();

	delete test;

	system("Pause");

	return 0;
}