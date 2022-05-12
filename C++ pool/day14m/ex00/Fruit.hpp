/*
** Fruit.hpp for B-CPP-300-PAR-3-2-CPPD14M-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 19 9:34:21 AM 2021 julien.garsia
** Last update Thu Jan 20 8:59:16 PM 2021 julien.garsia
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <iostream>

class Fruit {
    public:
        virtual ~Fruit();

        std::string getName(void) const { return _name;}
        int getVitamins(void) const { return _vitamins;}

    protected:
        Fruit(int vitamins, std::string name = "");
        std::string _name;
        int _vitamins;
};

#endif /* !FRUIT_HPP_ */
