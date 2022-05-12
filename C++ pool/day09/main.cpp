
// #include "Warrior.hpp"
// #include "Character.hpp"
// #include "Priest.hpp"
// #include "Hunter.hpp"
// #include "Paladin.hpp"
// #include "Mage.hpp"

// int  main()
// {
//     Mage Julien("Pétomax", 99);
//     Warrior Ugo("Kuzan", 90);
//     Hunter Seb("Trapzy", 99);
//     Paladin random2("pasdidé", 8);
//     Priest random1("OUAISLESMAGES", 83);
// }


/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** main
*/
 
#include "Character.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Hunter.hpp"
#include "Priest.hpp"
#include "Paladin.hpp"
 
int  main()
{
    Character c("poney", 42);
    Character const_("get_pranked", 99);
    c.TakeDamage (50);
    c.TakeDamage (200);
    c.TakeDamage (200);
    std::cout << const_.getLvl() << std::endl;
    std::cout << const_.getName() << const_.getPower() << std::endl;
    std::cout << const_.RangeAttack() << std::endl;
    std::cout << const_.CloseAttack() << std::endl;
    std::cout << c.getPv() << std::endl;
    c.Heal();
    c.Heal();
    c.RestorePower();
    std::cout << c.getPv() << " " << c.getPower() << std::endl  << std::endl;
 
    Warrior pol("NOP", 99);
    std::cout << pol.getPv() << " " << pol.getPower() << std::endl;
    std::cout << pol.getLvl() << std::endl;
    std::cout << pol.getName() << std::endl;
    std::cout << pol.RangeAttack() << std::endl;
    std::cout << pol.CloseAttack() << std::endl;
    pol.TakeDamage(100);
    pol.Heal();
    std::cout << pol.getPv() << " " << pol.getPower() << std::endl  << std::endl;
 
    Mage nrv("dragi", 99); // VALIDÉ
    std::cout << nrv.getPv() << " " << nrv.getPower() << std::endl;
    std::cout << nrv.getLvl() << std::endl;
    std::cout << nrv.getName() << std::endl;
    std::cout << nrv.RangeAttack() << std::endl;
    std::cout << nrv.CloseAttack() << std::endl;
    nrv.TakeDamage(100);
    std::cout << "test" << nrv.getPv() << " " << nrv.getPower() << std::endl;
    nrv.Heal();
    std::cout << nrv.getPv() << " " << nrv.getPower() << std::endl << std::endl;
 
    Priest hihi("flixis", 99); // VALIDÉ
    std::cout << hihi.getPv() << " " << hihi.getPower() << std::endl;
    std::cout << hihi.getLvl() << std::endl;
    std::cout << hihi.getName() << std::endl;
    std::cout << hihi.RangeAttack() << std::endl;
    std::cout << hihi.CloseAttack() << std::endl;
    hihi.TakeDamage(100);
    std::cout << "test" << hihi.getPv() << " " << hihi.getPower() << std::endl;
    hihi.Heal();
    hihi.RestorePower();
    std::cout << hihi.getPv() << " " << hihi.getPower() << std::endl << std::endl;
 
    // Hunter Trap("Trapzy", 99);
    // std::cout << Trap.getPv() << " " << Trap.getPower() << std::endl;
    // std::cout << Trap.getLvl() << std::endl;
    // std::cout << Trap.getName() << std::endl;
    // std::cout << Trap.RangeAttack() << std::endl;
    // std::cout << Trap.CloseAttack() << std::endl;
    // Trap.TakeDamage(100);
    // Trap.Heal();
    // std::cout << Trap.getPv() << " " << Trap.getPower() << std::endl << std::endl;

    // Paladin cava("Palafin", 99);
    // std::cout << cava.getPv() << " " << cava.getPower() << std::endl;
    // std::cout << cava.getLvl() << std::endl;
    // std::cout << cava.getName() << std::endl;
    // std::cout << cava.RangeAttack() << std::endl;
    // std::cout << cava.CloseAttack() << std::endl;
    // std::cout << cava.Intercept() << std::endl;
    // cava.TakeDamage(100);
    // std::cout << cava.getPower() << std::endl << std::endl;
    // cava.Heal();
    // std::cout << cava.getPv() << " " << cava.getPower() << std::endl << std::endl;
}