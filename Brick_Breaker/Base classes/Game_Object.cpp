#include "Game_Object.h"

Game_Object::Game_Object()
{
}

Game_Object::Game_Object(int x, int y, int width, int heigth, Color color) : x(x), y(y), heigth(heigth), width(width), color(color)
{

}

Game_Object::~Game_Object()
{
}

void Game_Object::SetXpos(int value)
{
	x = value;
}

void Game_Object::SetYpos(int value)
{
	y = value;
}

void Game_Object::SetWidth(int value)
{
	width = value;
}

void Game_Object::SetHeigth(int value)
{
	heigth = value;
}

void Game_Object::SetColor(Color color)
{
	this->color = color;
}
