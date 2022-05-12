/*
** main.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 9:56:40 AM 2021 julien.garsia
** Last update Tue Jan 18 2:55:43 PM 2021 julien.garsia
*/

#include <iostream>
#include "Toy.hpp"

int main()
{
    Toy a(Toy::BASIC_TOY , "REX", "rex.txt");
    std::cout << a;
    a << "\\o/";
    std::cout << a;
}