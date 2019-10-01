#include "Gameplay_Window.h"

Gameplay_Window::Gameplay_Window()
{
	pause = false;

	pad = new Pad(0, 430, 100, 20, BLACK);
	ball = new Ball(707, 40, 5, ORANGE);

	int xPos = 75;
	int yPos = 30;
	int diff = 52;
	int brickNumber = 60;

	for (int i = 0; i < brickNumber; i++)
	{
		bricks.push_back(new Brick(xPos, yPos, 51, 25, BLACK));
		xPos += diff;

		if (bricks.size() % 12 == 0)
		{
			xPos = 75;
			yPos += 26;
		}
	}
}

Gameplay_Window::Gameplay_Window(Function_Pointer toMenu) : Gameplay_Window()
{
	this->toMenu = toMenu;
}

Gameplay_Window::~Gameplay_Window()
{
	delete ball;
	delete pad;

	for (auto brick : bricks)
	{
		delete brick;
	}
}

void Gameplay_Window::DrawMe()
{
	DrawRectangle(0, 0, 50, SCREEN_HEIGTH, GRAY);
	DrawRectangle(SCREEN_WIDTH - 50, 0, 50, SCREEN_HEIGTH, GRAY);

	ball->DrawMe();
	pad->DrawMe();

	for (auto brick : bricks)
	{
		brick->DrawMe();
	}
}

void Gameplay_Window::HandleMe()
{
	if (Brick::GetNumberOfActiveBricks() != 0)
	{
		if (IsKeyPressed(KEY_P))
		{
			pause = !pause;
		}

		if (pause == false)
		{
			pad->Move();
			ball->Move();

			ball->CheckCollisionWithPad(pad);
			ball->CheckCollisionWithBricks(bricks);
		}
	}

	if (IsKeyDown(KEY_ESCAPE))
	{
		toMenu();
		pause = true;
	}
}