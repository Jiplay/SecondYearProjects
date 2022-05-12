/*
** dlopen_encapsulated.hpp for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Apr 16 9:40:00 AM 2021 julien.garsia
** Last update Sat Apr 16 10:18:53 AM 2021 julien.garsia
*/

#ifndef DLOPEN_ENCAPSULATED_HPP_
# define DLOPEN_ENCAPSULATED_HPP_

#include <iostream>
#include <dlfcn.h>
#include "../lib/ALibs.hpp"
#include "../lib/games/AGames.hpp"

class dlopen_encapsulated
{
private:
    const char *_path;
    bool _gamebool;
    void *_handle;
    AGames *_agames;
    ALibs* _alibs;

public:
    dlopen_encapsulated(const char *s, bool game);
    void open();
    void close();
    ALibs *getAlibs();
    AGames *getAgames();
    ~dlopen_encapsulated();
};




#endif /* !DLOPEN_ENCAPSULATED_HPP_ */
