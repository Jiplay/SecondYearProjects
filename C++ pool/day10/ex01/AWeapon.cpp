/*
** AWeapon.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 11:01:02 AM 2021 julien.garsia
** Last update Sat Jan 15 1:58:35 PM 2021 julien.garsia
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) : _name(name), _ap(apcost), _damage(damage)
{
}

AWeapon::~AWeapon()
{
}
