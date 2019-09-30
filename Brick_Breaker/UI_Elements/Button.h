#pragma once
#include "Text.h"
#include "raylib.h"
#include "Rect_Object.h"
#include "Clickable_Object.h"

typedef void(*Function_Pointer)();

class Button : public Rect_Object, public Clickable_Object
{
	private:
		Function_Pointer invokeFunction;
		Text *text;

	public:
		Button();
		Button(int x, int y, int width, int heigth, Color color, const char *text, Function_Pointer func);

		void DrawMe();
		bool CheckIfClicked();

		~Button();
};