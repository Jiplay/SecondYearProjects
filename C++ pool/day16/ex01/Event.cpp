/*
** Event.cpp for B-CPP-300-PAR-3-2-CPPD16-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 21 2:24:18 PM 2021 julien.garsia
** Last update Sat Jan 22 9:18:10 AM 2021 julien.garsia
*/

#include "Event.hpp"

Event::Event()
{
    _time = 0;
    _event = "";
}

Event::Event(unsigned int time, const std::string &event)
{
    _time = time;
    _event = event;
}

Event::Event(const Event &other)
{
    _time = other._time;
    _event = other._event;
}

Event &Event::operator=(const Event &rhs)
{
    _time = rhs._time;
    _event = rhs._event;
    return *this;
}

Event::~Event()
{
}
