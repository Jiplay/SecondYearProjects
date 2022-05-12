/*
** Priest.cpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 11:47:15 AM 2021 julien.garsia
** Last update Fri Jan 14 9:14:43 PM 2021 julien.garsia
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Character(name, level)
{
    Strength = 4;
    Stamina = 4;
    Intelligence = 42;
    Spirit = 21;
    Agility = 2;

    std::cout << Name << " teleported" << std::endl;
    std::cout << Name << " enters in the order" << std::endl;
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    if (Energy >= 10 && Range == CLOSE) {
        Energy = Energy - 10;
        Range = Range;
        std::cout << Name << " uses a spirit explosion" << std::endl;
        return (10 + Spirit);
    }
    std::cout << Name << " out of power" << std::endl;
    return 0;
}

int Priest::RangeAttack()
{
    if (Energy >= 25) {
        Energy = Energy - 25;
        std::cout << Name << " launches a fire ball" << std::endl;
        return (20 + Spirit);
    }
    std::cout << Name << " out of power" << std::endl;
    return 0;
}

void Priest::RestorePower()
{
    if (Energy + 50 + Intelligence > 100)
        Energy = 100;
    else
        Energy = Energy + 50 + Intelligence;
    std::cout << Name << " takes a mana potion" << std::endl;
}

void Priest::Heal()
{
    if (Energy >= 10) {
        Energy = Energy - 10;
        Health = Health + 70;
        if ( Health > 100)
            Health = 100;
    std::cout << Name << " casts a little heal spell" << std::endl;
    } else
        std::cout << Name << " out of power" << std::endl;
}
