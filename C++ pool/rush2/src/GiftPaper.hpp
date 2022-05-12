/*
** GiftPaper.hpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:26:34 AM 2021 julien.garsia
** Last update Sun Jan 16 9:59:30 AM 2021 julien.garsia
*/

#ifndef GIFTPAPER_HPP_
# define GIFTPAPER_HPP_

#include "Wrap.hpp"

class GiftPaper : public Wrap
{
    public:
        GiftPaper(const std::string &name);
        ~GiftPaper();
        void WrapMeThat(Object *_toy);
        Object *openMe();
        void closeMe();
        Object *getObjet();
};

#endif /* !GIFTPAPER_HPP_ */
