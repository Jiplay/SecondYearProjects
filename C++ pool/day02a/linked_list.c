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

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int i = 0;

    while (list != NULL) {
        list = list->next;
        i++;
    }

    return (i);
}

bool double_list_is_empty(double_list_t list)
{
    if (list == NULL)
        return true;

    return false;
}

void double_list_dump(double_list_t list)
{
    int i = 0;

    while (list != NULL) {
        printf("%f\n", list->value);
        list = list->next;
        i++;
    }
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    doublelist_node_t* new_node = malloc(sizeof(doublelist_node_t));

    if (new_node == NULL)
        return false;

    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;

    return true;
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    double_list_t new_node = malloc(sizeof(doublelist_node_t));
    double_list_t tmp = *front_ptr;

    if (new_node == NULL)
        return false;

    new_node->value = elem;

    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = new_node;

    return true;
}
