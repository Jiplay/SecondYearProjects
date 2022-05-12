/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-julien.garsia
** File description:
** MyModelsE
*/

#ifndef MYMODELSE_HPP_
#define MYMODELSE_HPP_

#include "raylib.h"
#include <iostream>

class MyModelsE {
    public:
        MyModelsE();
        ~MyModelsE();
        bool my_CheckCollisionBoxes(BoundingBox box1, BoundingBox box2);
        bool my_IsKeyDown(int key);
        void my_DrawCubeV(Vector3 position, Vector3 size, Color color);
        void my_DrawCube(Vector3 position, float width, float height, float length, Color color);
        void my_DrawGrid(int slices, float spacing);
        void my_DrawSphere(Vector3 centerPos, float radius, Color color);
        void my_DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
        Model my_loadModel(std::string fileName);
        Texture2D my_loadTexture(std::string fileName);
        void my_setMaterialTexture(Material *material, int mapType, Texture2D texture);
    protected:
    private:
};

#endif /* !MYMODELSE_HPP_ */
