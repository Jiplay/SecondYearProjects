/*
** SDL2.cpp for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Mar 18 10:19:16 AM 2021 julien.garsia
** Last update Fri Mar 25 10:01:58 AM 2021 julien.garsia
*/

#define SDL_MAIN_HANDLED // To compile SDL2
#include "SDL2.hpp"

SDL2::SDL2()
{
    _width = 1200;
    _height = 1200;
    _title_char = "Arcade by Ibrahim ZAFAR / Théau BENEZET / Julien GARSIA";
    _txtRect.x = 20;
    _txtRect.y = 50;
    _txtRect.w = 1200;
    _txtRect.h = 100;
}

int SDL2::mainLoop()
{
    
}

extern "C" SDL2* create_object()
{
  return new SDL2;
}

int SDL2::gameLoop()
{

}

void SDL2::setGame()
{
    
}

extern "C" void destroy_object( SDL2* object )
{
  delete object;
}

void SDL2::destroyWindow()
{
    
}

int SDL2::getCommand()
{

}

int SDL2::getCommand(const char *key)
{
    if (strcmp(key, "A") == 0)
        return 2;
    if (strcmp(key, "E") == 0)
        return 1;
    if (strcmp(key, "Q") == 0)
        return 0;
}

// Get a random number from 0 to 255
int SDL2::randInt(int rmin, int rmax) {
    return rand() % rmax + rmin;
}

int SDL2::createWindow()
{
    SDL_Window *window = SDL_CreateWindow(_title_char, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event windowEvent;

    TTF_Init();
    TTF_Font *verdanaFont = TTF_OpenFont("police.ttf", 128);
    SDL_Color textColor = { 0, 255, 255, 255 };
    SDL_Surface *textSurface = TTF_RenderText_Solid(verdanaFont, "Press E to go on the SFML menu or A for the Ncurses menu", textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_FreeSurface(textSurface);
    TTF_Quit();
    SDL_SetRenderDrawColor(renderer, 230, 0, 0, 230);
    
    bool running = true;
    SDL_Event event;
    while (running) {
        // Process events
        while (SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                const char *key = SDL_GetKeyName(event.key.keysym.sym);
                if (strcmp(key, "C") == 0) {
                    SDL_SetRenderDrawColor(renderer, randInt(0, 255), randInt(0, 255), randInt(0, 255), 255);
                }
                if (strcmp(key, "A") == 0) {
                    SDL_DestroyTexture(textTexture);
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 1;
                }
                if (strcmp(key, "E") == 0) {
                    SDL_DestroyTexture(textTexture);
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 2;
                }
                if (strcmp(key, "Q") == 0) {
                    SDL_DestroyTexture(textTexture);
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                }
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, textTexture, NULL, &_txtRect);
        SDL_RenderPresent(renderer);
    }
}
