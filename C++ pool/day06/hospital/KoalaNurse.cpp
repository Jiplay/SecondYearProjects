/*
** KoalaNurse.cpp for B-CPP-300-PAR-3-2-CPPD06-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD06-julien.garsia/hospital
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 11 2:33:13 PM 2021 julien.garsia
** Last update Wed Jan 12 1:44:23 PM 2021 julien.garsia
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id)
{
    this->identifier = id;
    this->clock = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->identifier << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string s, SickKoala *k)
{
    k->takeDrug(s);
}

std::string KoalaNurse::readReport(std::string filespath)
{
    std::ifstream file(filespath);
    std::string name;
    std::string line;

    if (file.is_open()) {
        getline(file, line);
        file.close();
    name = filespath.substr(0, filespath.size() - 7);
    std::cout << "Nurse " << this->identifier << ": Kreog! Mr." << name << " needs a " << line  << "!" << std::endl;
    return line;
    }
    return "";
}

void KoalaNurse::timeCheck(void)
{
    if (this->clock == true){
        std::cout << "Nurse " << this->identifier << ": Time to go home to my eucalyptus forest!" << std::endl;
        this->clock = false;
    } else if (this->clock == false) {
        std::cout << "Nurse " << this->identifier << ": Time to get to work!" << std::endl;
        this->clock = true;    
    }
}
