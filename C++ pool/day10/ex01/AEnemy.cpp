/*
** AEnemy.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD10-julien.garsia/ex01
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 12:45:50 PM 2021 julien.garsia
** Last update Mon Jan 17 9:09:12 PM 2021 julien.garsia
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) : _Type(type), _Hp(hp)
{
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
    _Hp -= damage;
    if (_Hp <= 0)
        this->~AEnemy();
}
