/*
** Droid.cpp for undefined
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Jan 13 9:02:59 AM 2021 julien.garsia
** Last update Thu Jan 13 12:16:01 PM 2021 julien.garsia
*/

#include "Droid.hpp"

// Droid::Droid(void) :
// Attack(25), Energy(50), Toughness(15), Id(""), Status(new std::string("Standing by"))
// {
//     std::cout << "Droid '" << Id << "' Activated" << std::endl;
// }


Droid::Droid(std::string s) :
    Attack(25), Energy(50), Toughness(15), Id(s), Status(new std::string("Standing by")), BattleData(new DroidMemory)
{
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &src) :
    Attack(25), Energy(src.Energy), Toughness(15), Id(src.Id), Status(new std::string(*src.Status))
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

void Droid::setBattleData(DroidMemory *d)
{
    if (BattleData != NULL)
        delete BattleData;
    BattleData = d;
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

bool Droid::operator==(Droid const &d)
{
    if (*Status == *d.Status) {
        return true;
    }
    return false;
}

bool Droid::operator!=(Droid const &d)
{
    if (*Status == *d.Status) {
        return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &s, Droid &d)
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
    Droid d1("Avenger");
    size_t Durasel = 200;
    
    std::cout << d << std::endl;
    std::cout << d1 << std::endl;
    d = d1;
    d.setStatus(new std::string("Kill Kill Kill!"));
    d << Durasel;
    std::cout << d << "--" << Durasel << std::endl;
    Droid d2 = d;
    d.setId("Rex");
    std::cout << (d2 != d) << std::endl;
    return 0;
}