/*
** OneTime.cpp for B-CPP-300-PAR-3-2-CPPD17-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 22 12:42:04 PM 2021 julien.garsia
** Last update Sat Jan 22 2:22:06 PM 2021 julien.garsia
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &k)
{
    _key = k;
    _nb = 0;
}

OneTime::~OneTime()
{
}

void OneTime::reset()
{
    _nb = 0;
}

void OneTime::encryptChar(char plainchar)
{
    unsigned char c = plainchar;

    if (c >= 'a' && c <= 'z') {
        if (_key[_nb] >= 'a' && _key[_nb] <= 'z') {
            c += (_key[_nb] - 'a');
        } else {
            c += (_key[_nb] - 'A');
        }
        if (c > 'z') {
            c = c - 26;
        }
    } else if (c >= 'A' && c <= 'Z') {
        if (_key[_nb] >= 'a' && _key[_nb] <= 'z') {
            c += (_key[_nb] - 'a');
        } else {
            c += (_key[_nb] - 'A');
        }
        if (c > 'Z') {
            c = c - 26;
        }
    }
    std::cout << c;
    _nb += 1;
    _nb %= _key.size();
}

void OneTime::decryptChar(char cipherchar)
{
    unsigned char c = cipherchar;

    if (c >= 'a' && c <= 'z') {
        if (_key[_nb] >= 'a' && _key[_nb] <= 'z') {
            c -= (_key[_nb] - 'a');
        } else {
            c -= (_key[_nb] - 'A');
        }
        if (c < 'a') {
            c = c + 26;
        }
    } else if (c >= 'A' && c <= 'Z') {
        if (_key[_nb] >= 'a' && _key[_nb] <= 'z') {
            c -= (_key[_nb] - 'a');
        } else {
            c -= (_key[_nb] - 'A');
        }
        if (c < 'A') {
            c = c + 26;
        }
    }
    std::cout << c;
    _nb += 1;
    _nb %= _key.size();
}
