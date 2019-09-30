#pragma once
#include "Drawable_Object.h"
#include "Clickable_Object.h"

class Window : public Drawable_Object
{
	public:
		Window();
		~Window();
		
		virtual void HandleMe() = 0;
		virtual void DrawMe() = 0;
};

