/*
** cond_var.cpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed May 12 11:20:01 AM 2021 julien.garsia
** Last update Thu May 12 11:34:33 AM 2021 julien.garsia
*/

#include "../include/encapsulation/conditionnal_var/cond_var.hpp"

Cond_var::Cond_var()
{
}

Cond_var::~Cond_var()
{
}

void Cond_var::notify_all()
{
    _cond_var.notify_all();
}

void Cond_var::notify_one()
{
    _cond_var.notify_one();
}

void Cond_var::wait(std::unique_lock<std::mutex> m)
{
    _cond_var.wait(m);
}
