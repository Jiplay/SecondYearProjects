/*
** order.hpp for plazzza
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon May 10 11:35:44 AM 2021 julien.garsia
** Last update Mon May 16 10:50:53 AM 2021 julien.garsia
*/

#ifndef ORDER_HPP
#define ORDER_HPP

#include <list>
#include <iostream>
#include <memory>
#include <map>

enum PizzaType {
    Regina = 1, 
    Margarita = 2,
    Americana = 4,
    Fantasia = 8,
};

enum PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16,
};

class Pizza
{
private:
    int Size;
    int Type;
    int Number;

public:
    Pizza(int type, int size, int number);
    Pizza(const Pizza &p);
    ~Pizza();

    void setType(int const type) { Type = type; }
    void setNumber(int const nb) { Number = nb; }
    void setSize(int const size) { Size = size; }

    int getType() const { return Type; }
    int getNumber() const { return Number; }
    int getSize() const { return Size; }
};

namespace parser {
    int check_pizza_name(std::string str);
    int check_pizza_size(std::string str);
    int check_pizza_number(std::string str);
    std::shared_ptr<Pizza> pizza_order_check(std::string str);
    void print_order_to_check(std::list<Pizza> pizzas);
    std::string newPizzaSize(std::shared_ptr<Pizza> p);
    std::list<std::shared_ptr<Pizza>> master_order_function(std::string str);
}

namespace useful
{
    void reverseStr(std::string &str);
    int divise(float a, float b);
    bool check_parameters(int ac, char**av);
    std::string removeSpaces(std::string str);
    std::string splitonsize(std::string str);
}

#endif
