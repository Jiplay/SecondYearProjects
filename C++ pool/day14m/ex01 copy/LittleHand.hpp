/*
** LittleHand.hpp for B-CPP-300-PAR-3-2-CPPD14M-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD14M-julien.garsia/ex01
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Jan 20 9:08:55 AM 2021 julien.garsia
** Last update Thu Jan 20 11:08:35 AM 2021 julien.garsia
*/

#ifndef LITTLEHAND_HPP_
# define LITTLEHAND_HPP_

#include "FruitBox.hpp"
#include "Lime.hpp"
#include "Banana.hpp"

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();
        void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);

    protected:
    private:
};

#endif /* !LITTLEHAND_HPP_ */
