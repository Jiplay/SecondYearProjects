/*
** thread.cpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/plazza/B-CCP-400-PAR-4-1-theplazza-julien.garsia/src
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed May 12 10:31:43 AM 2021 julien.garsia
** Last update Thu May 12 10:36:57 AM 2021 julien.garsia
*/


#include "../include/encapsulation/thread/thread.hpp"

void Thread::detach()
{
    t.detach();
}

void Thread::join()
{
    t.join();
}

Thread::Thread()
{
    
}

Thread::~Thread()
{
    if (t.joinable())
        t.join();
}

std::thread::id Thread::getId()
{
    return t.get_id();
}

void Thread::swap(std::thread t1)
{
    t.swap(t1);
}
