/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
** File description:
** nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

// #include <list>
// #include <ncurses.h>
// #include <ctime>
// #include <stdlib.h>
// #include <unistd.h>
#include "../AGames.hpp"
#include <string>
// #include "../../src/dlopen_encapsulated.hpp"
#include "../../../src/dlopen_encapsulated.hpp"

class Nibbler : public AGames
{
    public:
        // ~Nibbler() = default;

        void setGame();
        // void createFood();
        // void gameWindow();
        // void scoreWindow();
        // void gameScreen(int screen);
        int hit();
        int move();
        void endGame();
        void gameLoop();
        int game(bool t);
    
    protected:
        dlopen_encapsulated *_temp;
        // int y, x;
        // int yMax, xMax;
        // std::list<Serpent> snake;
        // std::list<Serpent>::iterator i;

        // Serpent food;
        // char direction;
        // WINDOW *nibblerwin, *scorewin;
        // int sizeX, sizeY, borderX, borderY;
};

#endif /* !NIBBLER_HPP_ */
