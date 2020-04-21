#include "Gameplay_Window.h"

Gameplay_Window::Gameplay_Window()
{
	pause = false;
	gameWon = false;

	pad = new Pad(0, 430, 100, 20, BLACK);
	ball = new Ball(707, 40, 5, ORANGE);
	
	int brickNumber = 48;

	int bricksInRow = 12;
	int bricksInColumn = brickNumber / bricksInRow;

	int brickWidth = 51;
	int brickHeigth = 25;

	int xDiff = brickWidth + 1;
	int yDiff = brickHeigth + 1;

	int startingXpos = 75;
	int startingYpos = 30;

	int xPos = startingXpos;
	int yPos = startingYpos;

	for (int i = 0; i < bricksInRow; i++)
	{
		if (bricksInColumn)
		{
			for (int j = 0; j < bricksInColumn; j++)
			{
				bricks.push_back(new Brick(xPos, yPos, brickWidth, brickHeigth, BLACK));
				yPos += yDiff;

				if (i == 0 || i == bricksInRow - 1 || j == 0 || j == bricksInColumn - 1) {
					AddBreakableBrick();
				}
			}

			xPos += xDiff;
			yPos = startingYpos;
		}
		else
		{
			bricks.push_back(new Brick(xPos, yPos, brickWidth, brickHeigth, BLACK));
			AddBreakableBrick();
			xPos += xDiff;
		}
	}

	auto connectNeighbourBricks = [](Brick* firstBrick, Brick* secondBrick, Side side)
	{
		auto areNeighbours = [](Brick* firstBrick, Brick* secondBrick)
		{
			auto firstRect = firstBrick->getRect();
			auto secondRect = secondBrick->getRect();

			return firstRect->x == secondRect->x || firstRect->y == secondRect->y;
		};

		Side otherSide = side == LEFT ? RIGHT : UP;

		if (areNeighbours(firstBrick, secondBrick))
		{
			firstBrick->SetBrick(side, secondBrick);
			secondBrick->SetBrick(otherSide, firstBrick);
		}
	};

	for (int i = 0; i < bricks.size(); i++)
	{
		if (i != 0)
		{
			connectNeighbourBricks(bricks[i], bricks[i - 1], LEFT);
		}

		if (i + bricksInRow < bricks.size())
		{
			connectNeighbourBricks(bricks[i], bricks[i + bricksInRow], DOWN);
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

void Gameplay_Window::AddBreakableBrick()
{
	auto brick = bricks.back();
	brick->SetColor(GREEN);
	breakableBricks.push_back(brick);
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

		if (!pause)
		{
			pad->Move();
			ball->Move();

			ball->CheckCollisionWithPad(pad);
			ball->CheckCollisionWithBricks(breakableBricks);
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