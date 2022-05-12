/*
** main.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 9:56:40 AM 2021 julien.garsia
** Last update Tue Jan 18 1:49:07 PM 2021 julien.garsia
*/

#include "Picture.hpp"
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int main()
{
    Toy toto;
    Buzz ET("wesh");
    Woody dd("audd");

    toto.setName("TOTO !");
    if (toto.getType () == Toy::BASIC_TOY)
        std::cout  << "basic toy: " << toto.getName () << std::endl<< toto.getAscii() << std::endl;
    if (ET.getType () == Toy::BUZZ)
        std::cout  << "this BUZZ is: " << ET.getName () << std::endl<< ET.getAscii () << std::endl;
    if (dd.getType () == Toy::WOODY)
        std::cout  << "this WOODY is: " << dd.getName () << std::endl<< dd.getAscii () << std::endl;
    return  0;
}
