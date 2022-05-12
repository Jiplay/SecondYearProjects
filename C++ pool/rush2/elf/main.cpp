/*
** main.cpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia

**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 4:47:34 PM 2021 julien.garsia
** Last update Sat Jan 16 4:47:34 PM 2021 julien.garsia
*/

// #include "../src/Box.hpp"
#include "../src/LittlePoney.hpp"
#include "../src/Teddy.hpp"
// #include "../src/GiftPaper.hpp"

#include "../src/IElf.hpp"
#include "../src/ConveyorBelt.hpp"
#include "../src/Table.hpp"
#include "../src/Object.hpp"

Object **Wraps() 
{
    Object **obj = new Object*[3];

    obj[0] = new GiftPaper("Paper");
    obj[1] = new Box("Basic Box");
    obj[2] = new Teddy("Bear");
    obj[3] = NULL;
    return obj;
}

void test (Object **objects)
{
    PapaXmasElf *elf = new PapaXmasElf();
    Box *b = static_cast<Box *>(objects[1]);
    Wrap *gp = static_cast<Wrap *>(objects[0]);
    b->WrapMeThat(objects[2]);
    Object *ob = static_cast<Object *>(b);
    Object *ob1 = new Object("test");
    Object *ob2 = new Object("julien");
    Object *ob3 = new Object("Ibra");
    Object *ob4 = new Object("Lautre");
    Object *ob5 = new Object("Le bon");


    elf->wraping(gp, ob);
    elf->putconveyor(elf->getConveyor(), ob);
    elf->pushout();
    elf->putconveyor(elf->getConveyor(), ob1);


    PapaXmasTable *t = elf->getTable();
    PapaXmasConveyorBelt *c = elf->getConveyor();

    t->put(ob);
    t->put(ob1);
    t->put(ob2);
    t->put(ob3);
    t->put(ob4);
    t->put(ob5);
    std::string *tes = t->look();
    // std::cout << tes[2] << std::endl;

    ob2 = elf->taketable();
    std::cout << ob2->getName() << std::endl;

    for (int i = 0; i < 10; i++) {
        Wrap *wraaaap = elf->pushin();
        std::cout << wraaaap->getName() << std::endl;
    }

    std::cout << *ob2;
}


int main ()
{
    test(Wraps());

    return 1;
}

