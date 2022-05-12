/*
** EPITECH PROJECT, 2020
** ex01
** File description:
** func_ptr
*/

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_42(const char *str)
{
    printf("42\n");
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--)
        printf("%c", str[i]);

    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void do_action(action_t action, const char *str)
{
    void (*fun_ptr_list[])(const char *) = {print_normal, print_reverse,
    print_upper, print_42};
    (*fun_ptr_list[action]) (str);
}
