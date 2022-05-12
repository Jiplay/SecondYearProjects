/*
** process.cpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia 
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Apr 20 9:42:03 AM 2021 julien.garsia
** Last update Wed May 11 12:00:08 PM 2021 julien.garsia
*/

#include "../include/encapsulation/process/process.hpp"
#include "../include/error.hpp"


Process::Process()
{
    _status = STATUS::NOT_BEGIN;
    _pid = -1;
}

int Process::start()
{
    _status = STATUS::RUNNING;
    _pid = fork();
    if (_pid == -1) {
        throw ProcessError("Process: Fail fork.", "");
    }
    return _pid;
}

void Process::wait()
{
    int status;

    if (!isChild())
        waitpid(_pid, &status, 0);
}

Process::~Process()
{
    _status = STATUS::OVER;

    kill(_pid, SIGTERM);
}

bool Process::isChild() const
{
    if (_pid == 0)
        return true;
    return false;
}

