/*
** KoalaNurse.hpp for B-CPP-300-PAR-3-2-CPPD06-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 11 2:33:20 PM 2021 julien.garsia
** Last update Tue Jan 11 8:53:48 PM 2021 julien.garsia
*/

#ifndef KOALANURSE_HPP_
# define KOALANURSE_HPP_

#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int id);
        ~KoalaNurse();
        void giveDrug(std::string s, SickKoala *k);
        std::string readReport(std::string filespath);
        void timeCheck(void);
    private:
        int identifier;
        bool clock;
};

#endif /* !KOALANURSE_HPP_ */
