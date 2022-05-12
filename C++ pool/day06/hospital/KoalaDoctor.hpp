/*
** KoalaDoctor.hpp for B-CPP-300-PAR-3-2-CPPD06-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD06-julien.garsia/hospital
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 11 3:44:01 PM 2021 julien.garsia
** Last update Wed Jan 12 5:53:55 PM 2021 julien.garsia
*/

#ifndef KOALADOCTOR_HPP_
# define KOALADOCTOR_HPP_

#include "KoalaNurse.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(std::string s);
        ~KoalaDoctor();
        void diagnose(SickKoala *k);
        void timeCheck(void);

    private:
        std::string name;
        bool clock;
};

#endif /* !KOALADOCTOR_HPP_ */
