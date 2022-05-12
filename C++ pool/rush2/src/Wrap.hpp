/*
** Wrap.hpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:26:24 AM 2021 julien.garsia
** Last update Sun Jan 16 10:00:08 AM 2021 julien.garsia
*/

#ifndef WRAP_HPP_
# define WRAP_HPP_

#include "Object.hpp"
#include <iostream>

class Wrap : public Object
{
    public:
        Wrap(const std::string &name);
        ~Wrap();
        virtual void WrapMeThat(Object *Toy) = 0;
        virtual Object *openMe() = 0;
        virtual void closeMe() = 0;
        virtual Object *getObjet() = 0;

    protected:
        bool open;
        Object *b;
};

#endif /* !WRAP_HPP_ */
