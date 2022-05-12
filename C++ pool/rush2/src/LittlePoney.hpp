/*
** EPITECH PROJECT, 2021
** LittlePoney.hpp 
** File description:
** LittlePoney.hpp
*/

#ifndef LITTLEPONEY_HPP_
#define LITTLEPONEY_HPP_

#include "Toy.hpp"

class LittlePoney:public Toy {
public:
    LittlePoney(const std::string &name);
    ~LittlePoney();
    void isTaken();
};

#endif
