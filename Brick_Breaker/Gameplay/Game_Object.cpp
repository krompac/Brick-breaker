#include "Game_Object.h"

Game_Object::Game_Object()
{
}

Game_Object::Game_Object(int x, int y, int width, int height, Color color) : x(x), y(y), height(height), width(width), color(color)
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

void Game_Object::SetHeight(int value)
{
	height = value;
}

void Game_Object::SetColor(Color color)
{
	this->color = color;
}
