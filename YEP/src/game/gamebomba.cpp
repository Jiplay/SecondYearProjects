/*
** EPITECH PROJECT, 2021
** gamebomba.cpp
** File description:
** gamebomba.cpp
*/

#include "../../Include/gamebomba.hpp"
#include "unistd.h"

gamebomba::gamebomba()
{
}

gamebomba::gamebomba(Vector3 pos, std::list<gamebox> b)
{
    std::shared_ptr <MyModelsE> Model;
    frameCreation = GetTime();
    bombaPos = pos;
    bill = true;
    vUP = {bombaPos.x+0, bombaPos.y, bombaPos.z+5};
    bombalist = b;
}

gamebomba::~gamebomba()
{
}

Vector3 gamebomba::getPos()
{
    return bombaPos;
}

void gamebomba::bombaStay()
{
    Model->my_DrawSphere(bombaPos, 1.0f, DARKGREEN);
}

void gamebomba::explode(std::vector<myVector3> *rv)
{
    Model->my_DrawSphere(bombaPos, 1.0f, RED);
    for (std::list<gamebox>::iterator it = bombalist.begin(); it != bombalist.end(); it++) {
        // std::cout << "##################### @POS =  " << it->enemyBoxPos.x << " "<< it->enemyBoxPos.y << " " << it->enemyBoxPos.z << std::endl;
        Model->my_DrawCubeV(bombaPos, (Vector3){1, 2, 5}, ORANGE);
        if (Model->my_CheckCollisionBoxes((BoundingBox){(Vector3){ bombaPos.x - 1,
                                     bombaPos.y - 2/2,
                                     bombaPos.z - 5/2},
                          (Vector3){ bombaPos.x + 1,
                                     bombaPos.y + 2/2,
                                     bombaPos.z + 5/2}}, (BoundingBox){(Vector3){ bombalist.front().getEnemyPos().x - 1,
                                     it->getEnemyPos().y - 1,
                                     it->getEnemyPos().z - 1},
                          (Vector3){ it->getEnemyPos().x + 1,
                                     it->getEnemyPos().y + 1,
                                     it->getEnemyPos().z + 1}})) {
                                         it->setIsNoMore();
                                        //  std::cout << "################### @spagethu" << it->enemyBoxPos.x<< it->enemyBoxPos.y<< it->enemyBoxPos.z << std::endl;
                                     }

        Model->my_DrawCubeV(bombaPos, (Vector3){5, 2, 1}, ORANGE);
        if (Model->my_CheckCollisionBoxes((BoundingBox){(Vector3){ bombaPos.x - 5/2,
                                     bombaPos.y - 1/2,
                                     bombaPos.z - 2/2},
                          (Vector3){ bombaPos.x + 5,
                                     bombaPos.y + 1/2,
                                     bombaPos.z + 2/2}}, (BoundingBox){(Vector3){ bombalist.front().getEnemyPos().x - 1,
                                     it->getEnemyPos().y - 1,
                                     it->getEnemyPos().z - 1},
                          (Vector3){ it->getEnemyPos().x + 1,
                                     it->getEnemyPos().y + 1,
                                     it->getEnemyPos().z + 1}}))
                                    {
                                        it->setIsNoMore();
                                        //  std::cout << k @spagethu" << it->enemyBoxPos.x<< it->enemyBoxPos.y<< it->enemyBoxPos.z << std::endl;

                                    }
    }
    for (std::vector<myVector3>::iterator it = rv->begin(); it != rv->end(); it++) {
        if (Model->my_CheckCollisionBoxes((BoundingBox) {{ 
                                    bombaPos.x - 5/2,
                                    bombaPos.y - 1/2,
                                    bombaPos.z - 2/2},
                          (Vector3){bombaPos.x + 5,
                                    bombaPos.y + 1/2,
                                    bombaPos.z + 2/2}}, (BoundingBox) {(Vector3) { it->getPosition().x - 1/2,
                                    it->getPosition().y - 2/2,
                                    it->getPosition().z - 1/2},
                          (Vector3){it->getPosition().x + 1/2,
                                    it->getPosition().y + 2/2,
                                    it->getPosition().z + 1/2,}})) {
                                        it->setAlive(false);
                                    }
        if (Model->my_CheckCollisionBoxes((BoundingBox) {{ 
                                    bombaPos.x - 2/2,
                                    bombaPos.y - 1/2,
                                    bombaPos.z - 5/2},
                          (Vector3){bombaPos.x + 2,
                                    bombaPos.y + 1/2,
                                    bombaPos.z + 5/2}}, (BoundingBox) {(Vector3) { it->getPosition().x - 1/2,
                                    it->getPosition().y - 2/2,
                                    it->getPosition().z - 1/2},
                          (Vector3){it->getPosition().x + 1/2,
                                    it->getPosition().y + 2/2,
                                    it->getPosition().z + 1/2,}})) {
                                        it->setAlive(false);
                                    }
    }
}

std::list<gamebox> gamebomba::getList()
{
    return bombalist;
}

bool gamebomba::check_time(int time)
{
    if(GetTime() < frameCreation + time)
        return true;
    return false;
}
