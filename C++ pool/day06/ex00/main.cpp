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
#include <fstream>

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (0);
    }

    for (int i = 1; i < ac; i++) {
        std::ifstream file(av[i]);
        if (file.is_open()) {
            std::string line;
            while (getline(file, line))
                std::cout << line.c_str() << std::endl;
            file.close();
        }
        else {
            std::cerr << "my_cat: " << av[1] << ": No such file or directory" << std::endl;
        }
    }
    return 0;
}



