#pragma once
#include "Rect_Object.h"

class Brick : public Rect_Object
{
private: 
	bool isDisabled;

public:
	Brick();
	Brick(int x, int y, int width, int height, Color color);

	void DestroyMe();
	void DrawMe();
	bool IsDisabled();

	~Brick();
};

