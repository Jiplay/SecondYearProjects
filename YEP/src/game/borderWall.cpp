/*
** EPITECH PROJECT, 2021
** borderWall.cpp
** File description:
** borderWall.cpp
*/

#include "../../Include/gamebox.hpp"
#include "../../Include/gamebomba.hpp"
#include "../../Include/gamecore.hpp"

void gamecore::createWall()
{
    gamebox upWall({ 0.0f, 1.0f, -17.5f }, {36.0f, 2.0f, 1.0f});
    gamebox downWall({ 0.0f, 1.0f, 17.5f }, {36.0f, 2.0f, 1.0f});
    gamebox leftWall({ -17.5f, 1.0f, 0.0f }, {1.0f, 2.0f, 36.0f});
    gamebox rightWall({ 17.5f, 1.0f, 0.0f }, {1.0f, 2.0f, 36.0f});
   
    BUpWall = upWall;
    BDownWall = downWall;
    BLeftWall = leftWall;
    BRightWall = rightWall;
}

void gamecore::drawWall()
{
    Model->my_DrawCube(BUpWall.getEnemyPos(), BUpWall.getEnemySize().x, BUpWall.getEnemySize().y, BUpWall.getEnemySize().z, BLACK);
    Model->my_DrawCube(BDownWall.getEnemyPos(), BDownWall.getEnemySize().x, BDownWall.getEnemySize().y, BDownWall.getEnemySize().z, BLACK);
    Model->my_DrawCube(BLeftWall.getEnemyPos(), BLeftWall.getEnemySize().x, BLeftWall.getEnemySize().y, BLeftWall.getEnemySize().z, BLACK);
    Model->my_DrawCube(BRightWall.getEnemyPos(), BRightWall.getEnemySize().x, BRightWall.getEnemySize().y, BRightWall.getEnemySize().z, BLACK);
}