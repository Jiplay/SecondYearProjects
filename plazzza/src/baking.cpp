/*
** baking.cpp for plazza
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Apr 13 6:06:12 PM 2021 julien.garsia
** Last update Mon May 16 10:49:38 AM 2021 julien.garsia
*/

#include "../include/kitchen/kitchen.hpp"
#include "../include/kitchen/order.hpp"
#include "../include/encapsulation/logger/Logger.hpp"


void Kitchen::americana_baking(std::shared_ptr<Pizza> p)
{
    Logger l("logs/logs.log");
    std::string size = parser::newPizzaSize(p);
    sleep(2 * multiplicater_of_time);
    std::cout << "\nAn americana (" << size << ") has been cooked" << std::endl;
    l.AddLine("An americana (" + size + ") has been cooked\n");
}

void Kitchen::fantasia_baking(std::shared_ptr<Pizza> p)
{
    Logger l("logs/logs.log");
    std::string size = parser::newPizzaSize(p);
    sleep(4 * multiplicater_of_time);
    std::cout << "\nA fantasia (" << size << ") has been cooked" << std::endl;
    l.AddLine("A fantasia (" + size + ") has been cooked\n");
}

void Kitchen::regina_baking(std::shared_ptr<Pizza> p)
{
    Logger l("logs/logs.log");
    std::string size = parser::newPizzaSize(p);
    sleep(2 * multiplicater_of_time);
    std::cout << "\nA regina (" << size << ") has been cooked" << std::endl;
    l.AddLine("A regina (" + size + ") has been cooked\n");
}

void Kitchen::margarita_baking(std::shared_ptr<Pizza> p)
{
    Logger l("logs/logs.log");
    std::string size = parser::newPizzaSize(p);
    sleep(1 * multiplicater_of_time);
    std::cout << "\nA margarita (" << size << ") has been cooked" << std::endl;
    l.AddLine("A margarita (" + size + ") has been cooked\n");
}
