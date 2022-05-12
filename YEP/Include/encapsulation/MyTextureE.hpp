/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** MyTextureE
*/

#ifndef MYTEXTUREE_HPP_
#define MYTEXTUREE_HPP_

#include "raylib.h"
#include <iostream>

class MyTextureE
{
private:
public:
    MyTextureE(/* args */);
    ~MyTextureE();
    Image my_LoadImage(const char *fileName);
    void my_ImageResize(Image *image, int newWidth, int newHeight);
    Texture2D my_LoadTexture(const char *fileName);
    Texture2D my_LoadTextureFromImage(Image image);
    void my_DrawTexture(Texture2D texture, int posX, int posY, Color tint);
    void my_DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint);
    void my_UnloadTexture(Texture2D texture);
};

#endif /* !MYTEXTUREE_HPP_ */
