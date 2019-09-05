#include <iostream>
#include <thread>
#include <chrono>

#include "raylib.h"

void sleep()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Brick Breaker");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		EndDrawing();
		sleep();
	}

	CloseWindow();

	return 0;
}