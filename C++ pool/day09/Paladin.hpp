/*
** Paladin.hpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 2:28:28 PM 2021 julien.garsia
** Last update Fri Jan 14 3:11:30 PM 2021 julien.garsia
*/

#ifndef PALADIN_HPP_
# define PALADIN_HPP_

#include "Character.hpp"
#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin:public Warrior, public Priest
{
    public:
        Paladin(const std::string &name, int level);
        ~Paladin();
        void RestorePower();
        void Heal();
        int RangeAttack();
        int CloseAttack();
        int Intercept();
};


#endif /* !PALADIN_HPP_ */
