#pragma once
#include <iostream>

#include "raylib.h"
#include "Game_Object.h"

class Rect_Object : public Game_Object
{
	protected:
		bool isDisabled;
		Rectangle *rect;

	public:
		Rect_Object();
		Rect_Object(int x, int y, int width, int height, Color color);
	
		void SetXpos(int value);
		void SetYpos(int value);

		Rectangle *getRect();
		virtual void DrawMe();
		virtual void DisableMe();

		~Rect_Object();
};

