/*
** Hunter.cpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 3:37:58 PM 2021 julien.garsia
** Last update Thu Jan 14 3:37:58 PM 2021 julien.garsia
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level) : Character(name, level), Warrior(name, level)
{
    Name = name;
    weaponName = "sword";
    Level = level;
    Health = 100;
    Energy = 100;
    Strength = 9;
    Stamina = 9;
    Intelligence = 5;
    Spirit = 6;
    Agility = 25;

    std::cout << Name << " is born from a tree" << std::endl;
}

int Hunter::CloseAttack()
{
    if (Energy >= 30 && Range == CLOSE) {
        Energy = Energy - 30;
        std::cout << Name << " strikes with his " << weaponName << std::endl;
        return (20 + Strength);
    }
    std::cout << Name << " out of power" << std::endl;
    return 0;
}

int Hunter::RangeAttack()
{
    if (Energy >= 25) {
        Energy = Energy - 25;
        std::cout << Name << " uses his bow" << std::endl;
        return (20 + Agility);
    }
    std::cout << Name << " out of power" << std::endl;
    return 0;
}

void Hunter::RestorePower()
{
    Energy = 100;
    std::cout << Name << " meditates" << std::endl;
}

void Hunter::Heal()
{
    if ( Health + 50 > 100)
        Health = 100;
    else
        Health = Health + 50;
    std::cout << Name << " takes a potion" << std::endl;
}

Hunter::~Hunter()
{
}
