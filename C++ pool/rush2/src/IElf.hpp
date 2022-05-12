/*
** EPITECH PROJECT, 2021
** IElf.hpp
** File description:
** IElf
*/

#ifndef _IELF_HPP_
#define _IELF_HPP_
#include "ConveyorBelt.hpp"
#include "Table.hpp"

class IElf
{
protected:
    PapaXmasTable *table;
    PapaXmasConveyorBelt *conveyorbelt;
    Object *obj;
public:
    IElf();
    ~IElf();
    
    virtual void putconveyor(PapaXmasConveyorBelt *conveyorbelt, Object *o) = 0;
    virtual Object *takeconveyor() = 0;
    virtual Wrap *pushin() = 0;
    virtual void pushout() = 0;

    virtual void puttable(Object *o) = 0;
    virtual Object *taketable() = 0;
    virtual std::string *looktable() = 0;
    virtual void wraping(Wrap *wrap, Object *o) = 0;

};

class PapaXmasElf
{
protected:
    PapaXmasTable *table;
    PapaXmasConveyorBelt *conveyorbelt;
    Object *obj;
public:
    PapaXmasElf();
    ~PapaXmasElf();

    PapaXmasTable *getTable() { return table; }
    PapaXmasConveyorBelt *getConveyor() { return conveyorbelt; }

    void putconveyor(PapaXmasConveyorBelt *conveyorbelt, Object *o);
    void wraping(Wrap *wrap, Object *o);
    Wrap *pushin();
    void pushout();
    void puttable(Object *o);
    Object *taketable();
    std::string *looktable();
    Object *takeconveyor();
};

#endif