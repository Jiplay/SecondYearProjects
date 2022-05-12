/*
** EPITECH PROJECT, 2021
** ConveyorBelt.hpp
** File description:
** ConveyorBelt
*/

#ifndef _CONVEYORBELT_HPP_
#define _CONVEYORBELT_HPP_
#include "Object.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

class IConveyorBelt
{
protected:
    bool _isEmpty;
    Wrap *wrap;
public:
    IConveyorBelt(/* args */);
    ~IConveyorBelt();
    virtual void put(Object *o) = 0;
    virtual Object *take() = 0;
    virtual Wrap *pushin() = 0;
    virtual void pushout() = 0;
};

IConveyorBelt *createConveyorBelt();

class PapaXmasConveyorBelt : public IConveyorBelt
{
public:
    PapaXmasConveyorBelt();
    ~PapaXmasConveyorBelt();
    Wrap *pushin();
    void pushout();
    void put(Object *o);
    Object *take();

};

#endif