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

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
    unsigned int position)
{
    double_list_t new_node = malloc(sizeof(doublelist_node_t));
    double_list_t tmp = *front_ptr;
    unsigned int i = 1;

    if (new_node == NULL)
        return false;

    new_node->value = elem;
    if (position == 0) {
        double_list_add_elem_at_front(front_ptr, elem);
        return true;
    }
    while (tmp->next != NULL) {
        if (i == position)
            break;
        tmp = tmp->next;
        i++;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;
    return true;
}

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL)
        return 0;
    return (list->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
    double value)
{
    double_list_t tmp = list;
    unsigned int i = 1;

    if (tmp == NULL)
        return NULL;

    while (tmp->next != NULL) {
        if (tmp->value == value)
            return (tmp);
        tmp = tmp->next;
        i++;
    }
    return NULL;
}
