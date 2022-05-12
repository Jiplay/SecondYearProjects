/*
** main.cpp for B-CPP-300-PAR-3-2-CPPD06-julien.garsia 
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 11 9:17:08 AM 2021 julien.garsia
** Last update Mon Jan 11 9:17:08 AM 2021 julien.garsia
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

int main(int ac, char **av)
{
    std::string a;
    std::string b;
    float res = 0;
    int found = 0;

    std::cin >> a;
    res = std::stof(a);
    std::cin >> b;
    found  = b.find("Celsius");

    if (found != std::string::npos)
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << (float)(9.0 /5.0) * res + 32 
        << std::setw(16) << "Fahrenheit" << std::endl;
    else
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << (float)(5.0 /9.0) * (res - 32) 
        << std::setw(16) << "Celsius" << std::endl;

    return 0;
}



