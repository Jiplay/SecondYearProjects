/*
** Federation.cpp for B-CPP-300-PAR-3-2-CPPD07M-julien.garsia 
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 9:05:47 AM 2021 julien.garsia
** Last update Wed Jan 12 5:10:56 PM 2021 julien.garsia
*/

// #include "Federation.hpp"
#include "Borg.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    _name = name;
    _length = length;
    _maxWarp = maxWarp;
    _width = width;
    _home = EARTH;
    _location = _home;

    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *c)
{
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
    this->_core = c;
}


void Federation::Starfleet::Ship::checkCore(void)
{
    std::cout << "USS ";
    if (_core->_coreReactor->_stability == true) {
        std::cout <<_name << ": The core is stable at the time."  << std::endl;
    } else {
        std::cout << _name << ": The core is unstable at the time."  << std::endl;
    }
}

void Federation::Starfleet::Ship::promote(Captain *c)
{
    _captain = c;
    std::cout << c->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->_coreReactor->_stability == true) { 
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _home != _location && _core->_coreReactor->_stability == true) { 
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->_coreReactor->_stability == true) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move()
{
    if (_home != _location && _core->_coreReactor->_stability == true) {
        _location = _home;
        return true;
    }
    return false;
}

Destination Federation::Starfleet::Ship::getLocation()
{
    return _location;
}

/*
    INDEPENDENT SHIP 
*/

Destination Federation::Ship::getLocation()
{
    return _location;
}

void Federation::Ship::checkCore(void)
{
    if (_core->_coreReactor->_stability == true) {
        std::cout <<_name << ": The core is stable at the time."  << std::endl;
    } else {
        std::cout << _name << ": The core is unstable at the time."  << std::endl;
    }
}

void Federation::Ship::setupCore(WarpSystem::Core *c)
{
    std::cout << this->_name << ": The core is set." << std::endl;
    this->_core = c;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    _name = name;
    _length = length;
    _maxWarp = 1;
    _width = width;
    _home = VULCAN;
    _location = _home;

    std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && warp > 0 && d != _location && _core->_coreReactor->_stability == true) { 
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp)
{
    if (warp <= _maxWarp && warp > 0 && _home != _location && _core->_coreReactor->_stability == true) { 
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (d != _location && _core->_coreReactor->_stability == true) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move()
{
    if (_home != _location && _core->_coreReactor->_stability == true) {
        _location = _home;
        return true;
    }
    return false;
}


/*
    CAPTAIN AND ENSIGN
*/


Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
}

int Federation::Starfleet::Captain::getAge()
{
    return _age;
}

std::string Federation::Starfleet::Captain::getName()
{
    return _name;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}
