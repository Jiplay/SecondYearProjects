/*
** Victim.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 9:46:50 AM 2021 julien.garsia
** Last update Sat Jan 15 12:32:58 PM 2021 julien.garsia
*/

#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name)
{
    std::cout << "Some random victim called " << name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

void Victim::getPolymorphed() const 
{
    std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const Victim &vi)
{
    s << "I'm " << vi.getName() << " and I like otters!" << std::endl;
    return s;
}
