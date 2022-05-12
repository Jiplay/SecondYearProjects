/*
** EPITECH PROJECT, 2021
** Table.hpp
** File description:
** Table
*/

#ifndef _TABLE_HPP_
#define _TABLE_HPP_
#include <iostream>
#include "Object.hpp"

class ITable
{
private:
protected:
    Object **array;
    size_t tablesize;
public:
    ITable(/* args */);
    ~ITable();
    virtual void put(Object *o) = 0;
    virtual Object *take() = 0;
    virtual std::string *look() = 0;
};

ITable *createTable();

class PapaXmasTable : public ITable
{
public:
    PapaXmasTable();
    ~PapaXmasTable();
    void put(Object *o);
    Object *take();
    std::string *look();
};

#endif