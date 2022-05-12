/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

enum Library {
    sfml_ = true,
    ncurses_ = false
};

class IGames {
    public:
        virtual ~IGames() = default;
        virtual void setGame() = 0;
        virtual int hit() = 0;
        virtual int move() = 0;
        virtual void endGame() = 0;
        virtual void gameLoop() = 0;
        virtual int game(bool t) = 0;
};

#endif /* !IGAMES_HPP_ */
