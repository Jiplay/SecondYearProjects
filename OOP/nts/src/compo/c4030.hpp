/*
** c4030.hpp for NTS in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/OOP/NTS/B-OOP-400-PAR-4-1-tekspice-ibrahim.zafar/src/compo
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Mar 2 10:14:27 AM 2021 julien.garsia
** Last update Wed Mar 2 10:34:05 AM 2021 julien.garsia
*/

#ifndef C4030_HPP_
#define C4030_HPP_

#include "Icomponent.hpp"
#include "Acomponent.hpp"
#include "pin.hpp"

    class c4030 : public Acomponent
    {
    public:
        c4030(const std::string &name);
        ~c4030();
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

#endif /* !C4030_HPP_ */
