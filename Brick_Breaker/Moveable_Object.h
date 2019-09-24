#pragma once
class Moveable_Object
{
	public:
		Moveable_Object();
		~Moveable_Object();

		virtual void Move() = 0;
};

