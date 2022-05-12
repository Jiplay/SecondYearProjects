/*
** SuperMutant.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 12:50:27 PM 2021 julien.garsia
** Last update Mon Jan 17 2:34:26 PM 2021 julien.garsia
*/

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : AEnemy(170, std::string("Super Mutant"))
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    int trueDamage = damage - 3;

    _Hp = _Hp - trueDamage;
}
