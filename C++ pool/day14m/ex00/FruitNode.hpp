/*
** FruitNode.hpp for B-CPP-300-PAR-3-2-CPPD14M-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 19 9:33:31 AM 2021 julien.garsia
** Last update Thu Jan 20 8:51:14 PM 2021 julien.garsia
*/

#ifndef FRUITNODE_HPP_
# define FRUITNODE_HPP_

#include "Fruit.hpp"

class FruitNode {
    public:
        ~FruitNode(void);
        Fruit *f;
        FruitNode *next;
};

#endif /* !FRUITNODE_HPP_ */
