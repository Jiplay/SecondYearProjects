/*
** Sorcerer.hpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 9:47:03 AM 2021 julien.garsia
** Last update Sat Jan 15 10:37:10 AM 2021 julien.garsia
*/

#ifndef SORCERER_HPP_
# define SORCERER_HPP_

#include "Victim.hpp"
#include <iostream>

class Sorcerer {
    public:
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();

        std::string getName(void) const { return _name; }
        std::string getTitle(void) const { return _title; }

        void polymorph(const Victim &victim) const;

    private:
        std::string _name;
        std::string _title;
};

std::ostream &operator<<(std::ostream &s, const Sorcerer &d);


#endif /* !SORCERER_HPP_ */
