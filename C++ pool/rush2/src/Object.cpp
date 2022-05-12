/*
** Object.cpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:01:35 AM 2021 julien.garsia
** Last update Sun Jan 16 9:01:40 AM 2021 julien.garsia
*/

#include "Object.hpp"

Object::Object(const std::string &name)
{
    _name = name;
}

Object::~Object()
{
}

const std::string &Object::getName() const
{
    return _name;
}

const std::string &Object::getType() const
{
    return type;
}


std::ostream &operator<<(std::ostream &o, Object const &obj)
{
    o << obj.getName() << " , " << obj.getType() << std::endl;
    return o;
}
