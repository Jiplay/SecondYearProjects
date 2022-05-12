/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** MyCoreE
*/

#ifndef MYCOREE_HPP_
#define MYCOREE_HPP_

#include "raylib.h"
#include <iostream>

class MyCoreE
{
private:
    /* data */
public:
    MyCoreE(int width, int height, const char *title);
    ~MyCoreE();
    bool my_WindowShouldClose(void);
    Vector2 my_GetMousePosition(void);
    bool my_IsMouseButtonDown(int button);
    bool my_IsMouseButtonReleased(int button);
    void my_ClearBackground(Color color);
    void my_BeginDrawing(void);
    void my_EndDrawing(void);
    void my_SetMouseCursor(int cursor);
    int my_GetKeyPressed(void);
    void my_SetTargetFPS(int fps);
    int my_GetRandomValue(int min, int max);
    void my_BeginMode3D(Camera3D camera);
    void my_EndMode3D(void);
    bool my_IsWindowReady(void);

};

#endif /* !MYCOREE_HPP_ */
