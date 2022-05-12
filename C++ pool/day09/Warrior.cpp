/*
** Warrior.cpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 10:30:52 AM 2021 julien.garsia
** Last update Fri Jan 14 2:54:29 PM 2021 julien.garsia
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level) : Character(name, level)
{
    Name = name;
    Level = level;
    weaponName = "hammer";
    Health = 100;
    Energy = 100;
    Strength = 12;
    Stamina = 12;
    Intelligence = 6;
    Spirit = 5;
    Agility = 7;

    std::cout << "I'm "<< Name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
    if (Energy >= 30 && Range == CLOSE) {
        Energy = Energy - 30;
        std::cout << Name << " strikes with his " << weaponName << std::endl;
        return (20 + Strength);
    }
    std::cout << Name << " out of power" << std::endl;
    return 0;
}

int Warrior::RangeAttack()
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
