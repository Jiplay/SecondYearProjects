/*
** Character.hpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD10-julien.garsia/ex01
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 1:06:09 PM 2021 julien.garsia
** Last update Sat Jan 15 2:59:29 PM 2021 julien.garsia
*/

#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
    public:
        Character(const std::string &name);
        ~Character();

        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);
        std::string const getName() const {return *_name; }
        int getAp() const {return _Ap; }
        AWeapon *getWeapon() const {return _weapon; }
        void setAp(int nb);

    private:
        const std::string *_name;
        AWeapon *_weapon;
        int _Ap;
};

std::ostream &operator<<(std::ostream &s, const Character &c);

#endif /* !CHARACTER_HPP_ */
