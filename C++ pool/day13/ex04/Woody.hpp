/*
** Woody.hpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 1:32:10 PM 2021 julien.garsia
** Last update Tue Jan 18 1:42:19 PM 2021 julien.garsia
*/

#ifndef WOODY_HPP_
# define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy
{
    public:
        Woody(std::string _name, std::string fpath = "woody.txt");
        ~Woody();

    private:
};

#endif /* !WOODY_HPP_ */
