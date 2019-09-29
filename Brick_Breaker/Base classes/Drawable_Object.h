#pragma once
class Drawable_Object
{
	public:
		Drawable_Object();
		~Drawable_Object();

		virtual void DrawMe() = 0;
};

