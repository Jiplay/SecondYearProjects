/*
** errors.cpp for NTS in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/OOP/NTS/B-OOP-400-PAR-4-1-tekspice-ibrahim.zafar/src/exceptions
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Feb 19 10:27:25 AM 2021 julien.garsia
** Last update Tue Feb 22 10:13:38 AM 2021 julien.garsia
*/

#include "errors.hpp"

Errors::Errors(std::string const &msg, std::string const &indi) noexcept
{
    _msg = msg;
    _indi = indi;
}

const char *Errors::what() const noexcept
{
    return _msg.c_str();
}
