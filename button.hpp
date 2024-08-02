#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "sdl2/sdl.h"


class Button : SDL_Rect
{
public:
    SDL_Color color;
    SDL_Texture* texture;

    Button(int x, int y, int w, int h, SDL_Color color, SDL_Texture* texture) 
    : SDL_Rect{x, y, w, h}, color(color), texture(texture) {}

    SDL_Rect toSDL_Rect() const {
        return {x, y, w, h};
    }

    



};















#endif