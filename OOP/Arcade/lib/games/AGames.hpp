/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
** File description:
** AGames
*/

#ifndef AGAMES_HPP_
#define AGAMES_HPP_

#include "IGames.hpp"

class AGames : public IGames {
    public:
        virtual ~AGames() = default;
        virtual void setGame() = 0;
        virtual int hit() = 0;
        virtual int move() = 0;
        virtual void endGame() = 0;
        virtual void gameLoop() = 0;
        virtual int game(bool t) = 0;
    protected:
        int _height;
        int _width;
};

#endif /* !AGAMES_HPP_ */
