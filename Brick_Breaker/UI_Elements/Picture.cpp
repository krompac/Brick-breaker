#include "Picture.h"

Picture::Picture()
{
}

Picture::Picture(int x, int y, Color color, const char *path) : Game_Object(x, y, 0, 0, color)
{
	texture = LoadTexture(path);
	SetWidth(texture.width);
	SetHeigth(texture.height);
}

Picture::~Picture()
{
}

void Picture::DrawMe()
{
	DrawTexture(texture, x, y, color);
}

void Picture::DrawMeInsideRect(Rectangle * rect)
{
	//TO DO
}

void Picture::UpdateSize(int width, int heigth)
{
	texture.width = width;
	texture.height = heigth;
	SetWidth(width);
	SetHeigth(heigth);
}
