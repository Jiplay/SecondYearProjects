/*
** main.cpp for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Mar 15 10:16:38 AM 2021 julien.garsia
** Last update Sat Apr 16 10:35:40 AM 2021 julien.garsia
*/

#include "src/core/core.hpp"
#include "src/exceptions/error.hpp"

std::string What_should_i_do_next(int &nb)
{
    std::string SDL2Path = "lib/arcade_sdl2.so";
    std::string SFMLPath = "lib/arcade_sfml.so";
    std::string NCURSESPath = "lib/arcade_ncurses.so";
    std::string NibblerPath = "lib/arcade_nibbler.so";
    std::string PacmanPath = "lib/arcade_pacman.so";

    if (nb == 1) {
        nb = 1;
        return NCURSESPath;
    }
    if (nb == 2) { 
        nb = 2;
        return SFMLPath;
    }
    if (nb == 3) {
        nb = 3;
        return SDL2Path;
    }
    if (nb > 12 && nb < 15) {
        return NibblerPath;
    }  
    if (nb > 9 && nb << 12) {
        return PacmanPath;
    }

    return std::string("Impossible has happened");
}

std::string name_func()
{
    std::cout << "Hey bro, gimme your name :)" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Have fun " << name << std::endl;

    return name;
}

int synchro_to_tmp(std::string s)
{
    std::string SDL2Path = "lib/arcade_sdl2.so";
    std::string SFMLPath = "lib/arcade_sfml.so";
    std::string NCURSESPath = "lib/arcade_ncurses.so";
    std::string NibblerPath = "lib/arcade_nibbler.so";
    std::string PacmanPath = "lib/arcade_pacman.so";

    if (s.compare(SDL2Path) == 0)
        return 3;
    if (s.compare(SFMLPath) == 0)
        return 2;
    if (s.compare(NCURSESPath) == 0)
        return 1;
    if (s.compare(NibblerPath) == 0)
        return 10;
    if (s.compare(PacmanPath) == 0)
        return 11;

    return 0;
}

int main (int ac, char **av)
{
    int a = 1;
    // int cmp = 0;

    if (ac != 2) {
        std::cerr << "Bad entries, you may forgot the path to the lib" << std::endl;
        return 84;
    }
    std::string tmp = av[1];
    std::string name = name_func();
    try
    {
        while (1) {
            Core *c = new Core ((tmp));  // Extra '()' to fix a warning :)
            a = c->Display(a, name);
            if (a == Libreturn::EXIT)
                break;
            tmp = What_should_i_do_next(a);
            // a = synchro_to_tmp(tmp);
            delete c;
            // cmp++;
        }
    }
    catch(const ArcadeError &e)
    {
        std::cerr << e.what() << '\n';
        return 84;
    }

    std::cout << "See you soon " << name << std::endl;
    return 0;
}