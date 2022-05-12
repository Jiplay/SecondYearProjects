/*
** else.cpp for plazza in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/plazza/B-CCP-400-PAR-4-1-theplazza-julien.garsia/src
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Apr 13 4:18:18 PM 2021 julien.garsia
** Last update Mon May 16 10:51:01 AM 2021 julien.garsia
*/

#include "../include/kitchen/order.hpp"
#include <iostream>
#include <algorithm>

namespace useful
{
    void reverseStr(std::string &str)
    {
        int n = str.length();
    
        for (int i = 0; i < n / 2; i++)
            std::swap(str[i], str[n - i - 1]);
    }

    int divise(float a, float b)
    {
        float c = a/b;
        int tmp = 0;
        std::string s;

        std::cout << c << '\n';
        s = std::to_string(c);

        reverseStr(s);
        char const *str = s.c_str();
        
        for (int i = 0; str[i] != '.'; i++) {
            if (str[i] == '0')
                tmp++;
        }

        if (tmp != 6) {
            return int(c + 1);
        }
        return int(c);
    }

    std::string splitonsize(std::string str)
    {
        std::string word = "";
        int a = 0;

        for (auto x : str) 
        {
            if (a == 1 && x != ' ') {
                word += x;
            }
            if (x == ' ')
                a++;
        }
        return word;
    }



    std::string removeSpaces(std::string str) 
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }

    bool check_parameters(int ac, char**av)
    {
        int tmp = 0;
        int tmp1 = 0;
        int tmpbis = 0;

        if (ac != 4)
            return false;
        
        tmp = atoi(av[1]);
        tmp1 = atoi(av[2]);
        tmpbis = atoi(av[3]);

        if (tmp > 0 && tmp1 > 0 && tmpbis > 0)
            return true;
        
        return false;
    }
}
