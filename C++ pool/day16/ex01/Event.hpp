/*
** Event.hpp for B-CPP-300-PAR-3-2-CPPD16-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 21 2:24:12 PM 2021 julien.garsia
** Last update Fri Jan 21 3:26:50 PM 2021 julien.garsia
*/

#ifndef EVENT_HPP_
# define EVENT_HPP_

#include <string>
#include <list>
#include <iostream>

class Event {
    public:
        Event();
        Event(unsigned int time, const std::string &event);
        Event(const Event &other);
        ~Event();
        Event &operator=(const Event &rhs);

        unsigned int getTime() const {return _time;}
        const std::string &getEvent() const {return _event;}
        void setEvent(const std::string &event) {_event = event;}
        void setTime(unsigned int t) {_time = t;}

    private:
        unsigned int _time;
        std::string _event;
};

#endif /* !EVENT_HPP_ */
