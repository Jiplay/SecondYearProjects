/*
** Sorcerer.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia 
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 9:46:55 AM 2021 julien.garsia
** Last update Sat Jan 15 4:27:51 PM 2021 julien.garsia
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}


std::ostream &operator<<(std::ostream &s, const Sorcerer &so)
{
    s << "I am " << so.getName() << ", " << so.getTitle() << ", and I like ponies!" << std::endl;;
    return s;
}

void Sorcerer::polymorph(const Victim &victim) const 
{
    victim.getPolymorphed();
}
