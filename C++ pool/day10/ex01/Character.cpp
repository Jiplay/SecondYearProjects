/*
** Character.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD10-julien.garsia/ex01
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 1:06:11 PM 2021 julien.garsia
** Last update Sat Jan 15 3:27:55 PM 2021 julien.garsia
*/

#include "Character.hpp"

Character::Character(const std::string &name) : _name(&name), _Ap(40)
{
}

Character::~Character()
{
}

void Character::equip(AWeapon *weapon)
{
    _weapon = weapon;
}

void Character::recoverAP()
{
    _Ap += 10;
    if (_Ap > 40)
        _Ap = 40;
}

void Character::setAp(int nb)
{
    _Ap = nb;
}

void Character::attack(AEnemy *target)
{
    if (_weapon != NULL) {
        std::cout << *_name << " attacks " << target->getType() << " with a " << _weapon->getName() << std::endl;
        _weapon->attack();
        _Ap = _Ap - _weapon->getAPCost();
        target->takeDamage(_weapon->getDamage());
    }
}

std::ostream &operator<<(std::ostream &s, const Character &c)
{
    if (c.getWeapon() != NULL) {
        s << c.getName() << " has " << c.getAp() << " AP and wields a " << c.getWeapon()->getName() << std::endl;
    } else
        s << c.getName() << " has " << c.getAp() << " AP and is unarmed" << std::endl;

    return s;
}
