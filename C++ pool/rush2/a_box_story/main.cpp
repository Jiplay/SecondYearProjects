/*
** main.cpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 10:11:35 AM 2021 julien.garsia
** Last update Sun Jan 16 10:33:06 AM 2021 julien.garsia
*/

#include "../src/Box.hpp"
#include "../src/LittlePoney.hpp"
#include "../src/Teddy.hpp"
#include "../src/GiftPaper.hpp"

Object **Toys()
{
    Object **obj = new Object*[3];

    obj[0] = new LittlePoney("happy pony");
    obj[1] = new Teddy("cuddles");
    obj[2] = NULL;
    return obj;
}

Object **Wraps() 
{
    Object **obj = new Object*[3];

    obj[0] = new GiftPaper("Paper");
    obj[1] = new Box("Basic Box");
    obj[2] = new Teddy("Bear");
    obj[3] = NULL;
    return obj;
}

Object *my_UnitTest(Object **o)
{
    Object *final_present = new Object("final");

    for (int i = 0; o[i] != NULL; i++) {
        std::cout << o[i]->getName() << std::endl;
    }
    Box *b = static_cast<Box *>(o[1]);
    GiftPaper *gp = static_cast<GiftPaper *>(o[0]);
    b->WrapMeThat(o[2]);

    Object *ob = static_cast<Object *>(b);
    gp->WrapMeThat(ob);
    Object *f = static_cast<Object *>(gp);
    
    std::cout << *f;
    // Wrap *fe = static_cast<Wrap *>(f);
    // Object *t = fe->openMe();
    // std::cout << *t;
    // Box *be = static_cast<Box *>(t);
    // Object *ds = be->openMe();
    // std::cout << *ds;
    return f;
}

Object **my_UnitTest(void)
{

    Object **toys = Toys();

    if (!toys) {
        std::cerr << "Empty array ! " << std::endl;
        return NULL;
    }

    for (int i = 0; toys[i] != NULL; i++) {
        std::cout << toys[i]->getName() << std::endl;
    }

    return(toys);
}

int main()
{
    my_UnitTest(Wraps());
    return 1;
}