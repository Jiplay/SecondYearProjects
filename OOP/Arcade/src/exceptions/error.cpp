/*
** error.cpp for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Mar 16 10:55:30 AM 2021 julien.garsia
** Last update Wed Mar 16 11:19:07 AM 2021 julien.garsia
*/

#include "error.hpp"

ArcadeError::ArcadeError(std::string const &m, std::string const &c)
{
    _msg = m;
    _cmp = c;
}

CoreError::CoreError(std::string const &m, std::string const &c) : ArcadeError(m, c)
{

}
