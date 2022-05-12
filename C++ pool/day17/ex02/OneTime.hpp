/*
** OneTime.hpp for B-CPP-300-PAR-3-2-CPPD17-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 22 12:41:58 PM 2021 julien.garsia
** Last update Sat Jan 22 1:45:16 PM 2021 julien.garsia
*/

#ifndef ONETIME_HPP_
# define ONETIME_HPP_

#include "IEncryptionMethod.hpp"
#include <iostream>

class OneTime : public IEncryptionMethod
{
    public:
        OneTime(const std::string &key);
        ~OneTime();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();
    private:
        std::string _key;
        int _nb;
};

#endif /* !ONETIME_HPP_ */
