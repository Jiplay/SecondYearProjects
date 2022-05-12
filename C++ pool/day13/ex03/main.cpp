/*
** main.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 9:56:40 AM 2021 julien.garsia
** Last update Tue Jan 18 2:30:46 PM 2021 julien.garsia
*/

#include "Picture.hpp"
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"
#include <memory>

int main()
{
    std::unique_ptr <Toy> b(new  Buzz("buzziiiii"));
    std::unique_ptr <Toy> w(new  Woody("wood"));
    std::unique_ptr <Toy> t(new Toy(Toy::ALIEN , "ET", "alien.txt"));
    b->speak("To the code, and  beyond !!!!!!!!");
    w->speak("There's a snake in my boot.");
    t->speak("the claaaaaaw");
}
