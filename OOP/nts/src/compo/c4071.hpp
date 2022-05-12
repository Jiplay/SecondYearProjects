/*
** EPITECH PROJECT, 2021
** nts
** File description:
** c4071
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include "Icomponent.hpp"
#include "Acomponent.hpp"
#include "pin.hpp"

    class c4071 : public Acomponent
    {
    public:
        c4071(const std::string &name);
        ~c4071();
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

#endif /* !C4071_HPP_ */