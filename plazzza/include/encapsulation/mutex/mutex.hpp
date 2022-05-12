/*
** Mutex.hpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue May 4 9:54:52 AM 2021 julien.garsia
** Last update Wed May 4 9:56:36 AM 2021 julien.garsia
*/

#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

class Mutex
{
private:
    std::mutex _m;
public:
    Mutex(/* args */);
    ~Mutex();
    void lock();
    void unlock();
    bool try_lock();
};

#endif /* !Mutex_HPP_ */
