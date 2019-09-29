#pragma once
#include "raylib.h"
#include "Drawable_Object.h"

class Game_Object : Drawable_Object
{
	protected:
		int x;
		int y;
		int width;
		int height;
		Color color;

	public:
		Game_Object();
		Game_Object(int x, int y, int width, int height, Color color);
		~Game_Object();

		virtual void SetXpos(int value);
		virtual void SetYpos(int value);
		virtual void SetWidth(int value);
		virtual void SetHeight(int value);
		virtual void SetColor(Color color);

		virtual void DrawMe() = 0;
};

