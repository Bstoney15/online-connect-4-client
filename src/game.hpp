#ifndef GAME_HPP
#define GAME_HPP
#include "SDL3/SDL.h"

class Game {
	public:
		int Init();
		void Render();
		void PollEvents();
		void destroy();
		int running;

	private:
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;

};



#endif // !GAME_HPP
