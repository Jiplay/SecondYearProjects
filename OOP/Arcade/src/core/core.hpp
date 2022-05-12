/*
** Core.hpp for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Mar 16 10:11:16 AM 2021 julien.garsia
** Last update Sat Apr 16 10:24:09 AM 2021 julien.garsia
*/

#ifndef Core_HPP_
#define Core_HPP_

#include <iostream>
#include <fstream>
#include <list>
#include "../../lib/ALibs.hpp"
#include "../../lib/games/AGames.hpp"
#include "../dlopen_encapsulated.hpp"

// TODO ENUM for switch lib

enum Libreturn {
    EXIT = 0,
    NCURSES = 1,
    SFML = 2,
    SDL2 = 3,
    NIBBLER = 10
};

enum State {
    MENU = false,
    GAME = true
};

class Core
{
public:
    Core(std::string path);
    ~Core();
    int Display(int nb, std::string n);
    bool is_the_library_a_game(std::string s);
    void score_manager(std::string name, int score);
private:
    bool _game_or_menu;
    void *_handle;
    ALibs* _menu;
    AGames* _game;
    dlopen_encapsulated *_temp;

};

#endif /* !Core_HPP_ */
