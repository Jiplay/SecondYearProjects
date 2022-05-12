/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    free(this);
}

char *Char_str(CharClass *this)
{
    size_t size = snprintf(NULL, 0, "<Char (%c)>", this->x);
    char *buffer = malloc(sizeof(char) * size + 1);

    snprintf(buffer, size + 1, "<Char (%c)>", this->x);
    return buffer;
}

CharClass *Char_add(const CharClass *a, const CharClass *b)
{
    CharClass *temp = new(Char, (a->x + b->x));

    return temp;
}

CharClass *Char_sub(const CharClass *a, const CharClass *b)
{
    CharClass *temp = new(Char, (a->x - b->x));

    return temp;
}

CharClass *Char_mul(const CharClass *a, const CharClass *b)
{
    CharClass *temp = new(Char, (a->x * b->x));

    return temp;
}

CharClass *Char_div(const CharClass *a, const CharClass *b)
{
    CharClass *temp;

    if (b->x == 0)
        raise("error : can't divise per 0");
    temp = new(Char, (a->x / b->x)); 

    return temp;
}

static bool Char_eq(const CharClass *a, const CharClass *b)
{
    if (a->x == b->x)
        return true;

    return false;
}

static bool Char_gt(const CharClass *a, const CharClass *b)
{
    if (a->x > b->x)
        return true;

    return false;
}

static bool Char_lt(const CharClass *this, const CharClass *obj)
{
    if (this->x < obj->x)
        return true;

    return false;
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0
};

const Class *Char = (const Class *)&_description;
