/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** MyShapesE
*/

#ifndef MYSHAPESE_HPP_
#define MYSHAPESE_HPP_

#include "raylib.h"
#include <iostream>

class MyShapesE {
    public:
        MyShapesE();
        ~MyShapesE();
        bool my_CheckCollisionPointRec(Vector2 point, Rectangle rec);
        void my_DrawRectangleRec(Rectangle rec, Color color);
        void my_DrawRectangleLines(int posX, int posY, int width, int height, Color color);

    private:
};

#endif /* !MYSHAPESE_HPP_ */
