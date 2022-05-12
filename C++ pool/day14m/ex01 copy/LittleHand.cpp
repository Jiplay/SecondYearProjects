/*
** LittleHand.cpp for B-CPP-300-PAR-3-2-CPPD14M-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD14M-julien.garsia/ex01
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Jan 20 9:08:58 AM 2021 julien.garsia
** Last update Thu Jan 20 11:25:35 AM 2021 julien.garsia
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    Fruit *fruit;
    FruitBox tmp(unsorted.nbFruits());
	bool success = false;

    while ((fruit = unsorted.pickFruit()))
        tmp.putFruit(fruit);
    while ((fruit = tmp.pickFruit())) {
		if (fruit->getName() == "banana")
			success = bananas.putFruit(fruit);
		else if (fruit->getName() == "lemon")
			success = lemons.putFruit(fruit);
		else if (fruit->getName() == "lime")
			success = limes.putFruit(fruit);
		if (!success)
			unsorted.putFruit(fruit);
    }
}
