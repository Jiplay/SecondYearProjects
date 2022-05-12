/*
** EPITECH PROJECT, 2020
** ex01
** File description:
** mem_ptr.c
*/

#include "double_list.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t tmp = *front_ptr;

    if (tmp == NULL)
        return false;

    *front_ptr = tmp->next;
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t tmp = *front_ptr;

    if (tmp == NULL)
        return false;

    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = NULL;

    return true;
}

bool double_list_del_elem_at_position(double_list_t *front_ptr,
    unsigned int position)
{
    double_list_t tmp = *front_ptr;
    unsigned int i = 1;

    while (tmp->next != NULL) {
        if (i == position)
            break;
        tmp = tmp->next;
        i++;
    }

    tmp->next = tmp->next->next;

    return true;
}

double double_list_get_elem_at_back(double_list_t list)
{
    double_list_t tmp = list;

    if (tmp == NULL)
        return 0;

    while (tmp->next != NULL)
        tmp = tmp->next;

    return (tmp->value);
}

double double_list_get_elem_at_position(double_list_t list,
    unsigned int position)
{
    double_list_t tmp = list;
    unsigned int i = 0;

    while (tmp->next != NULL) {
        if (i == position)
            break;
        tmp = tmp->next;
        i++;
    }
    return (tmp->value);
}
