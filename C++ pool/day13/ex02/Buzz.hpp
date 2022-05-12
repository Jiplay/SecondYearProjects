/*
** Buzz.hpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 1:32:22 PM 2021 julien.garsia
** Last update Wed Jan 19 11:52:00 AM 2021 julien.garsia
*/

#ifndef BUZZ_HPP_
# define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy
{
    public:
        Buzz(std::string const _name, std::string const fpath = "buzz.txt");
        ~Buzz();

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
