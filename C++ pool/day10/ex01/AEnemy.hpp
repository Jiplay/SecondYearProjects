/*
** AEnemy.hpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 12:45:53 PM 2021 julien.garsia
** Last update Mon Jan 17 2:37:33 PM 2021 julien.garsia
*/

#ifndef AENEMY_HPP_
# define AENEMY_HPP_

#include <iostream>

class AEnemy {
    public:
        AEnemy(int hp, const std::string &type);
        virtual ~AEnemy();

        virtual void takeDamage(int damage);
        std::string const getType() const { return _Type; }
        int getHP() const { return _Hp; }

    protected:
        const std::string _Type;
        int _Hp;
};

#endif /* !AENEMY_HPP_ */
