/*
** SickKoala.hpp for B-CPP-300-PAR-3-2-CPPD06-julien.garsia
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 11 11:05:45 AM 2021 julien.garsia
** Last update Tue Jan 11 3:38:55 PM 2021 julien.garsia
*/

#ifndef SICK_KOALA_HPP_
#define SICK_KOALA_HPP_

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

class SickKoala
{
    private:
        std::string name;
        std::string drug;
    public:
        SickKoala(std::string name);
        ~SickKoala();
        void poke();
        bool takeDrug(std::string name);
        void overDrive(std::string s);
        std::string getName() { return name; }
};



#endif
