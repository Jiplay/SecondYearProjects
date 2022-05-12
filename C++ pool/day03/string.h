/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** string.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

#ifndef STRING_H
#define STRING_H

typedef struct string_t
{
    char *str;

    // Member functions
    void (*string_init)(struct string_t *this, const char *s);
    void (*append_s)(struct string_t *this, const struct string_t *ap);
    void (*append_c)(struct string_t *this, const char *ap);
    void (*assign_s)(struct string_t *this, const struct string_t *str);
    void (*assign_c)(struct string_t *this, const char *s);
    char (*at)(const struct string_t *this, size_t pos);
    void (*string_destroy)(struct string_t *this);
    void (*clear)(struct string_t *this);
    int (*size)(const struct string_t *this);
    int (*compare_s)(const struct string_t *this, const struct string_t *str);
    int (*compare_c)(const struct string_t *this, const char *str);
    size_t (*copy)(const struct string_t *this, char *s, size_t n, size_t pos);
    const char (*c_str)(const struct string_t *this);
    int (*empty)(const struct string_t *this);
    int (*find_s)(const struct string_t *, const struct string_t *, size_t);
    int (*find_c)(const struct string_t *this, const char *str, size_t pos);

} string_t;

void assign_c(string_t *this, const char *s);
void assign_s(string_t *this, const string_t *str);
void append_c(string_t *this, const char *ap);
void append_s(string_t *this, const string_t *ap);
void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int size(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);

#endif
