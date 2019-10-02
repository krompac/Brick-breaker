#include <iostream>
#include <thread>
#include <chrono>

#include "raylib.h"
#include "Gameplay_Window.h"
#include "Menu_Window.h"
#include "Button.h"
#include "Picture.h"

Window *active = nullptr;
Gameplay_Window *gameplay = nullptr;
Menu_Window *menu = nullptr;

bool quit = false;

void sleep()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

void initGameWindows()
{
	auto toGame = [] { active = gameplay; DisableCursor(); };
	auto toMenu = [] {active = menu; EnableCursor(); };
	auto quitGame = [] {quit = true; };
	auto resume = [] {};

	gameplay = new Gameplay_Window(toMenu);
	menu = new Menu_Window(toGame, toMenu, resume, quitGame);
}

void free()
{
	delete gameplay;
	delete menu;
}

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Brick Breaker");
	SetExitKey(KEY_F1);

	initGameWindows();
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

	free();

	system("Pause");

	return 0;
}