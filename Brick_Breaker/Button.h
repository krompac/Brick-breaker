#pragma once
#include "Text.h"
#include "raylib.h"
#include "Rect_Object.h"
#include "Clickable_Object.h"

#include <functional>

typedef void(*Nekaj)();

class Button : public Rect_Object, public Clickable_Object
{
private:
	Nekaj func;
	void(*invokeFunction);
	Text *text;

public:
	Button();
	Button(int x, int y, int width, int heigth, Color color, const char *text, Nekaj func);

	void DrawMe();
	bool CheckIfClicked();

	~Button();
};