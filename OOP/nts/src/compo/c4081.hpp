/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-tekspice-ibrahim.zafar
** File description:
** c4081
*/

#ifndef C4081_HPP_
#define C4081_HPP_

#include "Icomponent.hpp"
#include "Acomponent.hpp"
#include "pin.hpp"

    class c4081 : public Acomponent
    {
    public:
        c4081(const std::string &name);
        ~c4081();
        nts::Tristate parsing_vector(std::vector<int> v, std::vector<int> v1);
        nts::Tristate compute(std::size_t pin = 1);
        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
        nts::Tristate getstate() const;
        std::string getName();
        int getValue();
        std::string getType();
        void setstate(std::string state);
        void setValue(std::string value);
    private:
        std::vector<nts::Pin> _pins;
    };

#endif /* !C4081_HPP_ */
