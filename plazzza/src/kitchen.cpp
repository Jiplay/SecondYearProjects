/*
** Iprocess.hpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Apr 20 9:50:56 AM 2021 julien.garsia
** Last update Mon May 16 10:46:24 AM 2021 julien.garsia
*/

#include <iostream> // Le classico
#include <string> // Le classico


#include <chrono> // need for time management
#include <memory> // for uniq_ptr

#include <iomanip>  // idk 
#include <sstream>  // idk 
#include <fstream>  // idk 
#include <unistd.h>  // idk 

#include "../include//kitchen/kitchen.hpp"
#include "../include/encapsulation/logger/Logger.hpp"
#include "../include/error.hpp"


Kitchen::Kitchen(int const m, int const c, int const t)
{
    _Cooksnb = c;
    Sleep_time = t;
    multiplicater_of_time = m;
    is_full = false;
    Ingredients *_ing = new Ingredients;
}

Kitchen::~Kitchen()
{
    Logger l("logs/logs.log");
    l.AddLine("A kitchen has been destroyed\n");
    std::cout << "Seems like you don't need me anymore " << std::endl;
}


void Kitchen::dump(){
    std::cout << "I'm alive" << std::endl;
}

void Kitchen::baking()
{
    _m.lock();

    std::shared_ptr<Pizza> p = work_in_waiting.front();
    work_in_waiting.pop_front();

    _m.unlock();

    if (p->getType() == PizzaType::Regina) {
        _m.lock();
        if (_ing.prepare_my_regina() == true) {
            _m.unlock();
            regina_baking(p);
        } else {
            _m.unlock();
        }
    } else if (p->getType() == PizzaType::Fantasia) {
        _m.lock();
        if (_ing.prepare_my_fantasia() == true) {
            _m.unlock();
            fantasia_baking(p);
        } else {
            _m.unlock();
        }
    } else if (p->getType() == PizzaType::Margarita) {
        _m.lock();
        if (_ing.prepare_my_margarita() == true) {
            _m.unlock();
            margarita_baking(p);
        } else {
            _m.unlock();
        }
    } else if (p->getType() == PizzaType::Americana) {
        _m.lock();
        if (_ing.prepare_my_americana() == true) {
            _m.unlock();
            americana_baking(p);
        } else {
            _m.unlock();
        }
    }
}

void Kitchen::refill_me()
{
    std::string real_time = std::to_string(Sleep_time);
    
    for (int i = 0; i < 3; i++)
      real_time.pop_back();
    
    int converted_time = std::stoi(real_time);

    for (int j = 0 ; j < 6; j++) {
        sleep(1);
        if (j == 4) {
            this->~Kitchen();
            break;
        }
    }
}

void Kitchen::set_objectives(std::list<std::shared_ptr<Pizza>> work_todo, int a)
{

    ThreadPool pool(_Cooksnb);

    if (work_in_waiting.size() == 0)
        work_in_waiting = work_todo;
    work_todo.clear();

    for(int i = 0; i < _Cooksnb; ++i) {
        pool.my_thread_queue([i, this] {
            baking();
            return i*i;
        });
    }

    pool.waitFinished();
    refill_me();
    if (a == 0)
        kill(getpid(), SIGTERM);
}

namespace kitchen_management
{

    void kitchenFactory(int m, int c, int t, std::list<std::shared_ptr<Kitchen>> *tmp)
    {
        tmp->push_back(std::make_shared<Kitchen>(m, c, t));
    }
}
