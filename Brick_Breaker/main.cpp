#include <iostream>
#include <thread>
#include <chrono>

#include "raylib.h"
#include "Rect_Object.h"

void sleep()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	int x = 0;
	auto test = Rect_Object(x, 200, 100, 50, BLACK);

	int currX = GetMouseX();
	int diff = 0;

	InitWindow(screenWidth, screenHeight, "Brick Breaker");
	DisableCursor();

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);
		test.SetXpos(x);
		test.DrawMe();

		EndDrawing();

		diff = GetMouseX() - currX;
		currX = GetMouseX();

		if (x + 100 + diff <= GetScreenWidth() && diff >= 0)
		{
			x += diff;
		}
		else if (x + diff >= 0 && diff <= 0)
		{
			x += diff;
		}

		sleep();

		if (IsKeyDown(KEY_ESCAPE))
		{
			break;
		}
	}

	CloseWindow();

	return 0;
}