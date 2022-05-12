/*
** Woody.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 1:32:16 PM 2021 julien.garsia
** Last update Wed Jan 19 11:51:38 AM 2021 julien.garsia
*/

#include "Woody.hpp"

Woody::Woody(std::string const _name, std::string const fpath)
{
    name = _name;
    type = WOODY;
    p = Picture(fpath);
}

Woody::~Woody()
{
}
