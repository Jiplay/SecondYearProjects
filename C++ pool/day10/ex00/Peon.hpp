/*
** Peon.hpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 9:46:30 AM 2021 julien.garsia
** Last update Sat Jan 15 10:38:26 AM 2021 julien.garsia
*/

#ifndef PEON_HPP_
# define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim
{
    public:
        Peon(std::string name);
        ~Peon();
        void getPolymorphed() const;

};

std::ostream &operator<<(std::ostream &s, const Peon &d);

#endif /* !PEON_HPP_ */
