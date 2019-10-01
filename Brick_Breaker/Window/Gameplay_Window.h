#pragma once
#include <iostream>

#include "Window.h"
#include "Pad.h"
#include "Ball.h"
#include "raylib.h"

typedef void(*Function_Pointer)();

class Gameplay_Window : public Window
{
	private:
		const int SCREEN_HEIGTH = GetScreenHeight();
		const int SCREEN_WIDTH = GetScreenWidth();

		Function_Pointer toMenu;

		Pad *pad;
		Ball *ball;

		std::vector<Brick*> bricks;

		bool pause;

	public:
		Gameplay_Window();
		Gameplay_Window(Function_Pointer toMenu);
		~Gameplay_Window();
	
		void HandleMe();
		void DrawMe();
};

