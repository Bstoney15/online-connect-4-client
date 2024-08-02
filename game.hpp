#ifndef GAMEDRIVER_HPP
#define GAMEDRIVER_HPP

#include <vector>
#include "sdl2/sdl.h"
#include "SDL2/sdl_ttf.h"


class Game
{
    public:
        int16_t Init();
        void Render();
        void Update();
        void PollEvents();
        bool GetIsRunning();
        void renderMenu();

    private:
        SDL_Renderer* renderer = NULL;
        SDL_Window* window = NULL;
        bool isRunning = false;
        SDL_Event event;
        SDL_Rect bounds;

        TTF_Font* subtitleFont;
        TTF_Font* titleFont;
        TTF_Font* buttonFont;

        int test = 255;

        
};


#endif