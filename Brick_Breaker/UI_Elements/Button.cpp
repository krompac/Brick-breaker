#include "Button.h"

Button::Button()
{
}

Button::Button(int x, int y, int width, int heigth, Color color, const char *text, Function_Pointer func) : Rect_Object(x, y, width, heigth, color)
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

	this->onClickFunction = func;
}

void Button::DrawMe()
{
	if (!isDisabled)
	{
		Rect_Object::DrawMe();
		text->DrawMe();
	}
}

void Button::EnableMe()
{
	if (isDisabled)
	{
		isDisabled = false;
	}
}

bool Button::CheckIfClicked()
{
	auto returnMe = !isDisabled && (CheckCollisionPointRec(GetMousePosition(), *rect) && IsMouseButtonPressed(0));

	if (returnMe)
	{
		onClickFunction();
	}

	return returnMe;
}

Button::~Button()
{
	delete text;
}
