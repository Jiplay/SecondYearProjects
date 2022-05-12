/*
** Mage.cpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 10:46:35 AM 2021 julien.garsia
** Last update Fri Jan 14 11:43:56 AM 2021 julien.garsia
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    Name = name;
    Level = level;
    Health = 100;
    Energy = 100;
    Strength = 6;
    Stamina = 6;
    Intelligence = 12;
    Spirit = 11;
    Agility = 7;

    std::cout << Name << " teleported" << std::endl;
}

int Mage::CloseAttack()
{
    if (Energy >= 10 && Range == CLOSE) {
        Energy = Energy - 10;
        Range = RANGE;
        std::cout << Name << " blinks" << std::endl;
        return 0;
    }
    std::cout << Name << " out of power" << std::endl;
    return 0;
}

int Mage::RangeAttack()
{
    if (Energy >= 25) {
        Energy = Energy - 25;
        std::cout << Name << " launches a fire ball" << std::endl;
        return (20 + Spirit);
    }
    std::cout << Name << " out of power" << std::endl;
    return 0;
}

void Mage::RestorePower()
{
    if (Energy + 50 + Intelligence > 100)
        Energy = 100;
    else
        Energy = Energy + 50 + Intelligence;
    std::cout << Name << " takes a mana potion" << std::endl;
}



Mage::~Mage()
{
}
