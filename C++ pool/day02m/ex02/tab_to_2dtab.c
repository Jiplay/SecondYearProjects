/*
** EPITECH PROJECT, 2020
** ex01
** File description:
** tab_to_2dtab.c
*/

#include <unistd.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int a = 0;
    int b = 0;
    int len = length * width;
    int **dest = malloc(sizeof(int*) * length);

    for (int i = 0; i < length + 1; i++) {
        dest[i] = malloc(sizeof(int) * width);
    }

    for (int i = 0; i != len; i++) {
        if (b == width - 1) {
            dest[a][b] = tab[i];
            a++;
            b = 0;
        } else {
            dest[a][b] = tab[i];
            b++;
        }   
    }
    res[0] = dest;
}
