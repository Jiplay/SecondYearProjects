/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** string.c
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    char *dest = malloc(sizeof(char) * strlen(s) + 1);

    dest = strcpy(dest, s);
    this->str = dest;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->string_destroy = &string_destroy;
    this->append_s = &append_s;
    this->assign_c = &assign_c;
    this->at = &at;
    this->clear = &clear;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
}

void string_destroy(string_t *this)
{
    if (this->str != NULL)
        free(this->str);
}

void assign_s(string_t *this, const string_t *str)
{
    if (str->str == NULL) {
        this->str = NULL;
    } else {
        free(this->str);
        this->str = malloc(strlen(str->str) + 1);
        strcpy(this->str, str->str);
    }
}

void assign_c(string_t *this, const char *c)
{
    if (c == NULL) {
        this->str = NULL;
    } else {
        free(this->str);
        this->str = malloc(strlen(c) + 1);
        strcpy(this->str, c);
    }
}

const char *c_str(const string_t *this)
{
    return(this->str);
}
