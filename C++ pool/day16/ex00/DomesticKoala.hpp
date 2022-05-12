/*
** DomesticKoala.hpp for B-CPP-300-PAR-3-2-CPPD16-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 21 10:21:12 AM 2021 julien.garsia
** Last update Fri Jan 21 12:38:40 PM 2021 julien.garsia
*/

#ifndef DOMESTICKOALA_HPP_
# define DOMESTICKOALA_HPP_

#include <vector>
#include <iostream>
#include "KoalaAction.hpp"

class DomesticKoala {
    public:
        DomesticKoala(KoalaAction &koala);
        DomesticKoala(const DomesticKoala &domesticKoala);
        ~DomesticKoala();

        DomesticKoala &operator=(const  DomesticKoala &d);
        using methodPointer_t = void (KoalaAction::*)(const std::string &);

        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);

        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &);
        const std::vector<methodPointer_t> *getActions() const { return _next; };

    private:
        KoalaAction _action;
        std::vector<unsigned char> _command;
        std::vector<methodPointer_t> *_next;
};

#endif  // !DOMESTICKOALA_HPP_ 
