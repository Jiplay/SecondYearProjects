/*
** Parts.cpp for B-CPP-300-PAR-3-2-CPPD07A-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 4:00:24 PM 2021 julien.garsia
** Last update Thu Jan 13 2:31:41 PM 2021 julien.garsia
*/

#include "KoalaBot.hpp"

 // CTORS

Arms::Arms(std::string serial, bool functional)
{
    _functional = functional;
    _serial = serial;
}

Legs::Legs(std::string serial, bool functional)
{
    _functional = functional;
    _serial = serial; 
}

Head::Head(std::string serial, bool functional)
{
    _functional = functional;
    _serial = serial;
}

// ARMS

bool Arms::isFunctional() const
{
    return _functional;
}

std::string Arms::serial() const
{
    return _serial;
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : ";
    if (isFunctional() == true) {
        std::cout << "OK" << std::endl;
    } else
        std::cout << "KO" << std::endl;
}

// HEAD

bool Head::isFunctional() const
{
    return _functional;
}

std::string Head::serial() const
{
    return _serial;
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << _serial << " status : ";
    if (isFunctional() == true) {
        std::cout << "OK" << std::endl;
    } else
        std::cout << "KO" << std::endl;
}


// LEGS
bool Legs::isFunctional() const
{
    return _functional;
}

std::string Legs::serial() const
{
    return _serial;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : ";
    if (isFunctional() == true) {
        std::cout << "OK" << std::endl;
    } else
        std::cout << "KO" << std::endl;
}
