/*
** cond_var.hpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed May 12 11:19:46 AM 2021 julien.garsia
** Last update Thu May 12 11:41:18 AM 2021 julien.garsia
*/

#ifndef COND_VAR_HPP_
#define COND_VAR_HPP_

#include <condition_variable> 

class ICond_var
{
private:
    /* data */
public:
    ~ICond_var() = default;

    virtual void wait() = 0;
    virtual void notify_one() = 0;
    virtual void notify_all() = 0;
};

class Cond_var
{
private:
    std::condition_variable _cond_var;
public:
    Cond_var(/* args */);
    ~Cond_var();

    void wait(std::unique_lock<std::mutex> m);
    void notify_one();
    void notify_all();
};




#endif /* !COND_VAR_HPP_ */
