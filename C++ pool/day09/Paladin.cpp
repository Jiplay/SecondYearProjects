/*
** Paladin.cpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 2:28:26 PM 2021 julien.garsia
** Last update Fri Jan 14 3:11:13 PM 2021 julien.garsia
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level) :Character(name, level), Warrior(name, level), Priest(name, level)
{
    Name = name;
    weaponName = "hammer";
    Level = level;
    Health = 100;
    Energy = 100;
    Strength = 9;
    Stamina = 10;
    Intelligence = 10;
    Spirit = 10;
    Agility = 2;

    std::cout << "the light falls on " << Name << std::endl;
}

int Paladin::CloseAttack()
{
    if (Energy >= 30 && Range == CLOSE) {
        Energy = Energy - 30;
        std::cout << Name << " strikes with his " << weaponName << std::endl;
        return (20 + Strength);
    }
    std::cout << Name << " out of power" << std::endl;
    return 0;
}

int Paladin::RangeAttack()
{
    if (Energy >= 25) {
        Energy = Energy - 25;
        std::cout << Name << " launches a fire ball" << std::endl;
        return (20 + Spirit);
    }
    std::cout << Name << " out of power" << std::endl;
    return 0;
}

void Paladin::Heal()
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

void Paladin::RestorePower()
{
    Energy = 100;
    std::cout << Name << " eats" << std::endl;
}

int Paladin::Intercept()
{
    if (Energy >= 10 && Range == RANGE) {
        Energy = Energy - 10;
        std::cout << Name << " intercepts" << std::endl;
        Range = CLOSE;
        return (0);
    }
    std::cout << Name << " out of power" << std::endl;
    return 0;
}

Paladin::~Paladin()
{
}
