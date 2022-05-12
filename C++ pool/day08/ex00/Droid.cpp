/*
** Droid.cpp for undefined
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Jan 13 9:02:59 AM 2021 julien.garsia
** Last update Sat May 7 11:04:00 AM 2021 julien.garsia
*/

#include "Droid.hpp"

Droid::Droid(void) :
    Id(""), Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by"))
{
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}


Droid::Droid(std::string s) :
    Id(s), Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by"))
{
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &src) :
    Id(src.Id), Energy(src.Energy), Attack(25), Toughness(15), Status(new std::string(*src.Status))
{
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
    if (Status != NULL)
        delete Status;
}

// SETTERS

void Droid::setEnergy(size_t e)
{
    if (e > 100)
        Energy = 100;
    else
        Energy = e;
}

void Droid::setId(std::string s)
{
    Id = s;
}

void Droid::setStatus(std::string *s)
{
    if (Status != NULL)
        delete Status;
    Status = s;
}

// OPERATORS 

Droid& Droid::operator=(const Droid  &src)
{
    if (Status != NULL)
        delete Status;

    setEnergy(src.Energy);
    Id = src.Id;
    Status = new std::string(*src.Status);

    return *this;
}

bool Droid::operator==(const Droid &d) const
{
    if (Id == d.Id &&  Energy == d.Energy && Attack == d.Attack && Toughness == d.Toughness && *Status == *d.Status) {
        return true;
    }
    return false;
}

bool Droid::operator!=(const Droid &d) const
{
    if (Id == d.Id &&  Energy == d.Energy && Attack == d.Attack && Toughness == d.Toughness && *Status == *d.Status) {
        return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &s, const Droid &d)
{
    if (d.getEnergy() > 100)
        s << "Droid '" << d.getId() << "', " << d.getStatus() << ", 100";
    else
        s << "Droid '" << d.getId() << "', " << d.getStatus() << ", " << d.getEnergy();
    return s;
}

Droid &Droid::operator<<(size_t &ac)
{
    size_t needed = 100 - Energy;
    if (ac <= needed) {
        Energy += ac;
        ac = 0;
    } else {
        ac -= needed;
        Energy = 100;
    }
    return *this;
}

int main()
{
    Droid d;
    // Droid d1;

    std::cout << d << "Julien" << std::endl;
}
