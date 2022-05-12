/*
** Borg.cpp for B-CPP-300-PAR-3-2-CPPD07M-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD07M-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 11:26:18 AM 2021 julien.garsia
** Last update Wed Jan 12 5:08:12 PM 2021 julien.garsia
*/

#include "Borg.hpp"

Borg::Ship::Ship()
{
    _side = 300;
    _maxWarp = 9;
    _home = UNICOMPLEX;
    _location = _home;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n";
    std::cout << "Your biological characteristics and technologies will be assimilated.\n";
    std::cout << "Resistance is futile.\n";
}

void Borg::Ship::setupCore(WarpSystem::Core *c)
{
    _core = c;
}

void Borg::Ship::checkCore()
{
    if (_core->_coreReactor->_stability == true) {
        std::cout << "Everything is in order."  << std::endl;
    } else {
        std::cout << "Critical failure iminent."  << std::endl;
    }
}

Destination Borg::Ship::getLocation()
{
    return _location;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->_coreReactor->_stability == true) { 
        _location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->_coreReactor->_stability == true) { 
        _location = _home;
        return true;
    }
    return false;
}

bool Borg::Ship::move(Destination d)
{
    if (d != _location && _core->_coreReactor->_stability == true) {
        _location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move()
{
    if (_home != _location && _core->_coreReactor->_stability == true) {
        _location = _home;
        return true;
    }
    return false;
}
 