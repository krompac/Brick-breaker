#include "Menu_Window.h"

Menu_Window::Menu_Window()
{
}

Menu_Window::Menu_Window(Function_Pointer playFunction, Function_Pointer resumeFunction, Function_Pointer restartFunction, Function_Pointer quitFunction)
{
	int buttonWidth = 100;
	int buttonHeigth = 30;
	int xPos = GetScreenWidth() - buttonWidth - 20;
	int yPos = GetScreenHeight() - buttonHeigth - 80;
	Color color = LIGHTGRAY;

	auto playButton = new Button(xPos, yPos, buttonWidth, buttonHeigth, color, play, playFunction);

	auto resumeButton = new Button(xPos, yPos, buttonWidth, buttonHeigth, color, resume, resumeFunction);
	resumeButton->DisableMe();

	auto restartButton = new Button(xPos, yPos, buttonWidth, buttonHeigth, color, restart, restartFunction);
	restartButton->DisableMe();

	yPos += 40;
	auto quitButton = new Button(xPos, yPos, buttonWidth, buttonHeigth, color, quit, quitFunction);

	buttons = std::map<const char *, Button *>{ {play, playButton}, {resume, resumeButton}, {restart, restartButton}, {quit, quitButton } };
}

Menu_Window::~Menu_Window()
{
	for (auto button : buttons)
	{
		delete button.second;
	}
}

void Menu_Window::DrawMe()
{
	for (auto button : buttons)
	{
		button.second->DrawMe();
	}
}

void Menu_Window::HandleMe()
{
	for (auto button : buttons)
	{
		button.second->CheckIfClicked();
	}
}
