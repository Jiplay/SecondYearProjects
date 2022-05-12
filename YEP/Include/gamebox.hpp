/*
** EPITECH PROJECT, 2021
** gamebox.hpp
** File description:
** gamebox.hpp
*/

#ifndef _GAMEBOX_HPP_
#define _GAMEBOX_HPP_

#include "../Include/encapsulation/MyAudioE.hpp"
#include "../Include/encapsulation/MyCoreE.hpp"
#include "../Include/encapsulation/MyTextureE.hpp"
#include "../Include/encapsulation/MyTextE.hpp"

class myVector3
{
public:
    myVector3();
    myVector3(Vector3 p);
    ~myVector3();
    Vector3 getPosition();
    bool getAlive();
    void setPosition(Vector3 p);
    void setAlive(bool b);

private:
    Vector3 position;
    bool isAlive;
};

class gamebox
{
public:
    gamebox(Vector3 pos, Vector3 size);
    gamebox(Vector3 pos, Vector3 size, bool state);
    gamebox();
    ~gamebox();

    void setIsNoMore();
    bool getIsNoMore();
    bool getIsDestrucible();
    Vector3 getEnemyPos();
    Vector3 getEnemySize();

private:
    Vector3 enemyBoxPos;
    Vector3 enemyBoxSize;
    bool is_destructible;
    bool is_no_more;
};


#endif /* !_GAMEBOX_HPP_ */
