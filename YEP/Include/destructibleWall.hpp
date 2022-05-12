/*
** EPITECH PROJECT, 2021
** destructibleWall.hpp
** File description:
** destructibleWall.hpp
*/

#ifndef _DESTRUCTIBLEWALL_HPP_
#define _DESTRUCTIBLEWALL_HPP_

#include "../Include/encapsulation/MyAudioE.hpp"
#include "../Include/encapsulation/MyCoreE.hpp"
#include "../Include/encapsulation/MyTextureE.hpp"
#include "../Include/encapsulation/MyTextE.hpp"

class destructibleWall
{
public:
    destructibleWall(Vector3 pos, Vector3 size);
    destructibleWall();
    ~destructibleWall();

    Vector3 destBoxPos;
    Vector3 destBoxSize;
    bool is_destructible;

protected:
};


#endif /* !_DESTRUCTIBLEWALL_HPP_ */
