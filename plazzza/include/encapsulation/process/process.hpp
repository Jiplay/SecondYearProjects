/*
** encapsulation.hpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Apr 20 9:33:38 AM 2021 julien.garsia
** Last update Thu May 5 9:59:25 AM 2021 julien.garsia
*/

#ifndef PROCESS_HPP_
# define PROCESS_HPP_

#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <signal.h>

#include "Iprocess.hpp"

class Process : public Iprocess
{
private:
    int _pid;
    STATUS _status;
public:
    Process(/* args */);
    ~Process();
    
    int start();
    void wait();
    int get_pid();
    bool isChild() const;
};


#endif /* !PROCESS_HPP_ */
