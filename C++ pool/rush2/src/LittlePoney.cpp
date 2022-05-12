/*
** littlePoney.cpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:00:21 AM 2021 julien.garsia
** Last update Sun Jan 16 9:00:26 AM 2021 julien.garsia
*/

#include "LittlePoney.hpp"

LittlePoney::LittlePoney(const std::string &name):Toy(name)
{
    type = "Little Poney";
}

LittlePoney::~LittlePoney()
{
}

void LittlePoney::isTaken()
{
    std::cout << "yo man" << std::endl;
}
