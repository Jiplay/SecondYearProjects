/*
** main.cpp for B-CPP-300-PAR-3-2-CPPD10-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 15 1:26:47 PM 2021 julien.garsia
** Last update Mon Jan 17 2:34:58 PM 2021 julien.garsia
*/

#include "Character.hpp"
#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"


int main()
{
    const auto preda = new Character("Predator");
    const auto prey = new RadScorpion();

    std::cout << *preda;

    AWeapon *pr(new PlasmaRifle());
    AWeapon *pf(new PowerFist());


    preda->equip(pr);
    std::cout << *preda;
    preda->equip(pf);
    
    preda->attack(prey);
    std::cout << *preda;
    preda->equip(pr);
    std::cout << *preda;
    preda->attack(prey);
    std::cout << *preda;
    preda->attack(prey);
    std::cout << *preda;

}
