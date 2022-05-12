/*
** Toy.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 9:41:10 AM 2021 julien.garsia
** Last update Wed Jan 19 9:20:07 AM 2021 julien.garsia
*/

#include "Toy.hpp"

Toy::Toy()
{
    type = BASIC_TOY;
    name = "toy";
    p.data = "";
}

Toy::Toy(ToyType typee, std::string namee, std::string file)
{
    type = typee;
    name = namee;
    p = Picture(file);
}

Toy::Toy(Toy const &t)
{
    type = t.getType();
    name = t.getName();
    p = Picture(t.p);
}

bool Toy::setAscii(std::string const f)
{
    p.getPictureFromFile(f);
    return true;
}

Toy &Toy::operator=(Toy const &t)
{
    type = t.getType();
    name = t.getName();
    p = t.p;

    return *this;
}

Toy::~Toy()
{
}
