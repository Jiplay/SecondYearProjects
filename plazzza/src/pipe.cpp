/*
** pipe.cpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/plazza/B-CCP-400-PAR-4-1-theplazza-julien.garsia/src
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Apr 20 12:19:47 PM 2021 julien.garsia
** Last update Tue May 10 11:31:45 AM 2021 julien.garsia
*/

#include "../include/IPC/pipe.hpp"

IPC_write::IPC_write()
{
}

IPC_write::~IPC_write()
{
}

void IPC_write::lets_write(std::string s, std::string msg)
{
    int myPipe = open(s.c_str(), O_WRONLY); 
    write(myPipe, msg.c_str(), msg.length());
    close(myPipe);
}

IPC_read::IPC_read(/* args */)
{
}

IPC_read::~IPC_read()
{
}

IPC::IPC()
{
}

void IPC_read::lets_read(std::string s, std::string *dest, int nb)
{
    int myPipe;
    myPipe = open(s.c_str(), O_RDONLY);
    char buffer[nb];
    int length = 0;
    length = read(myPipe, buffer, nb);
    buffer[nb] = '\0';

    *dest = std::string(buffer);
    close(myPipe);
}

IPC &IPC::operator<<(std::string &s)
{
    path = s;
    
    return *this;
}

IPC &IPC::operator>>(std::string &s)
{
    w.lets_write(path, s);
    
    return *this;
}
