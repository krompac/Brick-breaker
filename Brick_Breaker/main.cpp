#include <iostream>
#include <thread>
#include <chrono>

#include "raylib.h"
#include "Gameplay_Window.h"
#include "Menu_Window.h"
#include "Current_Window.h"
#include "Button.h"

Current_Window window = Lobby;

Window *active = nullptr;
Gameplay_Window *gameplay = nullptr;
Menu_Window *menu = nullptr;

bool quit = false;

void sleep()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Brick Breaker");
	SetExitKey(KEY_F1);

	auto toGame = [] { active = gameplay; DisableCursor(); };
	auto toMenu = [] {active = menu; EnableCursor(); };
	auto quitGame = [] {quit = true; };
	auto resume = [] {};
	
	gameplay = new Gameplay_Window(toMenu);
	menu = new Menu_Window(toGame, toMenu, resume, quitGame);

	Color color = RED;
	const char *text = "BUTTON";
	auto button = new Button(400, 400, 100, 50, color, text, sleep);

	active = menu;

	while (!WindowShouldClose() && !quit)
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		active->DrawMe();
		active->HandleMe();
		
		EndDrawing();

		sleep();
	}

	CloseWindow();

	delete button;
	delete menu;
	delete gameplay;

	system("Pause");

	return 0;
}