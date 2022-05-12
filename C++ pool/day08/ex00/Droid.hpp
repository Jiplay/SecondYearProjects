/*
** Droid.hpp for B-CPP-300-PAR-3-2-CPPD08-julien.garsia in
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Jan 13 9:02:56 AM 2021 julien.garsia
** Last update Sat May 7 11:07:25 AM 2021 julien.garsia
*/

#ifndef DROID_HPP_
# define DROID_HPP_

#include <iostream>

class Droid {
    public:
        Droid(std::string s);
        Droid(Droid const &src);
        Droid(void);
        ~Droid();


        std::string getId() const { return Id; }
        size_t getAttack() const { return Attack; }
        size_t getToughness() const { return Toughness; }
        size_t getEnergy() const { return Energy; }
        std::string getStatus() const { return *Status;};


        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);


        bool operator==(const Droid &d) const ;
        bool operator!=(const Droid &d) const ;
        Droid &operator=(const Droid  &d);
        Droid &operator<<(size_t &ac);

    private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;

};
std::ostream &operator<<(std::ostream &s, const Droid &d);
#endif /* !DROID_HPP_ */
