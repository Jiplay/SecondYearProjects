/*
** Cesar.cpp for B-CPP-300-PAR-3-2-CPPD17-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 22 12:42:14 PM 2021 julien.garsia
** Last update Sat Jan 22 12:54:38 PM 2021 julien.garsia
*/

#include "Cesar.hpp"

Cesar::Cesar() : IEncryptionMethod()
{
    _nb = 3;
}

Cesar::~Cesar()
{
}

void Cesar::encryptChar(char plainchar)
{
    unsigned char c = plainchar;

    if (c >= 'a' && c <= 'z') {
        c = c + _nb;
        if (c > 'z') {
            c = c - 26;
        }
    } else if (c >= 'A' && c <= 'Z') {
        c = c + _nb;
        if (c > 'Z') {
            c = c - 26;
        }
    }
    std::cout << c;
    _nb += 1;
    _nb %= 26; 
}

void Cesar::decryptChar(char cipherchar)
{
    unsigned char c = cipherchar;

    if (c >= 'a' && c <= 'z') {
        c = c - _nb;
        if (c < 'a') {
            c = c + 26;
        }
    } else if (c >= 'A' && c <= 'Z') {
        c = c - _nb;
        if (c < 'A') {
            c = c + 26;
        }
    }
    std::cout << c;
    _nb += 1;
    _nb %= 26; 
}

void Cesar::reset()
{
    _nb = 3;
}
