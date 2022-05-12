/*
** PlasmaRifle.hpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 11:15:33 AM 2021 julien.garsia
** Last update Sat Jan 15 1:44:55 PM 2021 julien.garsia
*/

#ifndef PLASMARIFLE_HPP_
# define PLASMARIFLE_HPP_

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    public:
        PlasmaRifle();
        ~PlasmaRifle();
        void attack() const final;
    private:
};

#endif /* !PLASMARIFLE_HPP_ */
