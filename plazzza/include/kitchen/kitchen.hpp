/*
** Iprocess.hpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Apr 20 9:50:56 AM 2021 julien.garsia
** Last update Mon May 16 10:39:11 AM 2021 julien.garsia
*/

#ifndef PLAZZA_HPP
#define PLAZZA_HPP

#include <memory> // for uniq_ptr
#include <thread> // needed for thread ^^

#include "order.hpp"
#include "../encapsulation/process/process.hpp"
#include "../encapsulation/threadpool/my_thread_pool.hpp"
#include "../encapsulation/mutex/mutex.hpp"

class Ingredients
{
private:
    int doe, tomato, gruyere, ham, mushrooms, steak, eggplant, goatcheese;
    
public:
    Ingredients();
    void refill();
    ~Ingredients();

    int getdoe() const { return doe; }
    int gettomato() const { return tomato; }
    int getgruyere() const { return gruyere; }
    int getham() const { return ham;}
    int getmushrooms() const { return mushrooms; }
    int getsteak() const { return steak; }
    int geteggplant() const { return eggplant; }
    int getgoatcheese() const { return goatcheese; }

    bool prepare_my_margarita();
    bool prepare_my_regina();
    bool prepare_my_americana();
    bool prepare_my_fantasia();
};


class Kitchen
{
private:
    int _Cooksnb;
    int Sleep_time;
    int multiplicater_of_time;
    bool is_full;
    std::list<std::shared_ptr<Pizza>> work;
    std::list<std::shared_ptr<Pizza>> work_in_waiting;
    Mutex _m;
    Ingredients _ing;


public:
    Kitchen(int const cooks, int const sleep, int const mul);
    ~Kitchen();
    void set_objectives(std::list<std::shared_ptr<Pizza>> work_todo, int a);

    void refill_me();
    void baking();
    void dump();

    void margarita_baking(std::shared_ptr<Pizza> p);
    void regina_baking(std::shared_ptr<Pizza> p);
    void fantasia_baking(std::shared_ptr<Pizza> p);
    void americana_baking(std::shared_ptr<Pizza> p);
};


namespace kitchen_management
{
    void create_kitchens(std::list<Pizza> list_p, int m, int c, int t);
    void kitchenFactory(int m, int c, int t, std::list<std::shared_ptr<Kitchen>> *tmp);
}

#endif
