#pragma once
#include <vector>

#include "Rect_Object.h"
#include "Clickable_Object.h"
#include "Button.h"
#include "Text.h"

class Panel : Rect_Object, Clickable_Object
{
	private:
		std::vector<Button *> buttons;
		std::vector<Text *> texts;

	public:
		Panel();
		Panel(int x, int y, int width, int heigth, Color color);
		~Panel();

		void DrawMe();
		bool CheckIfClicked();

		void AddButton(Button *button);
		void AddButton(int x, int y, int width, int heigth, Color color, const char *text, Function_Pointer func);

		void AddText(Text *text);
		void AddText(int xPos, int yPos, int fontSize, Color color, const char *text);
};

