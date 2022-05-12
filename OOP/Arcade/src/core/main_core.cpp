/*
** main_core.cpp for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Mar 16 10:10:50 AM 2021 julien.garsia
** Last update Sat Apr 16 10:24:14 AM 2021 julien.garsia
*/

#include "core.hpp"
#include "../exceptions/error.hpp"

bool Core::is_the_library_a_game(std::string s)
{
    std::size_t found0 = s.find("nibbler");
    std::size_t found1 = s.find("pacman");
    std::size_t found2 = s.find("qix");
    std::size_t found3 = s.find("centipede");
    std::size_t found4 = s.find("solarfox");
    
    if (found0 != std::string::npos || found1 != std::string::npos || found2 != std::string::npos || found3 != std::string::npos || found4 != std::string::npos)
        return State::GAME;

    return State::MENU;
}


Core::Core(std::string s)
{

    bool t = is_the_library_a_game(s); // const &

    if (t == State::GAME) {
        _temp = new dlopen_encapsulated(s.c_str(), t);
        _temp->open();
        _game = _temp->getAgames();
    } else {
        _temp = new dlopen_encapsulated(s.c_str(), t);
        _temp->open();
        _menu = _temp->getAlibs();
    }
}

void Core::score_manager(std::string s, int nb)
{
    std::ifstream file("scores.txt");
    std::list<std::string> l;
    std::string tmp;
    std::string final_str = std::to_string(nb) + " " + s;

    while (std::getline(file, tmp)) {
        l.push_back(tmp);
    }
    l.push_back(final_str);
    l.sort();
    l.reverse();

    std::string const nomFichier("scores.txt");
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)    
    {
        for (std::string i : l) {
            monFlux << i << std::endl;
        }
    } else {
        std::cout << "toz" << std::endl;
    }
}

bool check_lib(int nb)
{
    if (nb % 2 == 0)
        return true;
    return false;
}

int Core::Display(int nb, std::string name)
{
    int a = 0;
    if (nb < 10) {
        a = _menu->createWindow();
        return a;
    } else {
        bool t = check_lib(nb);
        a = _game->game(t);
        score_manager(name, a);
        return 3;
    } 
}

Core::~Core()
{
    if (_game_or_menu == false) {
        _temp->~dlopen_encapsulated();
    } else {
        _temp->~dlopen_encapsulated();
    }
}