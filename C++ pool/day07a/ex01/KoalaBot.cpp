/*
** KoalaBot.cpp for B-CPP-300-PAR-3-2-CPPD07A-julien.garsia 
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 4:00:01 PM 2021 julien.garsia
** Last update Thu Jan 13 2:49:22 PM 2021 julien.garsia
*/

#include "Parts.hpp"
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string const serial)
{
    _serial = serial;
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(Arms const &a)
{
    _arms = a;
}

void KoalaBot::setParts(Legs const &l)
{
    _legs = l;
}

void KoalaBot::setParts(Head const &h)
{
    _head = h;
}

void KoalaBot::swapParts(Arms &a)
{
    Arms tmp = _arms;
    setParts(a);

    a = tmp;
}

void KoalaBot::swapParts(Legs &l)
{
    Legs tmp = _legs;
    setParts(l);
    l = tmp;
}

void KoalaBot::swapParts(Head &h)
{
    Head tmp = _head;
    setParts(h);
    h = tmp;
}

void KoalaBot::informations(void) const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status() const
{
    if (_head.isFunctional() == true && _legs.isFunctional() == true && _arms.isFunctional() == true) {
        return true;
    }
    return false;
}
