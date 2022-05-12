/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-tekspice-ibrahim.zafar
** File description:
** pin
*/

#include "pin.hpp"
#include "Acomponent.hpp"

nts::Pin::Pin(Mode mode)
{
    _mode = mode;
    _component = NULL;
    _otherPin = 0;
    _state = UNDEFINED;
    _computed = false;
}

nts::Pin::Pin(const Pin &other)
{
}

nts::Pin::~Pin()
{
}

void nts::Pin::setPin(size_t p)
{
    _otherPin = p;
}

void nts::Pin::setCompo(nts::IComponent &obj)
{
    _component = &obj;
}

void nts::Pin::setLink(std::string s)
{
    _linkedto = s;
}


bool nts::Pin::islinked() const
{
     if (_component)
        return true;
    return false;
}

nts::IComponent &nts::Pin::getComponent() const
{
    return *_component;
}

nts::Tristate nts::Pin::compute()
{
    if (_state != UNDEFINED)
        return _state;
    if (_component != NULL)
    {
        if (_computed == false)
        {
            _computed = true;
            return (_component->compute(_otherPin));
        }
    }
    throw Errors("link pin which isn't a pin", "omg");
}

// const nts::Pin &Pin::operator=(const Pin &other)
// {
//     return *this;
// }