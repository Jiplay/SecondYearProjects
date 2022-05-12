/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-julien.garsia
** File description:
** MyModelsE
*/

#include "MyModelsE.hpp"

MyModelsE::MyModelsE()
{
}

MyModelsE::~MyModelsE()
{
}

bool MyModelsE::my_CheckCollisionBoxes(BoundingBox box1, BoundingBox box2)
{
    return CheckCollisionBoxes(box1, box2);
}

bool MyModelsE::my_IsKeyDown(int key)
{
    return IsKeyDown(key);
}

void MyModelsE::my_DrawCubeV(Vector3 position, Vector3 size, Color color)
{
    DrawCubeV(position, size, color);
}

void MyModelsE::my_DrawCube(Vector3 position, float width, float height, float length, Color color)
{
    DrawCube(position, width, height, length, color);
}

void MyModelsE::my_DrawGrid(int slices, float spacing)
{
    DrawGrid(slices, spacing);
}

void MyModelsE::my_DrawSphere(Vector3 centerPos, float radius, Color color)
{
    DrawSphere(centerPos, radius, color);
}

Model MyModelsE::my_loadModel(std::string fileName)
{
    const char *file = fileName.c_str();
    return LoadModel(file);
}

Texture2D MyModelsE::my_loadTexture(std::string fileName)
{
    const char *file = fileName.c_str();
    return LoadTexture(file);
}

void MyModelsE::my_setMaterialTexture(Material *material, int mapType, Texture2D texture)
{
    SetMaterialTexture(material, mapType, texture);
}

void MyModelsE::my_DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{
    DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
}