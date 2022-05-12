/*
** Woody.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 1:32:16 PM 2021 julien.garsia
** Last update Tue Jan 18 1:41:10 PM 2021 julien.garsia
*/

#include "Woody.hpp"

Woody::Woody(std::string _name, std::string fpath)
{
    name = _name;
    type = WOODY;
    p = Picture(fpath);
}

Woody::~Woody()
{
}
