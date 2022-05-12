/*
** output.cpp for NTS
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Feb 11 9:57:11 AM 2021 julien.garsia
** Last update Fri Feb 11 10:31:56 AM 2021 julien.garsia
*/

#include "output.hpp"

Output::Output(const std::string &s)
{
    _name = s;
    _value = "U";
    _type = "Output";
    // this->type = nts::AComponent::Type::O;
    _pins.push_back(nts::Pin{nts::Pin::I});
}

nts::Tristate Output::compute(std::size_t pin_num_this)
{
    std::cout << "output compute" << std::endl;
    // if (pin_num_this == 0)
    //     return (this->reset_pins());
    // if (pin_num_this != 1)
    //     throw Error ("Attempt to compute an invalid pin number", this->name + " " + std::to_string(pin_num_this));
    // return (this->pins[0].compute());
}

void Output::setLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
{
    if (pin_num_this != 1)
        return ;
    _pins[0].setCompo(component);        
    _pins[0].setPin(pin_num_target);        
}

void Output::dump(void) const
{
    std::cout << "Output : " << _name << " " << _state << std::endl;
}

// const std::string &Output::save() const
// {
//     return (*(new std::string ("output " + this->_name)));
// }

void Output::simulate(std::size_t t)
{
}

nts::Tristate Output::getstate() const
{
    return _state;
}

std::string Output::getName()
{
    return _name;
}

int Output::getValue()
{
    if (_value == "U")
        return -1;
    return std::stoi(_value);
}

std::string Output::getType()
{
    return _type;
}

void Output::setstate(std::string state)
{
    if (state == "0")
        _state = nts::Tristate::FALSE;
    if (state == "1")
        _state = nts::Tristate::TRUE;
}

void Output::setValue(std::string value)
{
    _value = value;
}