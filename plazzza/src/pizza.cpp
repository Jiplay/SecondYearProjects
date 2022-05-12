/*
** pizza.cpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu May 6 10:29:19 AM 2021 julien.garsia
** Last update Sat May 7 10:20:33 AM 2021 julien.garsia
*/

#include "../include/kitchen/order.hpp"
#include "../include/kitchen/kitchen.hpp"
#include "../include/error.hpp"


Ingredients::Ingredients()
{
    doe = 5;
    tomato = 5;
    gruyere = 5;
    ham = 5;
    steak = 5;
    eggplant = 5;
    goatcheese = 5;
    mushrooms = 5;
}

void Ingredients::refill()
{
    doe++;
    tomato++;
    gruyere++;
    ham++;
    mushrooms++;
    steak++;
    eggplant++;
    goatcheese ++;
}

bool Ingredients::prepare_my_margarita()
{
    if (doe != 0 && tomato != 0 && gruyere != 0) {
        doe--;
        tomato--;
        gruyere --;
        return true;
    }
    return false;
}

bool Ingredients::prepare_my_regina()
{
    if (doe != 0 && tomato != 0 && gruyere != 0 && ham != 0 && mushrooms != 0) {
        doe--;
        tomato--;
        gruyere --;
        ham--;
        mushrooms --;
        return true;
    }
    return false;
}

bool Ingredients::prepare_my_americana()
{
    if (doe != 0 && tomato != 0 && gruyere != 0 && steak != 0) {
        doe--;
        tomato--;
        gruyere--;
        ham--;
        mushrooms --;
        return true;
    }
    return false;
}

bool Ingredients::prepare_my_fantasia()
{
    if (doe != 0 && tomato != 0 && eggplant != 0 && goatcheese != 0) {
        doe--;
        tomato--;
        eggplant--;
        goatcheese --;
        return true;
    }
    return false;
}

Ingredients::~Ingredients()
{
}

Pizza::~Pizza()
{
}

Pizza::Pizza(int type, int size, int number)
{
    setNumber(number);
    setSize(size);
    setType(type);
}

Pizza::Pizza(const Pizza &p)
{
    setNumber(p.getNumber());
    setSize(p.getSize());
    setType(p.getType());
}
