/*
** Buzz.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 1:32:28 PM 2021 julien.garsia
** Last update Wed Jan 19 11:50:49 AM 2021 julien.garsia
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string const _name, std::string const fpath)
{
    name = _name;
    type = BUZZ;
    p = Picture(fpath);
}

Buzz::~Buzz()
{
}
