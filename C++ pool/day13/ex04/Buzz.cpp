/*
** Buzz.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 1:32:28 PM 2021 julien.garsia
** Last update Tue Jan 18 1:44:44 PM 2021 julien.garsia
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string _name, std::string fpath)
{
    name = _name;
    type = BUZZ;
    p = Picture(fpath);
}

Buzz::~Buzz()
{
}
