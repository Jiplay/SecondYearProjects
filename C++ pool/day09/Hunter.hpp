/*
** Hunter.hpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 3:37:52 PM 2021 julien.garsia
** Last update Thu Jan 14 3:37:52 PM 2021 julien.garsia
*/

#ifndef HUNTER_HPP_
# define HUNTER_HPP_

#include "Character.hpp"
#include "Warrior.hpp"

class Hunter : public Warrior
{
    public:
        Hunter(const std::string &name, int level);
        ~Hunter();
        int CloseAttack();
        void RestorePower();
        void Heal();
        int RangeAttack();

};

#endif /* !HUNTER_HPP_ */
