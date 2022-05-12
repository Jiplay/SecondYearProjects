/*
** Borg.hpp for B-CPP-300-PAR-3-2-CPPD07M-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD07M-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 11:26:16 AM 2021 julien.garsia
** Last update Wed Jan 12 1:58:22 PM 2021 julien.garsia
*/

#ifndef BORG_HPP_
# define BORG_HPP_

#include "Federation.hpp"

namespace Borg
{
    class Ship
    {
    public:
        int _side;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;

        Ship();
        void setupCore(WarpSystem::Core *c);
        Destination getLocation();
        void checkCore();
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
    };    
}

#endif /* !BORG_HPP_ */
