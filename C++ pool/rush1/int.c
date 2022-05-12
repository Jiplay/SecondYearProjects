/*
** EPITECH PROJECT, 2021
** int.c
** File description:
** int
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    free(this);
}

static char *Int_str(IntClass *this)
{
    size_t size = snprintf(NULL, 0, "<Int (%d)>", this->x);
    char *buffer = malloc(sizeof(char) * size + 1);

    snprintf(buffer, size + 1, "<Int (%d)>", this->x);
    return buffer;
}

IntClass *Int_add(IntClass const *a, IntClass const *b)
{
    IntClass *c = new(Int, a->x + b->x);

    return c;
}

IntClass *Int_sub(IntClass const *a, IntClass const *b)
{
    IntClass *c = new(Int, a->x - b->x);

    return c;
}

IntClass *Int_mul(IntClass const *a, IntClass const *b)
{
    IntClass *c = new(Int, a->x * b->x);

    return c;
}

IntClass *Int_div(IntClass const *a, IntClass const *b)
{
    IntClass *c;

    if (b->x == 0)
        raise("error : can't divise per 0");    
    c = new(Int, a->x / b->x);
    return c;
}

bool Int_eq(IntClass const *a, IntClass const *b)
{
    if (a->x == b->x)
        return true;
    return false;
}

bool Int_gt(IntClass const *a, IntClass const *b)
{
    if (a->x > b->x)
        return true;
    return false;
}

bool Int_lt(IntClass const *a, IntClass const *b)
{
    if (a->x < b->x)
        return true;
    return false;
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0,
};

const Class *Int = (const Class *)&_description;
