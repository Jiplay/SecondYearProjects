/*
** SuperMutant.hpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 12:50:38 PM 2021 julien.garsia
** Last update Sat Jan 15 12:59:24 PM 2021 julien.garsia
*/

#ifndef SUPERMUTANT_HPP_
# define SUPERMUTANT_HPP_

#include "AEnemy.hpp"

class SuperMutant : public AEnemy
{
    public:
        SuperMutant();
        ~SuperMutant();
        void takeDamage(int damage) override;
    private:
        
};

#endif /* !SUPERMUTANT_HPP_ */
