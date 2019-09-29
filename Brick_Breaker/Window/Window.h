#pragma once
#include "Drawable_Object.h"
#include "Clickable_Object.h"

class Window : public Drawable_Object
{
	protected:
		virtual void DrawMe() = 0;

	public:
		Window();
		~Window();
		
		virtual void HandleMe() = 0;
};

