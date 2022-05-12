/*
** SDL2.hpp for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Mar 18 10:19:11 AM 2021 julien.garsia
** Last update Thu Mar 24 10:28:12 AM 2021 julien.garsia
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>

#include "../ALibs.hpp"


class SDL2 : public ALibs
{
    public:
        SDL2();
        ~SDL2() = default;

        int createWindow();
        void destroyWindow();
        int getCommand();
        int getCommand(const char *key);
        int randInt(int min, int max);
        int gameLoop();
        int mainLoop();
        void setGame();

    private:
        SDL_Rect _txtRect;
};

#endif /* !SDL2_HPP_ */
