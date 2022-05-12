/*
** SickKoala.cpp for B-CPP-300-PAR-3-2-CPPD06-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 11 11:07:35 AM 2021 julien.garsia
** Last update Tue Jan 11 9:02:45 PM 2021 julien.garsia
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << this->name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string s)
{
    if (s.find("Mars") != std::string::npos) {
        std::cout << "Mr." << this->name << ": Mars, and it kreogs!" << std::endl;
        return true;
    }
    if (s.find("Kinder") != std::string::npos) {
        std::cout << "Mr." << this->name << ": There is a toy inside!" << std::endl;
        return true;
    }
    std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
    return false;
}

void SickKoala::overDrive(std::string s)
{
    while (s.find("Kreog!") != std::string::npos)
        s.replace(s.find("Kreog!"), 6, "1337!");
    std::cout << "Mr."<< name << ": " << s << std::endl;
}
