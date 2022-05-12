/*
** main.cpp for B-CPP-300-PAR-3-2-CPPrush3-julien.garsia 
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 23 10:32:56 AM 2021 julien.garsia
** Last update Sat Jan 23 10:32:56 AM 2021 julien.garsia
*/

#include <iostream>
#include "main.hpp"
#include "src/Core/Includes/core.hpp"

void help_message()
{
    std::cout << "-graphical :" << std::endl;
    std::cout << "\tOpen the graphical interface." << std::endl;
    std::cout << "-text :" << std::endl;
    std::cout << "\tOpen the text interface." << std::endl;
}

int main (int ac, char **av)
{
    Core core;

    if (ac > 1) {
        std::string arg = av[1];
        if (arg == "-graphical")
            sfml_main(core);
        if (arg == "-text")
            ncurse_main();
        if (arg == "-h")
            help_message();
    } else
        help_message();
    return 0;
}
