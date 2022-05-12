/*
** EPITECH PROJECT, 2020
** ex01
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>

void menger(int size, int level, int x, int y)
{
    if (level > 0 && size >=3) {
        level = level - 1;
        size = size / 3;
        printf("%03d %03d %03d\n", size, size + x, size + y);
        menger(size, level, x, y);
        menger(size, level, x, y + size);
        menger(size, level, x, y + 2 * size);
        menger(size, level, x + size, y);
        menger(size, level, x + size, y + 2 * size);
        menger(size, level, x + 2 *size, y);
        menger(size, level, x + 2 * size, y + size);
        menger(size, level, x + 2 * size, y + 2 * size);
    }
}

int main(int ac, char** av)
{
    if (ac == 3) {
        menger(atoi(av[1]), atoi(av[2]), 0, 0);
        return 0;
    } else
        return 84;
}
