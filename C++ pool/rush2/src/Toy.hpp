/*
** Toy.hpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:00:49 AM 2021 julien.garsia
** Last update Sun Jan 16 9:00:53 AM 2021 julien.garsia
*/

#ifndef TOY_HPP_
# define TOY_HPP_

#include <iostream>
#include <string>
#include "Object.hpp"

class Toy : public Object
{
    public:
        Toy(const std::string &name);
        virtual ~Toy();
        virtual void isTaken() = 0;
};

#endif /* !TOY_HPP_ */
