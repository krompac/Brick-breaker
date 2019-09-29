#include <iostream>
#include <thread>
#include <chrono>

#include "raylib.h"
#include "Gameplay_Window.h"

void sleep()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "Brick Breaker");
	DisableCursor();

	auto gameplay = new Gameplay_Window();

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		gameplay->HandleMe();
		
		EndDrawing();

		sleep();

		if (IsKeyDown(KEY_ESCAPE))
		{
			break;
		}
	}

	CloseWindow();

	system("Pause");

	return 0;
}