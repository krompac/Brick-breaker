#include "Menu_Window.h"


Menu_Window::Menu_Window()
{
}

Menu_Window::Menu_Window(Function_Pointer playFunction, Function_Pointer resumeFunction, Function_Pointer restartFunction, Function_Pointer quitFunction)
{
	int buttonWidth = 180;
	int buttonHeigth = 50;
	int xPos = GetScreenWidth() - buttonWidth - 100;
	int yPos = GetScreenHeight() - buttonHeigth - 80;
	Color color = LIGHTGRAY;

	auto playButton = new Button(xPos, yPos, buttonWidth, buttonHeigth, color, play, playFunction);

	auto resumeButton = new Button(xPos, yPos, buttonWidth, buttonHeigth, color, resume, resumeFunction);
	resumeButton->DisableMe();

	auto restartButton = new Button(xPos, yPos, buttonWidth, buttonHeigth, color, restart, restartFunction);
	restartButton->DisableMe();

	yPos += 60;
	auto quitButton = new Button(xPos, yPos, buttonWidth, buttonHeigth, color, quit, quitFunction);

	buttons = std::map<const char *, Button *>{ {play, playButton}, {resume, resumeButton}, {restart, restartButton}, {quit, quitButton } };

	InitTitlePictures();
}

Menu_Window::~Menu_Window()
{
	for (auto button : buttons)
	{
		delete button.second;
	}

	delete title[0];
	delete title[1];
	delete title;
}

void Menu_Window::InitTitlePictures()
{
	std::string path = GetWorkingDirectory();
	path.append("/Media/Pictures/");

	auto brickPath = path;
	brickPath.append("brick.png");

	auto breakerPath = path;
	breakerPath.append("breaker.png");

	int xPos = 150;
	int yPos = 25;

	auto brick = new Picture(xPos, yPos, BLACK, brickPath.c_str());
	brick->UpdateSize(300, 100);
	auto breaker = new Picture(xPos + 200, yPos + 100, BLACK, breakerPath.c_str());
	breaker->UpdateSize(300, 100);

	title = new Picture*[2]{ brick, breaker };
}

void Menu_Window::DrawMe()
{
	for (auto button : buttons)
	{
		button.second->DrawMe();
	}

	title[0]->DrawMe();
	title[1]->DrawMe();
}

void Menu_Window::HandleMe()
{
	for (auto button : buttons)
	{
		button.second->CheckIfClicked();
	}
}
