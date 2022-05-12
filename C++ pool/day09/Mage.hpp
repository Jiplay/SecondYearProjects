/*
** Mage.hpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia 
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 10:46:29 AM 2021 julien.garsia
** Last update Fri Jan 14 10:50:13 AM 2021 julien.garsia
*/

#ifndef MAGE_HPP_
# define MAGE_HPP_

#include "Character.hpp"

class Mage:public Character 
{
    public:
        Mage(const std::string &name, int level);
        ~Mage();
        int CloseAttack();
        void RestorePower();
        int RangeAttack();
};

#endif /* !MAGE_HPP_ */
