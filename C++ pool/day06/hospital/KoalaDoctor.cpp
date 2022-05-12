/*
** KoalaDoctor.cpp for B-CPP-300-PAR-3-2-CPPD06-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD06-julien.garsia/hospital
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 11 3:44:05 PM 2021 julien.garsia
** Last update Wed Jan 12 5:53:55 PM 2021 julien.garsia
*/

#include <list>
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string s)
{
    this->name = s;
    this->clock = false;
    std::cout << "Dr." << s << ": I'm Dr." << s << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *k)
{
    std::ofstream file;
    std::string name = k->getName();
    char array[5][16] = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"};

    std::cout << "Dr." << this->name << ": So what's goerking you Mr." << name << "?" <<std::endl;
    k->poke();
    name = name.append(".report");
    file.open(name);
    int b = random() % 5;
    std::cout << b << std::endl;
    file << array[b];
    file.close();
}

void KoalaDoctor::timeCheck(void)
{
    if (this->clock == true) {
        std::cout << "Dr." << this->name << ": Time to go home to my eucalyptus forest!" << std::endl;
        this->clock = false;
    } else if (this->clock == false) {
        std::cout << "Dr." << this->name << ": Time to get to work!" << std::endl;
        this->clock = true;
    }
}
