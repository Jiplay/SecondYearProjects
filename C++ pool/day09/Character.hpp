/*
** Character.hpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 9:47:49 AM 2021 julien.garsia
** Last update Fri Jan 14 10:23:26 AM 2021 julien.garsia
*/

#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

#include <iostream>

class Character {
    public:
        enum RangeAttack { CLOSE, RANGE };
        RangeAttack Range;
        Character(const std::string &name, int level);
        ~Character();

        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        void TakeDamage(int damage);

        const std::string &getName() { return Name; }
        int getLvl() const { return Level; }
        int getStamina() const { return Stamina; }
        int getIntelligence() const { return Intelligence; }
        int getPv() const { return Health; }
        int getPower() const { return Energy; }

    void setEnergy(int const energy) { Energy = energy; }
    void setHealth(int const health) { Health = health; }

    protected:
        std::string Name;
        std::string Classe;
        std::string Race; 
        int Level;
        int Health;
        int Energy;
        int Strength;
        int Stamina;
        int Intelligence;
        int Spirit;
        int Agility;
};


#endif /* !CHARACTER_HPP_ */
