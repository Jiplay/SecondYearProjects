/*
** main.hpp for NTS in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/OOP/NTS/src
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Feb 8 10:02:16 AM 2021 julien.garsia
** Last update Fri Mar 11 10:33:23 AM 2021 julien.garsia
*/

#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <iostream>
#include <map>
#include <regex>
#include <vector>
#include <iterator>

#include "pin.hpp"
#include "../exceptions/errors.hpp"

namespace nts
{
    enum Tristate {
        UNDEFINED = (- true) ,
        TRUE = true ,
        FALSE = false
    };
    class IComponent
    {
    public :
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual void dump() const = 0;
    };
    class Pin
    {
        public:
            enum Mode
            {
                U = 0,
                I,
                O,
                IO,
                VSS,
                VOD
            };

        public:
            Pin(Mode = U);
            Pin(const Pin &);
            ~Pin();
            void setPin(size_t p);
            void setCompo(nts::IComponent &obj);
            void setLink(std::string s);
            bool islinked() const;
            IComponent &getComponent() const;
            nts::Tristate compute();

            // const Pin &operator=(const Pin &);

        private:
            Mode _mode;
            IComponent *_component;
            size_t _otherPin;
            Tristate _state;
            bool _computed;
            std::string _linkedto;
    };
}

#endif /* !MAIN_HPP_ */
