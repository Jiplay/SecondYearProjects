/*
** DroidMemory.hpp for B-CPP-300-PAR-3-2-CPPD08-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Jan 13 12:06:31 PM 2021 julien.garsia
** Last update Thu Jan 13 4:57:08 PM 2021 julien.garsia
*/

#ifndef DROIDMEMORY_HPP_
# define DROIDMEMORY_HPP_

#include <iostream>

class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();

        const size_t getFingerprint() const { return Fingerprint; }
        const size_t getExp() const { return Exp; }
        void setFingerprint(size_t e);
        void setExp(size_t e);

        DroidMemory &operator<<(DroidMemory const &d);
        DroidMemory &operator>>(DroidMemory &d);
        DroidMemory &operator+=(DroidMemory &d);
        DroidMemory &operator+=(size_t nb);
        DroidMemory operator+(size_t nb) const ;
        DroidMemory operator+(DroidMemory &d) const;
        

    private:
        size_t Fingerprint;
        size_t Exp;
};

std::ostream &operator<<(std::ostream &o, const DroidMemory &d);

#endif /* !DROIDMEMORY_HPP_ */
