/*
** main.cpp for NTS
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Feb 8 9:58:56 AM 2021 julien.garsia
** Last update Sat Mar 12 11:46:19 AM 2021 julien.garsia
*/

#include "parser/parser.hpp"
#include "CLI/cli.hpp"

int main (int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Usage: ./nanotekspice file.nts" << std::endl;
        return 84;
      }
    try {
        Parser p1(av[1]);
        std::map<std::string, std::unique_ptr<nts::IComponent>> &chipsets_m = p1.getmap();

        // while (!chipsets_m.empty()) { // For test purpose
        //     // std::cout << "luck" << std::endl;
        //     std::cout << chipsets_m.begin()->first << std::endl;
        //     chipsets_m.erase(chipsets_m.begin());
        // }
        maincli(&chipsets_m);
    }
    catch(const Errors &e) {
      std::cerr << e.what() << '\n';
      return 84;
    }
    return 0;
}
