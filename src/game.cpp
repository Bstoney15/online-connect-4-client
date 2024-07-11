#include "game.hpp"
#include "SDL3/SDL.h"

int Game::Init()
{

	running = 1;
	int result = 0;

	window = SDL_CreateWindow("Connect 4", 500, 500, SDL_WINDOW_RESIZABLE);
	if (window == NULL)
	{
		result++;
	}

	renderer = SDL_CreateRenderer(window, NULL);
	SDL_SetRenderVSync(renderer, 1);
	if (renderer == NULL)
	{
		result++;
	}




	return result;
}

void Game::PollEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			SDL_Log("quit");
			running = 0;
			break;

		case SDL_EVENT_KEY_DOWN:
			
			switch (event.key.key)
			{
				case SDLK_ESCAPE:
					running = 0;
					SDL_Log("esc pushed");
					break;
			}

		}
	}
}

void Game::destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}



void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0xff, 0xff);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

