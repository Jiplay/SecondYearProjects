/*
** Toy.hpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 9:41:04 AM 2021 julien.garsia
** Last update Tue Jan 18 10:59:46 PM 2021 julien.garsia
*/

#ifndef TOY_HPP_
# define TOY_HPP_

#include "Picture.hpp"

class Toy {
    public:
    enum ToyType { BASIC_TOY, ALIEN, WOODY, BUZZ };
    Toy();
    Toy(ToyType type, std::string name = "toy", std::string file = "");
    Toy(Toy const &t);
    ~Toy();

    Toy &operator=(Toy const &t);
    bool setAscii(std::string const file);
    void setName(std::string const s) {name = s; }
    ToyType getType() const { return type; };
    std::string getName() const {return name; }
    std::string getAscii() const {return p.data; }
    protected:
        ToyType type;
        std::string name;
        Picture p;
};

#endif /* !TOY_HPP_ */
