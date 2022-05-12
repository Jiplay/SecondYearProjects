/*
** EPITECH PROJECT, 2021
** nts
** File description:
** c4011
*/

#include "c4011.hpp"
#include <vector>
#include <iostream>

c4011::c4011(std::string const &name)
{
    _name = name;
    _value = "U";
    _type = "CMP";
    _pins.push_back(nts::Pin{nts::Pin::I});
    _pins.push_back(nts::Pin{nts::Pin::I});
    _pins.push_back(nts::Pin{nts::Pin::O});
    _pins.push_back(nts::Pin{nts::Pin::O});
    _pins.push_back(nts::Pin{nts::Pin::I});
    _pins.push_back(nts::Pin{nts::Pin::I});
    _pins.push_back(nts::Pin{nts::Pin::VSS});
    _pins.push_back(nts::Pin{nts::Pin::I});
    _pins.push_back(nts::Pin{nts::Pin::I});
    _pins.push_back(nts::Pin{nts::Pin::O});
    _pins.push_back(nts::Pin{nts::Pin::O});
    _pins.push_back(nts::Pin{nts::Pin::I});
    _pins.push_back(nts::Pin{nts::Pin::I});
    _pins.push_back(nts::Pin{nts::Pin::VOD});
}

c4011::~c4011(void)
{
}

nts::Tristate c4011::parsing_vector(std::vector<int> v, std::vector<int> v1)
{
    int a = 0;
    int b = 0;

    for (std::vector<int>::const_iterator i = v1.begin(); i != v1.end(); ++i) {
        nts::IComponent &x = _pins[v[a]].getComponent();
        nts::IComponent &x1 = _pins[v[a+1]].getComponent();
        nts::IComponent &x2 = _pins[v1[b]].getComponent();

        if (dynamic_cast<Acomponent *>(&x)->getValue() + dynamic_cast<Acomponent *>(&x1)->getValue() == 2)
            dynamic_cast<Acomponent *>(&x2)->setstate("0");
        else
            dynamic_cast<Acomponent *>(&x2)->setstate("1");

        a+=2;
        b++;
    }
}

nts::Tristate c4011::compute(std::size_t pin)
{
    int a = 0;
    int b = 0;

    std::vector<int> v_input;
    std::vector<int> v_output;
    std::vector<nts::Pin>::iterator it;

    if (pin > 0 && pin < 14 && pin != 7)
    {
        for(it = _pins.begin(); it != _pins.end(); ++it)
        {
            if (it->islinked() == true)
            {
                nts::IComponent &x = it->getComponent();
                if (dynamic_cast<Acomponent *>(&x)->getType() == "Input")
                {
                    v_input.push_back(a);        
                }
                if (dynamic_cast<Acomponent *>(&x)->getType() == "Output")
                    v_output.push_back(a);
            }
            b++;
        }
        return parsing_vector(v_input, v_output);
    }
    throw Errors("Error : Invalid pin number",  ".");
}

void c4011::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > 0 && pin < 14 && pin != 7) {
        pin--;
        _pins[pin].setCompo(other);
        _pins[pin].setPin(otherPin);
        _pins[pin].setLink(dynamic_cast<Acomponent *>(&other)->getName());
    }
}

void c4011::simulate(std::size_t t)
{

}

void c4011::dump() const
{
    std::cout << "COMPONENT : " << _name << " " << _value << std::endl;
}

nts::Tristate c4011::getstate() const
{
    return nts::UNDEFINED;
}

std::string c4011::getName()
{
    return _name;
}

int c4011::getValue()
{
    if (_value == "U")
        return -1;
    return std::stoi(_value);
}

std::string c4011::getType()
{
    return _type;
}

void c4011::setstate(std::string state)
{
}

void c4011::setValue(std::string value)
{
    _value = value;
}