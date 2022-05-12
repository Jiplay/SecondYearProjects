/*
** FruitBox.hpp for B-CPP-300-PAR-3-2-CPPD14M-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 19 9:33:37 AM 2021 julien.garsia
** Last update Wed Jan 19 9:11:28 PM 2021 julien.garsia
*/

#ifndef FRUITBOX_HPP_
# define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int nb);
        ~FruitBox();
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head() const { return _node; }
        int nbFruits() const ;
    protected:
        FruitNode *_node;
        int _nb;
};

#endif /* !FRUITBOX_HPP_ */
