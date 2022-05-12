/*
** RadScorpion.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD10-julien.garsia/ex01
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 1:03:19 PM 2021 julien.garsia
** Last update Mon Jan 17 2:33:29 PM 2021 julien.garsia
*/

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : AEnemy(80, std::string("RadScorpion"))
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}
