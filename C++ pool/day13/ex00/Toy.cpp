/*
** Toy.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 9:41:10 AM 2021 julien.garsia
** Last update Tue Jan 18 10:46:29 PM 2021 julien.garsia
*/

#include "Toy.hpp"

Toy::Toy()
{
    type = BASIC_TOY;
    name = "toy";
    p = Picture();
}

Toy::Toy(ToyType typee, std::string namee, std::string file)
{
    type = typee;
    name = namee;
    p = Picture(file);
}

Toy::~Toy()
{
}

bool Toy::setAscii(std::string const f)
{

    p.getPictureFromFile(f);
}
