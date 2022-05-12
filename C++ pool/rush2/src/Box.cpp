/*
** Box.cpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:26:49 AM 2021 julien.garsia
** Last update Sun Jan 16 9:26:57 AM 2021 julien.garsia
*/

#include "Box.hpp"

Box::Box(const std::string &name) : Wrap(name)
{
    type = "Box";
}

Box::~Box()
{
}

Object *Box::getObjet()
{
    return b;
}

void Box::WrapMeThat(Object *object)
{
    if (!b && open == true) {
        b = object;
        open = false;
        std::cout << "tuuuut tuuut tuut" << std::endl;
    }
}

void Box::closeMe()
{
    this->open = false;
}

Object *Box::openMe()
{
    this->open = open;
    return b;
}
