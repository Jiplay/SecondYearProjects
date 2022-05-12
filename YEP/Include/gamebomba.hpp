/*
** EPITECH PROJECT, 2021
** gamebomba.hpp
** File description:
** gamebomba.hpp
*/

#ifndef _GAMEBOMBA_HPP_
#define _GAMEBOMBA_HPP_

#include "../Include/encapsulation/MyAudioE.hpp"
#include "../Include/encapsulation/MyCoreE.hpp"
#include "../Include/encapsulation/MyModelsE.hpp"
#include "../Include/encapsulation/MyTextureE.hpp"
#include "../Include/encapsulation/MyTextE.hpp"
#include "../Include/gamebox.hpp"
#include <memory>
#include <list>
#include <vector>

class gamebomba
{
public:
    std::shared_ptr <MyModelsE> Model;
    gamebomba();
    gamebomba(Vector3 pos, std::list<gamebox> b);
    ~gamebomba();

    Vector3 getPos();
    std::list<gamebox> getList();
    void updateBombaTimer();
    void bombaStay();
    void explode(std::vector<myVector3> *rv);
    bool check_time(int time);
    void boomsound();
    Rectangle recUP;
    Vector3 vUP;

private:
    std::list<gamebox> bombalist;
    Vector3 bombaPos;
    int bombaSize;
    int bombaTimer;
    bool bill;
    double frameCreation;
};


#endif /* !_GAMEBOMBA_HPP_ */
