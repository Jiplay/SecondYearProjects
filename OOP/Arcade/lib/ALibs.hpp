/*
** ALibs.hpp for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/lib
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Mar 18 10:47:45 AM 2021 julien.garsia
** Last update Tue Mar 22 9:58:10 AM 2021 julien.garsia
*/

#ifndef ALIBS_HPP_
#define ALIBS_HPP_

#include "ILibs.hpp"

class ALibs : public ILibs
{
    public:
        virtual ~ALibs() = default;
        virtual int createWindow() = 0;
        virtual void destroyWindow() = 0;
        virtual int getCommand() = 0;
        virtual void setGame() = 0;
        virtual int gameLoop() = 0;
        virtual int mainLoop() = 0;
    
    protected:
        int _height;
        int _width;
        std::string _title;
        char *_title_char;
};

#endif /* !ALIBS_HPP_ */
