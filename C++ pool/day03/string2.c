/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** string.c
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (this == NULL || this->str == "" || str->str == ""
        || str == NULL);
        return (-1);

    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL || str == "" || this->str == "")
        return (-1);

    return(strcmp(this->str, str));
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    char *dest = malloc(sizeof(char) * strlen(this->str));
    unsigned int j = 0;

    for (int i = pos; this->str[i] != '\0'; i++) {
        if (j < n) {
            dest[j] = this->str[i];
            j++;
        }
    }
    s = dest;

    free(dest);
    return j;
}
