/*
** main.cpp for B-CPP-300-PAR-3-2-CPPD14M-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD14M-julien.garsia/ex00
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 19 9:55:47 AM 2021 julien.garsia
** Last update Thu Jan 20 1:16:00 PM 2021 julien.garsia
*/

#include "Banana.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"
#include "FruitBox.hpp"
#include "FruitNode.hpp"
#include "LittleHand.hpp"

int main()
{
    Lemon l;
    Lime li;
    Banana b;
    FruitBox fb =  FruitBox(8);
    FruitBox limes =  FruitBox(8);
    FruitBox lemons =  FruitBox(8);
    FruitBox bananas =  FruitBox(8);
    LittleHand lh = LittleHand();

    // Fruit fr = static_cast<Fruit > (b);
    // Fruit fr1 = static_cast<Fruit > (l);
    // Fruit fee;
    // fe.putFruit(&fr);
    // fe.putFruit(&fr1);
    // fee = *fe.pickFruit();
    
    // fe.putFruit(new Lemon());
    std::cout << li.getName() << std::endl;
    std::cout << fb.putFruit(new Lemon()) << std::endl;
    std::cout << fb.putFruit(new Lemon()) << std::endl;
    std::cout << fb.putFruit(new Lemon()) << std::endl;
    std::cout << fb.putFruit(new Lemon()) << std::endl;
    std::cout << fb.putFruit(new Lime()) << std::endl;
    std::cout << fb.putFruit(new Banana()) << std::endl;
    std::cout << fb.putFruit(new Banana()) << std::endl;
    std::cout << fb.putFruit(&l) << std::endl;
    lh.sortFruitBox(fb, lemons, bananas, limes);
    std::cout << bananas.nbFruits() << std::endl;
    std::cout << limes.nbFruits() << std::endl;
    std::cout << lemons.nbFruits() << std::endl;

    // Fruit* d = fb.pickFruit();

    // std::cout << fe.nbFruits() << " " << fee.getName() << std::endl;

    // std::cout << l.getVitamins() << std::endl;
    // std::cout << b.getVitamins() << std::endl;
    // std::cout << l.getName() << std::endl;
    // std::cout << b.getName() << std::endl;

    // Fruit& f = l;
    // std::cout << f.getVitamins() << std::endl;
    // std::cout << f.getName() << std::endl;
    return 0;
}
