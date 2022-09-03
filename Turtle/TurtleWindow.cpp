#include "TurtleWindow.h"

np::TurtleWindow::TurtleWindow(const char* title, unsigned int width, unsigned int height) : width(width), height(height)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
	renderer = SDL_CreateRenderer(window, -1, flags);
}

void np::TurtleWindow::Begin()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
}

void np::TurtleWindow::End()
{
	static SDL_Event sdlEvent;

	while (renderer && window)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_KEYDOWN:
				SDL_DestroyRenderer(renderer);
				SDL_DestroyWindow(window);
				SDL_Quit();
			}
		}

		SDL_RenderPresent(renderer);
	}
}

void np::TurtleWindow::SetScale(unsigned int width, unsigned int height)
{
	SDL_RenderSetScale(renderer, width, height);
}
