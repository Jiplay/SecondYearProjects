/*
** Warrior.hpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 10:30:55 AM 2021 julien.garsia
** Last update Fri Jan 14 10:32:06 AM 2021 julien.garsia
*/

#ifndef WARRIOR_HPP_
# define WARRIOR_HPP_

#include "Character.hpp"

class Warrior:virtual public Character 
{
    protected:
        std::string weaponName;

    public:
        Warrior(const std::string &name, int level);
        ~Warrior();
        int CloseAttack();
        int RangeAttack();
};

#endif /* !WARRIOR_HPP_ */
