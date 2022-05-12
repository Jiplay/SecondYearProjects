/*
** PlasmaRifle.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 11:15:31 AM 2021 julien.garsia
** Last update Sat Jan 15 1:45:08 PM 2021 julien.garsia
*/

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon(std::string("Plasma Rifle"), 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const 
{
    std::cout << "* piouuu piouuu piouuu *" <<std::endl;
}
