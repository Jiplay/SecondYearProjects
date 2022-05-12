/*
** Box.hpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:26:44 AM 2021 julien.garsia
** Last update Sun Jan 16 9:26:48 AM 2021 julien.garsia
*/

#ifndef BOX_HPP_
# define BOX_HPP_

#include "Wrap.hpp"
#include <iostream>

class Box : public Wrap {
    public:
        Box(const std::string &name);
        ~Box();
        void WrapMeThat(Object *object);
        Object *openMe();
        void closeMe();
        Object *getObjet();
};

#endif /* !BOX_HPP_ */
