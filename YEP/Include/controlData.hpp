/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-julien.garsia
** File description:
** controlData
*/

#ifndef CONTROLDATA_HPP_
#define CONTROLDATA_HPP_
#include <iostream>
#include <map>
#include <fstream>

template <class T>
class Control{
    T first;
    T path;
    std::map<int, T> mappy;
    public:
        Control(T a) {
            path = a;
        }
        std::map<int, T> getctrl();

};

template <class T>
std::map<int, T> Control<T>::getctrl() 
{
    std::string line;
    std::ifstream myfile (path);
    int i = 0;
    if (myfile.is_open())
    {
        while (std::getline (myfile,line)) {
            // std::cout << line << '\n';
            mappy.insert(std::pair<int, T>( i, line));
            i++;
        }
        myfile.close();
    }

    else std::cout << "Unable to open file";
    return mappy;
}

#endif /* !CONTROLDATA_HPP_ */
