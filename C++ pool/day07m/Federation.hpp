/*
** Federation.hpp for B-CPP-300-PAR-3-2-CPPD07M-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 9:05:44 AM 2021 julien.garsia
** Last update Wed Jan 12 2:06:57 PM 2021 julien.garsia
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation
{

    namespace Starfleet
    {
        class Captain
        {
        public:
            std::string _name;
            int _age;
            Captain(std::string name);
            std::string getName();
            int getAge();
            void setAge(int age);
        };
        class Ship
        {
            public:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                Destination _location;
                Destination _home;
                WarpSystem::Core *_core;
                Federation::Starfleet::Captain *_captain;

                Ship(int length, int width, std::string name, short maxWarp);
                Destination getLocation();
                void setupCore(WarpSystem::Core *c);
                void checkCore(void);
                void promote(Federation::Starfleet::Captain *c);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
        };
        class Ensign
        {
        private:
            std::string _name;
        public:
            Ensign(std::string name);
        };
    }
        class Ship
        {
        private:
            int _length;
            int _width;
            std::string _name;
            WarpSystem::Core *_core;
            short _maxWarp;
            Destination _location;
            Destination _home;
        public:
            void setupCore(WarpSystem::Core *c);
            Destination getLocation();
            void checkCore(void);
            Ship(int length, int width, std::string name);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
        };
}

#endif /* !FEDERATION_HPP_ */
