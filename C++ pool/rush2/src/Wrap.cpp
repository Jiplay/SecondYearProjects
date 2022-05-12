/*
** Wrap.cpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:26:29 AM 2021 julien.garsia
** Last update Sun Jan 16 10:00:16 AM 2021 julien.garsia
*/

#include "Wrap.hpp"

Wrap::Wrap(std::string const &name) : Object(name)
{
    open = true;
    b = NULL;
}

Wrap::~Wrap()
{
    delete b;
}


