/*
** KoalaBot.hpp for B-CPP-300-PAR-3-2-CPPD07A-julien.garsia 
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 4:00:03 PM 2021 julien.garsia
** Last update Thu Jan 13 2:39:44 PM 2021 julien.garsia
*/

#ifndef KOALABOT_HPP_
# define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();
        void setParts(Arms const &a);
        void setParts(Legs const &l);
        void setParts(Head const &h);

        void swapParts(Arms &a);
        void swapParts(Legs &l);
        void swapParts(Head &h);

        void informations(void) const;
        bool status() const;


    private:
        Legs _legs;
        Arms _arms;
        Head _head;
        std::string _serial = "Bob-01";
};

#endif /* !KOALABOT_HPP_ */
