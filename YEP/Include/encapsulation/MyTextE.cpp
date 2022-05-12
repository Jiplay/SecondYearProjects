/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-julien.garsia
** File description:
** MyTextE
*/

#include "MyTextE.hpp"

MyTextE::MyTextE()
{
}

MyTextE::~MyTextE()
{
}

const char *MyTextE::my_TextFormat(const char *text, ...)
{
    return TextFormat(text);
}

void MyTextE::my_DrawText(const char *text, int posX, int posY, int fontSize, Color color)
{
    DrawText(text, posX, posY, fontSize, color);
}

void MyTextE::my_DrawFPS(int posX, int posY)
{
    DrawFPS(posX, posY);
}
