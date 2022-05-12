/*
** EPITECH PROJECT, 2021
** IElf.cpp
** File description:
** IElf
*/

#include "IElf.hpp"

IElf::IElf()
{
}

IElf::~IElf()
{
}

PapaXmasElf::PapaXmasElf()
{
    table = new PapaXmasTable();
    conveyorbelt = new PapaXmasConveyorBelt();
}

PapaXmasElf::~PapaXmasElf()
{
    delete table;
    delete conveyorbelt;
    delete obj;
}

void PapaXmasElf::putconveyor(PapaXmasConveyorBelt *conveyorbelt, Object *o)
{
    conveyorbelt->put(o);
}

void PapaXmasElf::wraping(Wrap *wrap, Object *o)
{
    wrap->WrapMeThat(o);
}

Wrap *PapaXmasElf::pushin()
{
    return(conveyorbelt->pushin());
}

void PapaXmasElf::pushout()
{
    conveyorbelt->pushout();
}

void PapaXmasElf::puttable(Object *o)
{
    table->put(o);
}

Object *PapaXmasElf::taketable()
{
    return table->take();
}

std::string *PapaXmasElf::looktable()
{
    return table->look();
}

Object *PapaXmasElf::takeconveyor()
{
    return conveyorbelt->take();
}