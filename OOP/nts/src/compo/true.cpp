/*
** true.cpp for NTS
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Mar 2 11:24:08 AM 2021 julien.garsia
** Last update Fri Mar 4 10:32:42 AM 2021 julien.garsia
*/

#include "true.hpp"

True::True(std::string const &name)
{
    _name = name;
    _value = "U";
    _type = "true";
    _state = nts::TRUE;
}

nts::Tristate True::compute(std::size_t pin)
{
    return _state;
}

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > 0 && pin < 14 && pin != 7) {
       dynamic_cast<Acomponent *>(&other)->setstate("1");
    }
}

void True::simulate(std::size_t t)
{

}

void True::dump() const
{
    std::cout << "COMPONENT : " << _name << " " << _state << std::endl;
}

nts::Tristate True::getstate() const
{
    return nts::UNDEFINED;
}

std::string True::getName()
{
    return _name;
}

int True::getValue()
{
    if (_value == "U")
        return -1;
    return std::stoi(_value);
}

std::string True::getType()
{
    return _type;
}

void True::setstate(std::string state)
{
}

void True::setValue(std::string value)
{
    _value = value;
}