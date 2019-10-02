#pragma once
#include "Game_Object.h"

class Picture : public Game_Object
{
	private:
		Texture2D texture;

	public:
		Picture();
		Picture(int x, int y, Color color, const char *path);
		~Picture();

		void DrawMe();
		void DrawMeInsideRect(Rectangle *rect);
		void UpdateSize(int width, int heigth);
};

