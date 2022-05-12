/*
** EPITECH PROJECT, 2021
** ILibs.hpp
** File description:
** ILibs.hpp
*/

#ifndef _ILIBS_HPP_
#define _ILIBS_HPP_

class ILibs {
    public:
        virtual ~ILibs() = default;
        virtual int createWindow() = 0;
        virtual void destroyWindow() = 0;
        virtual int getCommand() = 0;
        virtual void setGame() = 0;
        virtual int gameLoop() = 0;
        virtual int mainLoop() = 0;
};

#endif /* !_ILIBS_HPP_ */
