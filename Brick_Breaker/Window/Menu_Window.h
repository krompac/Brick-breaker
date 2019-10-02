#pragma once
#include <map>

#include "Window.h"
#include "Button.h"
#include "Picture.h"

typedef void(*Function_Pointer)();

class Menu_Window : public Window 
{
	private:
		std::map<const char *, Button *> buttons;

		const char *play = "PLAY";
		const char *resume = "RESUME";
		const char *restart = "RESTART";
		const char *quit = "QUIT";

		Picture **title;
		void InitTitlePictures();

	public:
		Menu_Window();
		Menu_Window(Function_Pointer playFunction, Function_Pointer resumeFunction, Function_Pointer restartFunction, Function_Pointer quitFunction);

		~Menu_Window();

		void DrawMe();
		void HandleMe();
};
