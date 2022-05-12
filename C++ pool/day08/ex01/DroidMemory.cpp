/*
** DroidMemory.cpp for B-CPP-300-PAR-3-2-CPPD08-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Jan 13 12:06:38 PM 2021 julien.garsia
** Last update Thu Jan 13 4:56:17 PM 2021 julien.garsia
*/

#include "Droid.hpp"

DroidMemory::DroidMemory() : 
    Exp(0), Fingerprint(random())
{
}

DroidMemory::~DroidMemory()
{
}

void DroidMemory::setExp(size_t e)
{
    Exp = e;
}

void DroidMemory::setFingerprint(size_t e)
{
    Fingerprint = e;
}


DroidMemory &DroidMemory::operator<<(DroidMemory const &d)
{
    Exp = d.getExp() + Exp;
    Fingerprint = Fingerprint ^ d.getFingerprint();

    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &d)
{
    d.setExp(d.getExp() + Exp);
    Fingerprint = Fingerprint ^ d.getFingerprint();

    return d;
}


std::ostream &operator<<(std::ostream &o, const DroidMemory &d)
{
    o << "DroidMemory '" << d.getFingerprint() << "', " << d.getExp();
    return o;
}

DroidMemory &DroidMemory::operator+=(DroidMemory &d)
{
    Exp = d.getExp() + Exp;
    Fingerprint = Fingerprint ^ d.getFingerprint();

    return *this;
}

DroidMemory &DroidMemory::operator+=(size_t nb)
{
    Exp += nb;
    Fingerprint = Fingerprint ^ nb;
}

DroidMemory DroidMemory::operator+(size_t nb) const 
{
    DroidMemory a;

    a.setExp(Exp + nb);
    a.setFingerprint(Fingerprint ^ nb);

    return a;
}

DroidMemory DroidMemory::operator+(DroidMemory &d) const 
{
    DroidMemory a;

    a.setExp(Exp + d.Exp);
    a.setFingerprint(Fingerprint ^ d.Fingerprint);

    return a;
}
