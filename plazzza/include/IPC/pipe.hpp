/*
** pipe.hpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia 
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Apr 20 12:19:55 PM 2021 julien.garsia
** Last update Tue May 10 11:21:52 AM 2021 julien.garsia
*/

#ifndef PIPE_HPP_
#define PIPE_HPP_

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <iostream>


class IPC_read
{
private:
    /* data */
public:
    IPC_read(/* args */);
    ~IPC_read();
    void lets_read(std::string p, std::string *dest, int n);
};

class IPC_write
{
private:
    std::string _path;
    std::string _msg;
    
public:
    IPC_write();
    ~IPC_write();
    void lets_write(std::string s, std::string msg);
};

class IPC
{
private:
    IPC_read r;
    IPC_write w;
public:
    std::string read;
    std::string path;
    IPC(/* args */);
    ~IPC() = default;

    IPC &operator<<(std::string &s);
    IPC &operator>>(std::string &s);
};

#endif /* !PIPE_HPP_ */
