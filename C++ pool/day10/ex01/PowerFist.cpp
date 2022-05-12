/*
** PowerFist.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD10-julien.garsia/ex01
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 12:36:19 PM 2021 julien.garsia
** Last update Sat Jan 15 9:24:02 PM 2021 julien.garsia
*/

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon(std::string("Power Fist"), 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const 
{
    std::cout << "* pschhh... SBAM! *" <<std::endl;    
}
