#include "Text.h"

Text::Text()
{
	text = nullptr;
}

Text::Text(int xPos, int yPos, int fontSize, Color color, const char * text) :
	xPos(xPos), yPos(yPos), fontSize(fontSize), color(color), text(text)
{
}


Text::~Text()
{
}

void Text::UpdateXPosition(int value)
{
	xPos += value;
}

void Text::SetYPosition(int value)
{
	yPos = value;
}

void Text::DrawMe()
{
	DrawText(text, xPos, yPos, fontSize, color);
}
