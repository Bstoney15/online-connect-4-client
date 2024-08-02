#include "game.hpp"
#include <cstdio>


int16_t Game::Init()
{

    int16_t initValue = 0;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("SDL failed");
        initValue++;
        return initValue;
    }


    SDL_GetDisplayBounds(0, &bounds);
    bounds.x = 600; //how wide the window is
    bounds.y = 600; //how tall the window is


    window = SDL_CreateWindow("connect 4", int((bounds.w - bounds.x)/2), int((bounds.h - bounds.y)/2), bounds.x, bounds.y, 0);
    if(window == NULL)
    {
        SDL_Log("window failed");
        initValue++;
        return initValue;
    }


    renderer = SDL_CreateRenderer(window, 1, 0);
    if(renderer == NULL)
    {
        SDL_Log("Renderer Failed");
        initValue++;
        return initValue;
    }

    if(TTF_Init() < 0)
    {
        SDL_Log("TTF failed");
        initValue++;
        return initValue;
    }

    titleFont = TTF_OpenFont("font3.ttf", 48);
    subtitleFont = TTF_OpenFont("font3.ttf", 24);
    buttonFont = TTF_OpenFont("font4.ttf", 12);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);




    //Create menus


    isRunning = true;
    return initValue;
}

void Game::renderMenu()
{
    SDL_Log("rendering menu");

    SDL_Surface* titleSurface = TTF_RenderText_Blended(titleFont, "CONNECt 4", {255, 255, 255, 255});
    SDL_Surface* subtitleSurface = TTF_RenderText_Blended(subtitleFont, "online", {255, 255, 255, 255});
    SDL_Texture* titleTexture = SDL_CreateTextureFromSurface(renderer, titleSurface);
    SDL_Texture* subtitleTexture = SDL_CreateTextureFromSurface(renderer, subtitleSurface);

    SDL_Rect titleRect;
    SDL_Rect subtitleRect;
    SDL_QueryTexture(titleTexture, NULL, NULL, &titleRect.w, &titleRect.h);
    SDL_QueryTexture(subtitleTexture, NULL, NULL, &subtitleRect.w, &subtitleRect.h);

    titleRect.x = (bounds.x - titleRect.w) / 2;
    titleRect.y = (bounds.y - titleRect.h) / 20;

    subtitleRect.x = (bounds.x - subtitleRect.w) / 2;
    subtitleRect.y = ((bounds.y - titleRect.h) / 20) + titleRect.h;

    SDL_RenderCopy(renderer, titleTexture, NULL, &titleRect);
    SDL_RenderCopy(renderer, subtitleTexture, NULL, &subtitleRect);


    SDL_Surface* onlineButtonSurface = TTF_RenderText_Blended(buttonFont, "O-Online", {0, 0, 0, 255});
    SDL_Texture* onlineButtonTexture = SDL_CreateTextureFromSurface(renderer, onlineButtonSurface);
    SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
    SDL_Rect onlineButtonRect;
    onlineButtonRect.w = 100;
    onlineButtonRect.h = 50;
    onlineButtonRect.x = (bounds.x - onlineButtonRect.w) / 4;
    onlineButtonRect.y = (bounds.y - onlineButtonRect.h) / 1.5;
    SDL_RenderFillRect(renderer, &onlineButtonRect);
    SDL_RenderCopy(renderer, onlineButtonTexture, NULL, &onlineButtonRect);

    SDL_Surface* offlineButtonSurface = TTF_RenderText_Blended(buttonFont, "S-Offline", {0, 0, 0, 255});
    SDL_Texture* offlineButtonTexture = SDL_CreateTextureFromSurface(renderer, offlineButtonSurface);
    SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
    SDL_Rect offlineButtonRect;
    offlineButtonRect.w = 100;
    offlineButtonRect.h = 50;
    offlineButtonRect.x = (int)((double)(bounds.x - offlineButtonRect.w) / (4.0/3.0));
    offlineButtonRect.y = (bounds.y - offlineButtonRect.h) / 1.5;
    SDL_RenderFillRect(renderer, &offlineButtonRect); 
    SDL_RenderCopy(renderer, offlineButtonTexture, NULL, &offlineButtonRect);




    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

    SDL_DestroyTexture(titleTexture);
    SDL_DestroyTexture(subtitleTexture);
    SDL_FreeSurface(titleSurface);
    SDL_FreeSurface(subtitleSurface);
    SDL_FreeSurface(onlineButtonSurface);
    SDL_DestroyTexture(onlineButtonTexture);


    SDL_Log("finished rendering menu");
}


void Game::Update()
{

}

void Game::Render()
{

}

bool Game::GetIsRunning()
{
    return isRunning;
}

void Game::PollEvents()
{
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:

                isRunning = false;
                break;

            case SDL_KEYDOWN:

                switch(event.key.keysym.sym)
                {
                    case SDLK_SPACE:
                        renderMenu();
                        break;
                }
        }
    }
}