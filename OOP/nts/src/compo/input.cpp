/*
** output.cpp for NTS
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Feb 11 9:57:11 AM 2021 julien.garsia
** Last update Thu Feb 17 11:22:44 AM 2021 julien.garsia
*/

#include "input.hpp"

Input::Input(const std::string &s)
{
    _name = s;
    _value = "U";
    _type = "Input";
    // this->type = nts::AComponent::Type::O;
    _pins.push_back(nts::Pin{nts::Pin::I});
}

nts::Tristate Input::compute(std::size_t pin_num_this)
{
    std::cout << "input compute" << std::endl;
    // if (pin_num_this == 0)
    //     return (this->reset_pins());
    // if (pin_num_this != 1)
    //     throw Error ("Attempt to compute an invalid pin number", this->name + " " + std::to_string(pin_num_this));
    // return (this->pins[0].compute());
}

void Input::setLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
{
    if (pin_num_this != 1)
        return ;
    _pins[0].setCompo(component);
    _pins[0].setPin(pin_num_target);   
}

void Input::dump(void) const
{
    std::cout << "Input : " << _name << " " << _value << std::endl;
}

// const std::string &Input::save() const
// {
//     return (*(new std::string ("output " + this->_name)));
// }

void Input::simulate(std::size_t t)
{
}

nts::Tristate Input::getstate() const
{
    return _state;
}

std::string Input::getName()
{
    return _name;
}

int Input::getValue()
{
    if (_value == "U")
        return -1;
    return std::stoi(_value);
}

std::string Input::getType()
{
    return _type;
}

void Input::setstate(std::string state)
{
    if (state == "0")
        _state = nts::Tristate::FALSE;
    if (state == "1")
        _state = nts::Tristate::TRUE;
}

void Input::setValue(std::string value)
{
    _value = value;
}