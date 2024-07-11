#include <SDL3/SDL.h>
#include "game.hpp"

int main(int argc, char* argv[])
{
	
	Game driver;
	int result = driver.Init();
	if (result > 0)
	{
		SDL_Log(SDL_GetError());
	}

	while (driver.running)
	{
		driver.Render();
		driver.PollEvents();

		SDL_Delay(10);
	}

	driver.destroy();

}