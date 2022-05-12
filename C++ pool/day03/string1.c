/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** string.c
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    int tmp = strlen(this->str) + 1;
    char *dest = malloc(sizeof(char) * tmp);

    strcpy(dest, this->str);
    free(this->str);
    this->str = malloc(tmp + strlen(ap->str) + 1);
    strcat(strcpy(this->str, dest), ap->str);
    free(dest);
}

void append_c(string_t *this, const char *ap)
{
    int tmp = strlen(this->str) + 1;
    char *dest = malloc(sizeof(char) * tmp);

    strcpy(dest, this->str);
    free(this->str);
    this->str = malloc(tmp + strlen(ap) + 1);
    strcat(strcpy(this->str, dest), ap);
    free(dest);
}

char at(const string_t *this, size_t pos)
{
    if (pos > strlen(this->str) -1)
        return -1;
    return this->str[pos];
}

void clear(string_t *this)
{
    if (this != NULL) {
        free(this->str);
        this->str = malloc(sizeof(char) * 1);
        this->str[0] = '\0';
    }
}

int size(const string_t *this)
{
    int i = 0;

    if (this == NULL || this->str == NULL)
        return (-1);

    return strlen(this->str);
}
