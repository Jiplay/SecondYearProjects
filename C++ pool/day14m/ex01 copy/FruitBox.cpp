/*
** FruitBox.cpp for B-CPP-300-PAR-3-2-CPPD14M-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 19 9:33:42 AM 2021 julien.garsia
** Last update Wed Jan 19 9:11:20 PM 2021 julien.garsia
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int nb)
{
    _nb = nb;
    _node = nullptr;
}

int FruitBox::nbFruits() const
{
    FruitNode *fn = _node;
    int i = 0;
    while (fn != nullptr) {
        fn = fn->next;
        i++;
    }
    return i;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *node;
    FruitNode *tmp = _node;

    if (_node == nullptr) {
        _node = new FruitNode;
        _node->f = f;
        _node->next = nullptr;
        return true;
    }
    while (tmp->next != nullptr) {
        if (tmp->f == f)
            return false;
        tmp = tmp->next;
    }
    if (tmp->f == f)
        return false;
    node = new FruitNode;
    node->f = f;
    node->next = nullptr;
    tmp->next = node;
    
    return true;
}

Fruit *FruitBox::pickFruit()
{
    Fruit *tmp;

    if (_node == nullptr)
        return (nullptr);
    tmp = _node->f;
    _node = _node->next;
    return (tmp);
}

FruitBox::~FruitBox()
{
}
