#include "Button.h"

Button::Button()
{
}

Button::Button(int x, int y, int width, int heigth, Color color, const char *text, Nekaj func) : Rect_Object(x, y, width, heigth, color)
{
	auto fontSize = height / 2;
	auto textSize = MeasureText(text, fontSize);

	while (width - textSize < 10)
	{
		fontSize--;
		textSize = MeasureText(text, fontSize);
	}

	auto textIndention = (int)(width - textSize) / 2;

	this->text = new Text(x + textIndention, y + (heigth / 3), fontSize, BLACK, text);

	this->func = func;
}

void Button::DrawMe()
{
	Rect_Object::DrawMe();
	text->DrawMe();
}

bool Button::CheckIfClicked()
{
	auto returnMe = (CheckCollisionPointRec(GetMousePosition(), *rect) && IsMouseButtonPressed(0));

	if (returnMe)
	{
		func();
	}

	return returnMe;
}

Button::~Button()
{
	delete text;
}
