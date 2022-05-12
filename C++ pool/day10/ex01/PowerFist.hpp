/*
** PowerFist.hpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD10-julien.garsia/ex01
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 12:36:24 PM 2021 julien.garsia
** Last update Sat Jan 15 1:47:34 PM 2021 julien.garsia
*/

#ifndef POWERFIST_HPP_
# define POWERFIST_HPP_

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
    public:
        PowerFist();
        ~PowerFist();
        void attack() const final;
    private:
};

#endif /* !POWERFIST_HPP_ */
