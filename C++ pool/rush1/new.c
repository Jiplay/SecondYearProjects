/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 01
*/

#include "new.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    Class *new_obj;
    va_list arg_list;

    va_start(arg_list, class);
    new_obj = va_new(class, &arg_list);
    va_end(arg_list);
    return new_obj;
}

Object *va_new(const Class *class, va_list *ap)
{
    Class *new_obj = malloc(class->__size__);
    
    if (new_obj == NULL)
        raise("failed to allowed memory");
    memcpy(new_obj, class, class->__size__);
    if (class->__ctor__ != NULL) {
    class->__ctor__(new_obj, ap);
    }

    return new_obj;
}

void delete(Object *ptr)
{
    Class *new_obj = (Class *)ptr;

    if (new_obj->__dtor__)
        new_obj->__dtor__(ptr);
    else
        free(ptr);
}
