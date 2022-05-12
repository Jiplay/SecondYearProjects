/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-julien.garsia
** File description:
** MyTextE
*/

#ifndef MYTEXTE_HPP_
#define MYTEXTE_HPP_

#include "raylib.h"

class MyTextE {
    public:
        MyTextE();
        ~MyTextE();
        const char *my_TextFormat(const char *text, ...);
        void my_DrawText(const char *text, int posX, int posY, int fontSize, Color color);
        void my_DrawFPS(int posX, int posY);
};

#endif /* !MYTEXTE_HPP_ */
