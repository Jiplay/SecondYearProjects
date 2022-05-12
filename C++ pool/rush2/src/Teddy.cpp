/*
** Teddy.cpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:00:31 AM 2021 julien.garsia
** Last update Sun Jan 16 9:00:35 AM 2021 julien.garsia
*/

#include "Teddy.hpp"

Teddy::Teddy(const std::string &name):Toy(name)
{
    type = "Teddy";
}

Teddy::~Teddy()
{
}

void Teddy::isTaken()
{
    std::cout << "gra hu" << std::endl;
}
