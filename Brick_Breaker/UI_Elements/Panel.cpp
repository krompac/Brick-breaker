#include "Panel.h"

Panel::Panel()
{
}

Panel::Panel(int x, int y, int width, int heigth, Color color) : Rect_Object(x, y, width, heigth, color)
{
}

Panel::~Panel()
{
	for (auto button : buttons)
	{
		delete button;
	}

	for (auto object : texts)
	{
		delete object;
	}
}

void Panel::DrawMe()
{
	Rect_Object::DrawMe();

	for (auto button : buttons)
	{
		button->DrawMe();
	}

	for (auto text : texts)
	{
		text->DrawMe();
	}
}

bool Panel::CheckIfClicked()
{
	bool isClicked = false;

	for (auto button : buttons)
	{
		if (button->CheckIfClicked())
		{
			isClicked = true;
		}
	}

	return isClicked;
}

void Panel::AddButton(Button * button)
{
	buttons.push_back(button);
}

void Panel::AddButton(int x, int y, int width, int heigth, Color color, const char * text, Function_Pointer func)
{
	auto button = new Button(x, y, width, heigth, color, text, func);
	AddButton(button);
}

void Panel::AddText(Text * text)
{
	texts.push_back(text);
}

void Panel::AddText(int xPos, int yPos, int fontSize, Color color, const char * text)
{
	auto newText = new Text(xPos, yPos, fontSize, color, text);
	AddText(newText);
}
