/*
** EPITECH PROJECT, 2021
** ConveyorBelt.cpp
** File description:
** ConveyorBelt
*/

#include "ConveyorBelt.hpp"

IConveyorBelt::IConveyorBelt()
{
}

IConveyorBelt::~IConveyorBelt()
{
}

IConveyorBelt *createConveyorBelt()
{
    IConveyorBelt *conveyorbelt = new PapaXmasConveyorBelt();
    return conveyorbelt;
}

PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
    _isEmpty = true;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
}

Wrap *PapaXmasConveyorBelt::pushin()
{
    int x = rand();
    if (x % 2 == 1) {
        Box *box = new Box("BaseBox");
        wrap = box;
    }
    else {
        GiftPaper *gift = new GiftPaper("BaseGift");
        wrap = gift;
    }
    _isEmpty = false;
    return wrap;
}

void PapaXmasConveyorBelt::pushout()
{
    std::cout << "The " << wrap->getName() << " has been sent to Santa" << std::endl;
    delete wrap;
    _isEmpty = true;
}

void PapaXmasConveyorBelt::put(Object *o)
{
    if (_isEmpty == true) {
        wrap = static_cast<Wrap *>(o);
        _isEmpty = false;
    } else
        std::cerr << "Too many objects on the Conveyor Belt !" << std::endl;
}
Object *PapaXmasConveyorBelt::take()
{
    Object *temp;
    temp = static_cast<Object *>(wrap);
    delete wrap;
    return temp;
}