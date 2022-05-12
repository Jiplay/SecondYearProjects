/*
** ex00.c for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 9:12:57 AM 2021 julien.garsia
** Last update Fri Jan 14 1:16:00 PM 2021 julien.garsia
*/

#include "ex00.h"

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new = malloc(sizeof(cthulhu_t));
    
    new->m_name = "Cthulhu";
    new->m_power = 42;
    printf("----\n");
    printf("Building Cthulhu\n");

    return (new);
}

void eat(koala_t *this)
{
    printf("%s eats\n", this->m_parent.m_name);
    this->m_parent.m_power = this->m_parent.m_power + 42;
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
    }
}

void sleeping(cthulhu_t *this)
{
    this->m_power = 42000;
    printf("%s sleeps\n", this->m_name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(koala_t));

    new->m_parent = *new_cthulhu();
    new->m_is_a_legend = is_a_legend;
    new->m_parent.m_name = name;
    printf("Building %s\n", name);

    if (is_a_legend == 0)
        new->m_parent.m_power = 0;

    return new;
}

void print_power(cthulhu_t const *this)
{
    printf("Power => %d\n", this->m_power);
}
