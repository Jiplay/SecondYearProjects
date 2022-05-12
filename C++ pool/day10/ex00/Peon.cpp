/*
** Peon.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 9:46:33 AM 2021 julien.garsia
** Last update Sat Jan 15 4:28:02 PM 2021 julien.garsia
*/

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const 
{
    std::cout << _name << " has been turned into a pink pony!" <<std::endl;
}

std::ostream &operator<<(std::ostream &s, const Peon &p)
{
    s << "I'm " << p.getName() << " and I like otters!" << std::endl;;
    return s;
}
