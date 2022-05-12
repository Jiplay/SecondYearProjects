/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** MyTextureE
*/

#include "MyTextureE.hpp"

MyTextureE::MyTextureE()
{
}

MyTextureE::~MyTextureE()
{
}

Image MyTextureE::my_LoadImage(const char *fileName)
{
    Image gear = LoadImage(fileName);
    return gear;
}

void MyTextureE::my_ImageResize(Image *image, int newWidth, int newHeight)
{
    ImageResize(image, newWidth, newHeight);
}

Texture2D MyTextureE::my_LoadTexture(const char *fileName)
{
    Texture2D wallpaper = LoadTexture(fileName);
    return wallpaper;
}

Texture2D MyTextureE::my_LoadTextureFromImage(Image image)
{
    Texture2D text_gear = LoadTextureFromImage(image);
    return text_gear;
}

void MyTextureE::my_DrawTexture(Texture2D texture, int posX, int posY, Color tint)
{
    DrawTexture(texture, posX, posY, tint);
}

void MyTextureE::my_DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint)
{
    DrawTextureRec(texture, source, position, tint);
}

void MyTextureE::my_UnloadTexture(Texture2D texture)
{
    UnloadTexture(texture);
}