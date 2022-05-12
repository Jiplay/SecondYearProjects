/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** MyShapesE
*/

#include "MyShapesE.hpp"

MyShapesE::MyShapesE()
{
}

MyShapesE::~MyShapesE()
{
}


bool MyShapesE::my_CheckCollisionPointRec(Vector2 point, Rectangle rec)
{
    return CheckCollisionPointRec(point, rec);
}

void MyShapesE::my_DrawRectangleRec(Rectangle rec, Color color)
{
    DrawRectangleRec(rec, color);
}

void MyShapesE::my_DrawRectangleLines(int posX, int posY, int width, int height, Color color)
{
    DrawRectangleLines(posX, posY, width, height, color);
}
