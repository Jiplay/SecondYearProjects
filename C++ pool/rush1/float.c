/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    free(this);
}

static char *Float_str(FloatClass *this)
{
    size_t size = snprintf(NULL, 0, "<Float (%f)>", this->x);
    char *buffer = malloc(sizeof(char) * size + 1);

    snprintf(buffer, size + 1, "<Float (%f)>", this->x);
    return buffer;
}

FloatClass *Float_add(FloatClass const *a, FloatClass const *b)
{
    FloatClass *c = new(Float, (a->x + b->x));

    return c;
}

FloatClass *Float_sub(FloatClass const *a, FloatClass const *b)
{
    FloatClass *c = new(Float, (a->x - b->x));

    return c;
}

FloatClass *Float_mul(FloatClass const *a, FloatClass const *b)
{
    FloatClass *c = new(Float, (a->x * b->x));

    return c;
}

FloatClass *Float_div(FloatClass const *a, FloatClass const *b)
{
    FloatClass *c;

    if (b->x == 0)
        raise("error : can't divise per 0");
    c = new(Float, (a->x / b->x));

    return c;
}

static bool Float_eq(FloatClass const *a, FloatClass const *b)
{
    if (a->x == b->x)
        return true;
    return false;
}

static bool Float_gt(FloatClass const *a, FloatClass const *b)
{
    if (a->x > b->x)
        return true;
    return false;
}

static bool Float_lt(FloatClass const *a, FloatClass const *b)
{
    if (a->x < b->x)
        return true;
    return false;
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt,
    },
    .x = 0
};

const Class   *Float = (const Class *)&_description;
