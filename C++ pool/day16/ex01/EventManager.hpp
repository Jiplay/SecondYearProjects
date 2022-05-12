/*
** EventManager.hpp for B-CPP-300-PAR-3-2-CPPD16-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 21 2:24:22 PM 2021 julien.garsia
** Last update Sat Jan 22 10:43:16 AM 2021 julien.garsia
*/

#ifndef EVENTMANAGER_HPP_
# define EVENTMANAGER_HPP_

#include "Event.hpp"

class EventManager {
    public:
        EventManager();
        EventManager(EventManager const &other);
        ~EventManager();
        EventManager &operator=(EventManager const &rhs);

        void addEvent(const Event &e);
        void dumpEvents() const;

        void removeEventsAt(unsigned int time);
        void dumpEventAt(unsigned int time) const ;

        void addTime(unsigned int time);
        void addEventList(std::list<Event> &events);
    private:
        std::list<Event> _events;
        unsigned int _currentTime;
};

#endif /* !EVENTMANAGER_HPP_ */
