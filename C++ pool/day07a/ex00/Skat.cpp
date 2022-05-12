/*
** Skat.cpp for B-CPP-300-PAR-3-2-CPPD07A-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD07A-julien.garsia/ex00
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 2:33:09 PM 2021 julien.garsia
** Last update Wed Jan 12 10:49:55 PM 2021 julien.garsia
*/

#include "Skat.hpp"

Skat::Skat(std::string s, int nb)
{
    _name = s;
    _stimpaks = nb;
}

Skat::Skat(std::string s)
{
    _name = s;
    _stimpaks = 15;
}

Skat::Skat(int nb)
{
    _name = "bob";
    _stimpaks = nb;
}

Skat::Skat()
{
    _name = "bob";
    _stimpaks = 15;
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return _stimpaks;
}

// unsigned int Skat::stimPaks(unsigned int stimPaks)
// {
//     _stimpaks = stimPaks;
//     return _stimpaks;
// }

const std::string &Skat::name()
{
    return _name;
}

void Skat::addStimPaks(unsigned int nb)
{
    if (nb == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
    } else {
        _stimpaks = _stimpaks + nb;
    }
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > _stimpaks)
        std::cout << "Don't be greedy" << std::endl;
    else {
        _stimpaks -= number;
        stock += number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::useStimPaks()
{
    if (_stimpaks > 0) {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        _stimpaks--;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stimpaks << " stimpaks remaining sir!" << std::endl;
}
