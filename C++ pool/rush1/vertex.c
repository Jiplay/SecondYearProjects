/*
** EPITECH PROJECT, 2021
** vertex
** File description:
** Exercise 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    free(this);
}

static char *Vertex_str(VertexClass *this)
{
    size_t size = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    char *buffer = malloc(sizeof(char) * size + 1);

    snprintf(buffer, size + 1, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return buffer;
}

VertexClass *Vertex_add(VertexClass const *a, VertexClass const *b)
{
    VertexClass *c = new(Vertex, (a->x + b->x), (a->y + b->y), (a->z + b->z));

    return c;
}

VertexClass *Vertex_sub(VertexClass const *a, VertexClass const *b)
{
    VertexClass *c = new(Vertex, (a->x - b->x), (a->y - b->y), (a->z - b->z));

    return c;
}

VertexClass *Vertex_mul(VertexClass const *a, VertexClass const *b)
{
    VertexClass *c = new(Vertex, (a->x * b->x), (a->y * b->y), (a->z * b->z));

    return c;
}

VertexClass *Vertex_div(VertexClass const *a, VertexClass const *b)
{
    if (a->x == 0 || a->y == 0 || a->z == 0)
        raise("error : can't divise per 0");
    VertexClass *c = new(Vertex, (a->x / b->x), (a->y / b->y), (a->z / b->z));

    return c;
}

static bool Vertex_eq(VertexClass const *a, VertexClass const *b)
{
    if (a->x == b->x && a->y == b->y && a->z == b->z)
        return true;
    return false;
}

static bool Vertex_gt(VertexClass const *a, VertexClass const *b)
{
    if (a->x > b->x && a->y > b->y && a->z > b->z)
        return true;
    return false;
}

static bool Vertex_lt(VertexClass const *a, VertexClass const *b)
{
    if (a->x < b->x && a->y < b->y && a->z < b->z)
        return true;
    return false;
}
// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = (binary_operator_t)&Vertex_mul,
        .__div__ = (binary_operator_t)&Vertex_div,
        .__eq__ = (binary_comparator_t)&Vertex_eq,
        .__gt__ = (binary_comparator_t)&Vertex_gt,
        .__lt__ = (binary_comparator_t)&Vertex_lt,
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
