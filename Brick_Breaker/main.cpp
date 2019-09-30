#include <iostream>
#include <thread>
#include <chrono>

#include "raylib.h"
#include "Gameplay_Window.h"
#include "Menu_Window.h"
#include "Current_Window.h"
#include "Button.h"

void sleep()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

void print()
{
	std::cout << "BUTTON CLICK" << std::endl;
}

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	
	Current_Window window = Lobby;

	InitWindow(screenWidth, screenHeight, "Brick Breaker");
	//DisableCursor();

	Window *active = nullptr;
	auto gameplay = new Gameplay_Window();
	auto menu = new Menu_Window();
	Color color = RED;
	const char *text = "BUTTON";
	auto nekaj = new Button(400, 400, 100, 50, color, text, print);

	active = gameplay;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		active->DrawMe();
		active->HandleMe();
		nekaj->DrawMe();
		nekaj->CheckIfClicked();
		
		EndDrawing();

		sleep();

		if (IsKeyDown(KEY_ESCAPE))
		{
			break;
		}
	}

	CloseWindow();

	delete nekaj;
	delete menu;
	delete gameplay;

	system("Pause");

	return 0;
}