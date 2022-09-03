#pragma once
#ifndef TURTLE_WINDOW_H
#define TURTLE_WINDOW_H

//Includes:
#include<SDL.h>
#include<iostream>
#include"Colour.h"

/// <summary>Nameless Programmer namespace.</summary>
namespace np
{
	class TurtleWindow
	{
	private:
		//Attributes:
		const unsigned int flags = 0;
		unsigned int width = 0, height = 0;
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

	public:
		//Constructor:
		TurtleWindow(const char* title, unsigned int width, unsigned int height);

		//Methods:
		void Begin();
		void End();

		//Friends:
		friend class Turtle;
	};
}

#endif // !TURTLE_WINDOW_H