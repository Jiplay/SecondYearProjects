/*
** Character.cpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 9:47:47 AM 2021 julien.garsia
** Last update Fri Jan 14 10:29:35 AM 2021 julien.garsia
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level) : 
    Level(1), Health(100), Energy(100), Strength(5), Stamina(5), Intelligence(5), Spirit(5), Agility(5)
{
    Name = name;
    Level = level;
    Classe = "Character";
    Race = "Human";
    Range = Character::CLOSE;
    
    std::cout << name << " Created" << std::endl;
}

Character::~Character()
{
}

int Character::CloseAttack()
{
    if (Energy >= 10 && Range == CLOSE) {
        std::cout << Name << " strikes with a wooden stick" << std::endl;
        Energy -= 10;
        return (10 + Strength);
    } else {
        std::cout << Name << " out of power" << std::endl;
        return 0;
    }
}

int Character::RangeAttack()
{
    if (Energy >= 10) {
        std::cout << Name << " tosses a stone" << std::endl;
        Energy -= 10;
        return (5 + Strength);
    } else {
        std::cout << Name << " out of power" << std::endl;
        return 0;
    }
}

void Character::Heal()
{
    if (Health + 50 >= 100)
        setHealth(100);
    else 
        setHealth(50 + Health);
    std::cout << Name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    setEnergy(100);
    std::cout << Name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    if (getPv() - damage <= 0) {;
        setHealth(0);
        std::cout << Name << " out of combat" << std::endl;
    } else {
        std::cout << Name << " takes " << damage << " damage" << std::endl;
        setHealth(getPv() -  damage);
    }
}

