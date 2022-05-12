/*
** EPITECH PROJECT, 2021
** Table.cpp
** File description:
** Table
*/

#include "Table.hpp"

ITable::ITable()
{
    tablesize = 0;
    array = new Object*[10];
}

ITable::~ITable()
{
}

void ITable::put(Object *o)
{
}

ITable *createTable()
{
    ITable *table = new PapaXmasTable();
    return table;
}

void PapaXmasTable::put(Object *o)
{
    if (tablesize <= 10) {
        array[tablesize] = o;
        tablesize += 1;
    }
    else
        std::cerr << "Too many objects on the table !" << std::endl;
}

Object *PapaXmasTable::take()
{
    return array[tablesize-1];
}

std::string *PapaXmasTable::look()
{
    std::string temp[10];
    std::string osf;
    for (int x = 0; array[x] != NULL; x += 1) {
        osf = array[x]->getName();
        temp[x] = osf;
    }
    return temp;
}

PapaXmasTable::PapaXmasTable()
{
}

PapaXmasTable::~PapaXmasTable()
{
    for (size_t i = 0;array[i] != NULL; i++) {
        delete array[i];
    }
    
}