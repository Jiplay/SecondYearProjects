/*
** mutex.cpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue May 4 9:57:03 AM 2021 julien.garsia
** Last update Wed May 4 9:59:29 AM 2021 julien.garsia
*/

#include "../include/encapsulation/mutex/mutex.hpp"

Mutex::Mutex()
{

}

Mutex::~Mutex()
{

}

void Mutex::lock()
{
    _m.lock();
}

void Mutex::unlock()
{
    _m.unlock();
}

bool Mutex::try_lock()
{
    return (_m.try_lock());
}
