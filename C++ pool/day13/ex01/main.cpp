/*
** main.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 9:56:40 AM 2021 julien.garsia
** Last update Tue Jan 18 1:27:40 PM 2021 julien.garsia
*/

#include "Picture.hpp"
#include "Toy.hpp"

int main()
{
    Toy toto;
    Toy ET(Toy::ALIEN, "green", "./draw/alien.txt");

    toto.setName("TOTO !");

    if (toto.getType() == Toy::BASIC_TOY)
        std::cout << "basic toy: " << toto.getName() << std::endl
        << toto.getAscii() << std::endl;
    if (ET.getType() == Toy::ALIEN)
        std::cout << "this alien is: " << ET.getName() << std::endl
        << ET.getAscii() << std::endl;
    return 0;
}
