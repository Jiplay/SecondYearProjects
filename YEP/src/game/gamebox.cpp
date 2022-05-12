/*
** EPITECH PROJECT, 2021
** gamebox.cpp
** File description:
** gamebox.cpp
*/

#include "../../Include/gamebox.hpp"

gamebox::gamebox(Vector3 pos, Vector3 size)
{
    enemyBoxPos = pos;
    enemyBoxSize = size;
    is_no_more = false;
}

gamebox::gamebox(Vector3 pos, Vector3 size, bool state)
{
    enemyBoxPos = pos;
    enemyBoxSize = size;
    is_destructible = state;
    is_no_more = false;
}

gamebox::gamebox()
{
    enemyBoxPos = {};
    enemyBoxSize = {};
}

gamebox::~gamebox()
{
}

myVector3::myVector3()
{

}

myVector3::myVector3(Vector3 p)
{
    position = p;
    isAlive = true;
}

myVector3::~myVector3()
{

}

Vector3 myVector3::getPosition()
{
    return position;
}

bool myVector3::getAlive()
{
    return isAlive;
}

void myVector3::setPosition(Vector3 p)
{
    position = p;
}

void myVector3::setAlive(bool b)
{
    isAlive = b;
}

void gamebox::setIsNoMore()
{
    is_no_more = true;
}

bool gamebox::getIsNoMore()
{
    return is_no_more;
}

bool gamebox::getIsDestrucible()
{
    return is_destructible;
}

Vector3 gamebox::getEnemyPos()
{
    return enemyBoxPos;
}

Vector3 gamebox::getEnemySize()
{
    return enemyBoxSize;
}