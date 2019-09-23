#pragma once
class Clickable_Object
{
	public:
		Clickable_Object();
		~Clickable_Object();
	
		virtual bool CheckIfClicked() = 0;
};

