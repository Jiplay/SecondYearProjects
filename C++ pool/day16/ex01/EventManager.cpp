/*
** EventManager.cpp for B-CPP-300-PAR-3-2-CPPD16-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 21 2:24:15 PM 2021 julien.garsia
** Last update Sat Jan 22 3:24:47 PM 2021 julien.garsia
*/

#include "EventManager.hpp"

EventManager::EventManager()
{
    _currentTime = 0;
}

EventManager::EventManager(EventManager const &other)
{
    if (_events.empty() == true)
        _events.clear();
    _events = other._events;
    _currentTime = other._currentTime;
}

EventManager::~EventManager()
{
    _events.clear();
}

EventManager &EventManager::operator=(EventManager const &rhs)
{
    if (_events.empty() == true)
        _events.clear();
    _events = rhs._events;
    _currentTime = rhs._currentTime;
    return *this;
}

inline bool sortTime(const Event &event1, const Event &event2)
{
    if (event1.getTime() <= event2.getTime())
        return true;
    return false;
}

void EventManager::addEvent(const Event &e)
{
    _events.push_back(e);
    _events.sort(sortTime);
}

void EventManager::dumpEvents() const
{
    for (Event it : _events)
        std::cout << it.getTime() << ": " << it.getEvent() << std::endl;
}

void EventManager::removeEventsAt(unsigned int time)
{
    std::list<Event>::const_iterator it = _events.begin();

    while (it != _events.end()) {
        if (it->getTime() == time){
            it = _events.erase(it);
            it--;
        }
        it++;
    }
}

void EventManager::dumpEventAt(unsigned int time) const
{
    std::list<Event>::const_iterator it = _events.begin();

    while (it != _events.end()) {
        if (it->getTime() == time)
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
        it++;
    }
}

void EventManager::addTime(unsigned int time)
{
    auto it = _events.begin();
    _currentTime += time;
    while (it != _events.end() && it->getTime() <= _currentTime) {
        std::cout << it->getEvent() << std::endl;
        it = _events.erase(it);
        it--;
        it++;
    }
}

void EventManager::addEventList(std::list<Event> &events)
{
    for (std::list<Event>::const_iterator it = events.begin(); it != events.end(); ++it){
        if (it->getTime() >= _currentTime)
            _events.push_back(*it);
    }
    _events.sort(sortTime);
}
