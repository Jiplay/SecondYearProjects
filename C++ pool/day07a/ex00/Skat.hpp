/*
** Skat.hpp for B-CPP-300-PAR-3-2-CPPD07A-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/Pool /B-CPP-300-PAR-3-2-CPPD07A-julien.garsia/ex00
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 2:33:17 PM 2021 julien.garsia
** Last update Wed Jan 12 10:49:35 PM 2021 julien.garsia
*/

#ifndef SKAT_HPP_
# define SKAT_HPP_

// #include <string>
#include <iostream>

class Skat {
    public:
        Skat(const std::string s, int nb);
        Skat(const std::string s);
        Skat(int nb);
        Skat(void);
        ~Skat();

        int &stimPaks();
        // unsigned int stimPaks(unsigned int stimPaks);
        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int nb);
        void useStimPaks();
        void status();

    private:
        std::string _name;
        int _stimpaks;
};

#endif /* !SKAT_HPP_ */
