/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    free(this);
}

static char *Point_str(PointClass *this)
{
    size_t size = snprintf(NULL, 0, "<Point (%d, %d)>", this->x, this->y);
    char *buffer = malloc(sizeof(char) * size + 1);

    snprintf(buffer, size + 1, "<Point (%d, %d)>", this->x, this->y);
    return buffer;
}

PointClass *Point_add(PointClass const *a, PointClass const *b)
{
    PointClass *c = new(Point, (a->x + b->x), (a->y + b->y));

    return c;
}

PointClass *Point_sub(PointClass const *a, PointClass const *b)
{
    PointClass *c = new(Point, (a->x - b->x), (a->y - b->y));

    return c;
}

PointClass *Point_mul(PointClass const *a, PointClass const *b)
{
    PointClass *c = new(Point, (a->x * b->x), (a->y * b->y));

    return c;
}

PointClass *Point_div(PointClass const *a, PointClass const *b)
{
    PointClass *c = new(Point, (a->x / b->x), (a->y / b->y));

    return c;
}

bool Point_eq(PointClass const *a, PointClass const *b)
{
    if (a->x == b->x && a->y == b->y)
        return true;
    return false;
}

bool Point_gt(PointClass const *a, PointClass const *b)
{
    int x = a->x - b->x;
    int y = a->y - b->y;

    if (x + y > 0)
        return true;
    return false;
}

bool Point_lt(PointClass const *a, PointClass const *b)
{
    int x = a->x - b->x;
    int y = a->y - b->y;

    if (x + y < 0)
        return true;
    return false;
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = (binary_operator_t)&Point_mul,
        .__div__ = (binary_operator_t)&Point_div,
        .__eq__ = (binary_comparator_t)&Point_eq,
        .__gt__ = (binary_comparator_t)&Point_gt,
        .__lt__ = (binary_comparator_t)&Point_lt
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
