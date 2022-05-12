/*
** dlopen_encapsulated.cpp for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Apr 16 9:39:45 AM 2021 julien.garsia
** Last update Sat Apr 16 10:14:23 AM 2021 julien.garsia
*/

#include "dlopen_encapsulated.hpp"

dlopen_encapsulated::dlopen_encapsulated(const char *s, bool game)
{
    _path = s;
    _gamebool = game;
}

void dlopen_encapsulated::open()
{
    if (_gamebool == true) { 
    _handle = dlopen(_path, RTLD_LAZY);
    if (!_handle)
        throw ("Can't open that .so file", dlerror());
    AGames* (*create)();
    void (*destroy)(AGames*);

    create = (AGames* (*)())dlsym(_handle, "create_object");
    _agames = (AGames*)create();
    } else {
            _handle = dlopen(_path, RTLD_LAZY);
            if (!_handle)
                throw ("Can't open that .so file", dlerror()); // new arcade error
            ALibs* (*create)();
            void (*destroy)(ALibs*);

            create = (ALibs* (*)())dlsym(_handle, "create_object");
            _alibs = (ALibs*)create();
    }
}

void dlopen_encapsulated::close()
{
    if (_gamebool == false) {
        void (*destroy)(ALibs*);
        destroy = (void (*)(ALibs*))dlsym(_handle, "destroy_object");
        destroy(_alibs);
        dlclose(_handle);
    } else {
        void (*destroy)(AGames*);
        destroy = (void (*)(AGames*))dlsym(_handle, "destroy_object");
        destroy(_agames);
        dlclose(_handle);
    }
}

AGames *dlopen_encapsulated::getAgames()
{
    return _agames;
}

ALibs *dlopen_encapsulated::getAlibs()
{
    return _alibs;
}

dlopen_encapsulated::~dlopen_encapsulated()
{
    close();
}

