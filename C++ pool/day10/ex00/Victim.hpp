/*
** Victim.hpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 9:46:36 AM 2021 julien.garsia
** Last update Sat Jan 15 10:38:19 AM 2021 julien.garsia
*/

#ifndef VICTIM_HPP_
# define VICTIM_HPP_

#include <iostream>

class Victim {
    public:
        Victim(std::string name);
        ~Victim();

        std::string getName(void) const { return _name; }
        virtual void getPolymorphed() const;
    protected:
        std::string _name;
};

std::ostream &operator<<(std::ostream &s, const Victim &d);

#endif /* !VICTIM_HPP_ */
