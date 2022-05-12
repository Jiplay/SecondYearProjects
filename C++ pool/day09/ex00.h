/*
** ex00.hpp for B-CPP-300-PAR-3-2-CPPD09-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 14 9:13:02 AM 2021 julien.garsia
** Last update Fri Jan 14 1:11:54 PM 2021 julien.garsia
*/

#ifndef EX00_HPP_
# define EX00_HPP_

#include <stdio.h>

typedef struct cthulhu_s {
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct koala_s {
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;

cthulhu_t *new_cthulhu();
void sleeping(cthulhu_t *this);
void attack(cthulhu_t *this);
koala_t *new_koala(char *name, char is_a_legend);
void print_power(cthulhu_t const *this);
void eat(koala_t *this);
#endif /* !EX00_HPP_ */
