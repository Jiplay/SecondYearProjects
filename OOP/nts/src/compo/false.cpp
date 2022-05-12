/*
** true.cpp for NTS
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Mar 2 11:24:08 AM 2021 julien.garsia
** Last update Thu Mar 3 10:38:28 AM 2021 julien.garsia
*/

#include "false.hpp"

False::False(std::string const &name)
{
    _name = name;
    _value = "U";
    _type = "true";
    _state = nts::FALSE;
}

nts::Tristate False::compute(std::size_t pin)
{
    return _state;
}

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > 0 && pin < 14 && pin != 7) {
        dynamic_cast<Acomponent *>(&other)->setstate("0");
    }
}

void False::simulate(std::size_t t)
{

}

void False::dump() const
{
    std::cout << "COMPONENT : " << _name << " " << _state << std::endl;
}

nts::Tristate False::getstate() const
{
    return nts::FALSE;
}

std::string False::getName()
{
    return _name;
}

int False::getValue()
{
    if (_value == "U")
        return -1;
    return std::stoi(_value);
}

std::string False::getType()
{
    return _type;
}

void False::setstate(std::string state)
{
}

void False::setValue(std::string value)
{
    _value = value;
}