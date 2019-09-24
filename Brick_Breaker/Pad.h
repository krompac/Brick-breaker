#pragma once
#include "Rect_Object.h"
#include "Moveable_Object.h"

class Pad : public Rect_Object, public Moveable_Object 
{
	private:
		float xPosDifference;
		int currentMouseX;

	public:
		Pad();
		Pad(int x, int y, int width, int height, Color color);

		void Move();

		~Pad();
};

