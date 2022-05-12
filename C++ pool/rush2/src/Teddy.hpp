/*
** Teddy.hpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:00:37 AM 2021 julien.garsia
** Last update Sun Jan 16 9:00:41 AM 2021 julien.garsia
*/

#ifndef TEDDY_HPP_
# define TEDDY_HPP_

#include "Toy.hpp"

class Teddy:public Toy {
public:
    Teddy(const std::string &name);
    ~Teddy();
    void isTaken();
};

#endif /* !TEDDY_HPP_ */
