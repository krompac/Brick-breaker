#pragma once
#include "Text.h"
#include "raylib.h"
#include "Rect_Object.h"
#include "Clickable_Object.h"
#include "TypeFuncPointer.h"

class Button : public Rect_Object, public Clickable_Object
{
	private:
		Function_Pointer onClickFunction;
		Text *text;

	public:
		Button();
		Button(int x, int y, int width, int heigth, Color color, const char *text, Function_Pointer func);

		void DrawMe();
		void EnableMe();
		bool CheckIfClicked();

		~Button();
};