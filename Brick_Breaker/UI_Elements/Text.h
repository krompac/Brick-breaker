#pragma once
#include "raylib.h"
#include "Drawable_Object.h"

class Text : Drawable_Object
{
	private:
		int xPos;
		int yPos;
		int fontSize;
		Color color;
		const char *text;

	public:
		Text();
		Text(int xPos, int yPos, int fontSize, Color color, const char *text);
		~Text();

		void UpdateXPosition(int value);
		void SetYPosition(int value);
		void DrawMe();
};

