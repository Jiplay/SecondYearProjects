/*
** Toy.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 9:41:10 AM 2021 julien.garsia
** Last update Tue Jan 18 4:37:48 PM 2021 julien.garsia
*/

#include "Toy.hpp"

Toy::Toy()
{
    type = BASIC_TOY;
    p.data = "";
}

Toy::Toy(ToyType typee, std::string namee, std::string file)
{
    type = typee;
    name = namee;
    p = new Picture(file);
}

Toy::Toy(Toy const *t)
{
    type = t->getType();
    name = t->getName();
    p = Picture(t->p);
}

bool Toy::setAscii(std::string const f)
{
    p.getPictureFromFile(f);
    return true;
}

Toy &Toy::operator=(Toy const &t)
{
    type = t.getType();
    name = t.getName();
    p = t.p;

    return *this;
}

void Toy::speak(std::string s)
{
    if (type == WOODY) {
        std::cout << "WOODY: " << name << " \"" << s << "\"" << std::endl;
    } else if (type == BUZZ) {
        std::cout << "WOODY: " << name << " \"" << s << "\"" << std::endl;
    } else {
        std::cout << name << " \"" << s << "\"" << std::endl;
    }
}

Toy &Toy::operator<<(const std::string str)
{
    p.data = str;
    return *this;
}

std::ostream &operator<<(std::ostream &s, const Toy &t)
{
    s << t.getName() << '\n' << t.getAscii() << std::endl;
    return s;
}

Toy::~Toy()
{
}
