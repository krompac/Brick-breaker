#pragma once
#include <iostream>

#include "Window.h"
#include "Pad.h"
#include "Ball.h"
#include "Panel.h"
#include "TypeFuncPointer.h"
#include "raylib.h"
#include "Side.h"

class Gameplay_Window : public Window
{
	private:
		const int SCREEN_HEIGTH = GetScreenHeight();
		const int SCREEN_WIDTH = GetScreenWidth();

		Function_Pointer toMenu;

		Pad *pad;
		Ball *ball;

		std::vector<Brick*> bricks;
		std::vector<Brick*> breakableBricks;

		bool pause;
		bool gameWon;

		Panel *gameWonPanel;

		void AddBreakableBrick();

	public:
		Gameplay_Window();
		Gameplay_Window(Function_Pointer toMenu);
		~Gameplay_Window();
	
		void HandleMe();
		void DrawMe();
};

