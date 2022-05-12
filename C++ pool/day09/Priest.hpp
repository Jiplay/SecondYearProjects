/*
** Priest.hpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 11:47:17 AM 2021 julien.garsia
** Last update Fri Jan 14 12:04:50 PM 2021 julien.garsia
*/

#ifndef PRIEST_HPP_
# define PRIEST_HPP_

#include "Character.hpp"

class Priest : virtual public Character
{
    public:
        Priest(const std::string &name, int level);
        ~Priest();
        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
};

#endif /* !PRIEST_HPP_ */
