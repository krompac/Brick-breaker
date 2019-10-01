#pragma once
#include "Rect_Object.h"

class Brick : public Rect_Object
{
	private: 
		static int numberOfActiveBricks;

	public:
		Brick();
		Brick(int x, int y, int width, int height, Color color);

		bool IsDisabled();
		void DisableMe();

		static int GetNumberOfActiveBricks();

		~Brick();
};