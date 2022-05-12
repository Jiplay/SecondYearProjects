/*
** EPITECH PROJECT, 2021
** nts
** File description:
** c4071
*/

#include "c4071.hpp"
#include <vector>
#include <iostream>

c4071::c4071(std::string const &name)
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

c4071::~c4071(void)
{
}

nts::Tristate c4071::parsing_vector(std::vector<int> v, std::vector<int> v1)
{
    int a = 0;
    int b = 0;

    for (std::vector<int>::const_iterator i = v1.begin(); i != v1.end(); ++i) {
        nts::IComponent &x = _pins[v[a]].getComponent();
        nts::IComponent &x1 = _pins[v[a+1]].getComponent();
        nts::IComponent &x2 = _pins[v1[b]].getComponent();

        if (dynamic_cast<Acomponent *>(&x)->getValue() + dynamic_cast<Acomponent *>(&x1)->getValue() == 0)
            dynamic_cast<Acomponent *>(&x2)->setstate("0");
        else
            dynamic_cast<Acomponent *>(&x2)->setstate("1");

        a+=2;
        b++;
    }
}

nts::Tristate c4071::compute(std::size_t pin)
{
    int a = 0;
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
                if (dynamic_cast<Acomponent *>(&x)->getType()  == "Output")
                    v_output.push_back(a);
            }
            a++;
        }
        return parsing_vector(v_input, v_output);
    }
    throw Errors("Error : Invalid pin number",  ".");
}

void c4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > 0 && pin < 14 && pin != 7) {
        pin--;
        _pins[pin].setCompo(other);
        _pins[pin].setPin(otherPin);
        _pins[pin].setLink(dynamic_cast<Acomponent *>(&other)->getName());
    }
}

void c4071::simulate(std::size_t t)
{

}

void c4071::dump() const
{
    std::cout << "COMPONENT : " << _name << " " << _value << std::endl;
}

nts::Tristate c4071::getstate() const
{
    return nts::UNDEFINED;
}

std::string c4071::getName()
{
    return _name;
}

int c4071::getValue()
{
    if (_value == "U")
        return -1;
    return std::stoi(_value);
}

std::string c4071::getType()
{
    return _type;
}

void c4071::setstate(std::string state)
{
}

void c4071::setValue(std::string value)
{
    _value = value;
}