/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** string3.c
*/

#include "string.h"

int empty(const string_t *this)
{
    if (strlen(this->str) == 0)
        return (1);
    return (0);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *dest = malloc(sizeof(char) * strlen(this->str) + 1);
    char *tmp;
    int a = 0;

    if (pos > strlen(this->str) || strlen(str->str) > strlen(this->str))
        return (-1);

    for (int i = 0;this->str[i] != '\0'; i++) {
        if (i > pos) {
            dest[a] = this->str[i];
            a++;
        }
    }
    tmp = strstr(dest, str->str);
    if (tmp == NULL)
        return (-1);

    free(dest);
    return (strlen(this->str) - strlen(tmp));
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *dest = malloc(sizeof(char) * strlen(this->str) + 1);
    char *tmp;
    int a = 0;

    if (pos > strlen(this->str) || strlen(str) > strlen(this->str))
        return (-1);

    for (int i = 0;this->str[i] != '\0'; i++) {
        if (i > pos) {
            dest[a] = this->str[i];
            a++;
        }
    }
    tmp = strstr(dest, str);
    if (tmp == NULL)
        return (-1);

    free(dest);
    return (strlen(this->str) - strlen(tmp));
}

