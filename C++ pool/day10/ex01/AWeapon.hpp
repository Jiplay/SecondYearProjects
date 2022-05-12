/*
** AWeapon.hpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 11:00:57 AM 2021 julien.garsia
** Last update Sat Jan 15 1:58:08 PM 2021 julien.garsia
*/

#ifndef AWEAPON_HPP_
# define AWEAPON_HPP_

#include <iostream>

class AWeapon {
    public:
        AWeapon(const std::string &name, int apcost, int damage);
        ~AWeapon();

        std::string const &getName() const {return _name; }
        int getAPCost() const { return _ap; }
        int getDamage() const { return _damage; }
        virtual void attack() const = 0;
    
    protected:
        const std::string _name;
        int _ap;
        int _damage;
};

#endif /* !AWEAPON_HPP_ */
