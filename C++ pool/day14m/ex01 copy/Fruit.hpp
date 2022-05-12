/*
** Fruit.hpp for B-CPP-300-PAR-3-2-CPPD14M-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 19 9:34:21 AM 2021 julien.garsia
** Last update Wed Jan 19 9:54:13 AM 2021 julien.garsia
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <iostream>

class Fruit {
    public:
        Fruit();
        ~Fruit();

        std::string getName() const { return _name;}
        int getVitamins() const { return _vitamins;}

    protected:
        std::string _name;
        int _vitamins;
};

#endif /* !FRUIT_HPP_ */
