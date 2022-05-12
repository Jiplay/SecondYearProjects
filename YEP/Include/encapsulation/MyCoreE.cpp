/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** MyCoreE
*/

#include "MyCoreE.hpp"

MyCoreE::MyCoreE(int width, int height, const char *title)
{
    InitWindow(width, height, title);
    SetTargetFPS(30);
}

MyCoreE::~MyCoreE()
{
    CloseWindow();
}

bool MyCoreE::my_WindowShouldClose(void)
{
    return WindowShouldClose();
}

Vector2 MyCoreE::my_GetMousePosition(void)
{
    return GetMousePosition();   
}

bool MyCoreE::my_IsMouseButtonDown(int button)
{
    return IsMouseButtonDown(button);
}

bool MyCoreE::my_IsMouseButtonReleased(int button)
{
    return IsMouseButtonReleased(button);
}

void MyCoreE::my_ClearBackground(Color color)
{
    ClearBackground(color);
}

void MyCoreE::my_BeginDrawing(void)
{
    BeginDrawing();
}

void MyCoreE::my_EndDrawing(void)
{
    EndDrawing();
}

void MyCoreE::my_SetMouseCursor(int cursor)
{
    SetMouseCursor(cursor);
}

int MyCoreE::my_GetKeyPressed(void)
{
    return GetKeyPressed();
}

void MyCoreE::my_SetTargetFPS(int fps)
{
    SetTargetFPS(fps);
}

int MyCoreE::my_GetRandomValue(int min, int max)
{
    return GetRandomValue(min, max);
}

void MyCoreE::my_BeginMode3D(Camera3D camera)
{
    BeginMode3D(camera);
}

void MyCoreE::my_EndMode3D(void)
{
    EndMode3D();
}

bool MyCoreE::my_IsWindowReady(void)
{
    return IsWindowReady();
}