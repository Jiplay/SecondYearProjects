/*
** GiftPaper.cpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:26:39 AM 2021 julien.garsia
** Last update Sun Jan 16 9:59:48 AM 2021 julien.garsia
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper(const std::string &name) : Wrap(name)
{
    type = "GiftPaper";
    b = NULL;
}

GiftPaper::~GiftPaper()
{
    delete b;
}

void GiftPaper::WrapMeThat(Object *_toy)
{
    if (!b) {
        b = _toy;
        open = false;
        std::cout << "tuuuut tuuut tuut" << std::endl;
    }
}

Object *GiftPaper::getObjet()
{
    return b;
}

Object *GiftPaper::openMe()
{
    open = true;
    return b;
}

void GiftPaper::closeMe()
{
    open = false;
}
