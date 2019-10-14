#include "Gameplay_Window.h"

Gameplay_Window::Gameplay_Window()
{
	pause = false;
	gameWon = false;

	pad = new Pad(0, 430, 100, 20, BLACK);
	ball = new Ball(707, 40, 5, ORANGE);

	int xPos = 75;
	int yPos = 30;
	int diff = 52;
	int brickNumber = 4;

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

	int panelWidth = 300;
	int panelHeigth = 200;
	int panelXpos = (SCREEN_WIDTH - panelWidth) / 2;
	int panelYpos = (SCREEN_HEIGTH - panelHeigth) / 2;

	gameWonPanel = new Panel(panelXpos, panelYpos, panelWidth, panelHeigth, ORANGE);
}

Gameplay_Window::Gameplay_Window(Function_Pointer toMenu) : Gameplay_Window()
{
	this->toMenu = toMenu;

	auto panelRect = gameWonPanel->getRect();

	int buttonWidth = 125;
	int buttonHeigth = 40;
	int buttonXpos = (panelRect->width - buttonWidth) / 2 + panelRect->x;
	int buttonYpos = panelRect->y + panelRect->height - buttonHeigth - 20;
	const char *buttonText = "OKAY";

	auto toMenuButton = new Button(buttonXpos, buttonYpos, buttonWidth, buttonHeigth, GRAY, buttonText, toMenu);

	gameWonPanel->AddButton(toMenuButton);

	int textXpos = panelRect->x + 30;
	int textYpos = panelRect->y + 30;

	auto scoreLabel = new Text(textXpos, textYpos, 25, RED, "Score: ");
	
	//TO DO: implementirati da korisnik sam upiše score na kraju
	auto scoreValue = new Text(textXpos + MeasureText("Score: ", 25) + 20, textYpos, 25, RED, "1234"); 
	
	textYpos += 50;

	auto nameLabel = new Text(textXpos, textYpos, 25, RED, "Name: ");

	gameWonPanel->AddText(scoreLabel);
	gameWonPanel->AddText(scoreValue);
	gameWonPanel->AddText(nameLabel);
}

Gameplay_Window::~Gameplay_Window()
{
	delete ball;
	delete pad;

	for (auto brick : bricks)
	{
		delete brick;
	}

	delete gameWonPanel;
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

	if (gameWon)
	{
		gameWonPanel->DrawMe();
	}
}

void Gameplay_Window::HandleMe()
{
	gameWon = Brick::GetNumberOfActiveBricks() == 0;

	if (!gameWon)
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
	
		if (IsKeyDown(KEY_ESCAPE))
		{
			toMenu();
			pause = true;
		}
	}
	else
	{
		if (!pause)
		{
			pause = true;
			EnableCursor();
		}

		gameWonPanel->DrawMe();
		if (gameWonPanel->CheckIfClicked())
		{
			pause = false;
		}
	}
}