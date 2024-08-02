#include "game.hpp"
#include "SDL2/SDL_main.h"
#include <iostream>



int main(int argc, char* argv[])
{
    Game game;
    game.Init();


    while(game.GetIsRunning())
    {
        game.PollEvents();
        game.Update();
        game.Render();
    }

    SDL_Quit();
    return 0;
}