/*
** main.cpp for 
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 10:33:30 AM 2021 julien.garsia
** Last update Sat Jan 15 10:42:40 AM 2021 julien.garsia
*/

#include "Sorcerer.hpp"
#include "Peon.hpp"

int main()
{
    Sorcerer s("Julien", "Le Witcher");
    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << s << jim << joe;

    s.polymorph(jim);
    s.polymorph(joe);
}