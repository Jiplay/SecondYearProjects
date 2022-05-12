/*
** Cesar.hpp for B-CPP-300-PAR-3-2-CPPD17-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 22 12:42:09 PM 2021 julien.garsia
** Last update Sat Jan 22 12:53:33 PM 2021 julien.garsia
*/

#ifndef CESAR_HPP_
# define CESAR_HPP_

#include "IEncryptionMethod.hpp"
#include <iostream>

class Cesar : public IEncryptionMethod
{
    public:
        Cesar();
        ~Cesar();
        void encryptChar(char plainchar);
		void decryptChar(char cipherchar);
		void reset();
    private:
        int _nb;
};

#endif /* !CESAR_HPP_ */
