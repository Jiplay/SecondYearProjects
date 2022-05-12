/*
** c4030.cpp for NTS in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/OOP/NTS/B-OOP-400-PAR-4-1-tekspice-ibrahim.zafar/src/compo
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Mar 2 10:14:29 AM 2021 julien.garsia
** Last update Wed Mar 2 10:34:01 AM 2021 julien.garsia
*/

#include "c4030.hpp"
#include <vector>
#include <iostream>

c4030::c4030(std::string const &name)
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

c4030::~c4030(void)
{
}

nts::Tristate c4030::parsing_vector(std::vector<int> v, std::vector<int> v1)
{
    int a = 0;
    int b = 0;

    for (std::vector<int>::const_iterator i = v1.begin(); i != v1.end(); ++i) {
        nts::IComponent &x = _pins[v[a]].getComponent();
        nts::IComponent &x1 = _pins[v[a+1]].getComponent();
        nts::IComponent &x2 = _pins[v1[b]].getComponent();

        if (dynamic_cast<Acomponent *>(&x)->getValue() + dynamic_cast<Acomponent *>(&x1)->getValue() == 1)
            dynamic_cast<Acomponent *>(&x2)->setstate("1");
        else
            dynamic_cast<Acomponent *>(&x2)->setstate("0");
        a+=2;
        b++;
    }
}

nts::Tristate c4030::compute(std::size_t pin)
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
                if (dynamic_cast<Acomponent *>(&x)->getType() == "Output")
                    v_output.push_back(a);
            }
            a++;
        }
        return parsing_vector(v_input, v_output);
    }
    throw Errors("Error : Invalid pin number",  ".");
}

void c4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > 0 && pin < 14 && pin != 7) {
        pin--;
        _pins[pin].setCompo(other);
        _pins[pin].setPin(otherPin);
        _pins[pin].setLink(dynamic_cast<Acomponent *>(&other)->getName());
    }
}

void c4030::simulate(std::size_t t)
{

}

void c4030::dump() const
{
    std::cout << "COMPONENT : " << _name << " " << _value << std::endl;
}

nts::Tristate c4030::getstate() const
{
    return nts::UNDEFINED;
}

std::string c4030::getName()
{
    return _name;
}

int c4030::getValue()
{
    if (_value == "U")
        return -1;
    return std::stoi(_value);
}

std::string c4030::getType()
{
    return _type;
}

void c4030::setstate(std::string state)
{
}

void c4030::setValue(std::string value)
{
    _value = value;
}
