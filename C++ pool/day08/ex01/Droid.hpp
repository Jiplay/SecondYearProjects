/*
** Droid.hpp for B-CPP-300-PAR-3-2-CPPD08-julien.garsia in
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Jan 13 9:02:56 AM 2021 julien.garsia
** Last update Thu Jan 13 12:16:53 PM 2021 julien.garsia
*/

#ifndef DROID_HPP_
# define DROID_HPP_

#include "DroidMemory.hpp"

class Droid {
    public:
        Droid(std::string s);
        Droid(Droid const &src);
        // Droid(void);
        ~Droid();


        std::string getId() const { return Id; }
        const size_t getAttack() const { return Attack; }
        const size_t getToughness() const { return Toughness; }
        const size_t getEnergy() const { return Energy; }
        const std::string getStatus() const { return *Status;};
        const DroidMemory getBattleData() const { return *BattleData; }


        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        void setBattleData(DroidMemory *d);


        bool operator==(Droid const &d);
        bool operator!=(Droid const &d);
        Droid &operator=(const Droid  &d);
        Droid &operator<<(size_t &ac);

    private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;
        DroidMemory *BattleData;

};

#endif /* !DROID_HPP_ */
