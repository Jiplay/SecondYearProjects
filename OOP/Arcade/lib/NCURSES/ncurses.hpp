/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <string>
#include <list>
#include <ncurses.h>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include "../ALibs.hpp"

#define WIDTH 700
#define HEIGHT 350

struct Serpent{
    int x;
    int y;
    Serpent(int y, int x);
    Serpent();
};

class Ncurses : public ALibs
{
    public:
        Ncurses();
        ~Ncurses() = default;

        int createWindow();
        void destroyWindow();
        int getCommand();
        int menu();
        void displayWindow();
        int mainLoop();


// UPDATE NIBBLER

        void setGame();
        void createFood();
        void gameWindow();
        void scoreWindow();
        void gameScreen(int screen);
        int hit();
        int move();
        void endGame();
        int gameLoop();
        int game(bool t);

    private:
        int _length;
        int _height;

// UPDATE NIBBLER
        int y, x;
        int yMax, xMax;
        std::list<Serpent> snake;
        std::list<Serpent>::iterator i;

        Serpent food;
        char direction;
        WINDOW *nibblerwin, *scorewin;
        int sizeX, sizeY, borderX, borderY;
};

#endif /* !NCURSES_HPP_ */
