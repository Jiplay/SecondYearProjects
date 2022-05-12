/*
** EPITECH PROJECT, 2021
** player.hpp
** File description:
** player.hpp
*/

#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "../Include/encapsulation/MyAudioE.hpp"
#include "../Include/encapsulation/MyCoreE.hpp"
#include "../Include/encapsulation/MyModelsE.hpp"
#include "../Include/encapsulation/MyTextureE.hpp"
#include "../Include/encapsulation/MyTextE.hpp"
#include "../Include/gamebox.hpp"
#include "../Include/gamebomba.hpp"
#include <memory>
#include <list>
#include <vector>

class Player
{
private:
    std::unique_ptr <MyCoreE> Core;
    std::unique_ptr <MyModelsE> ModelE;

    Model playerModel;
    Texture2D playerTexture;

    Vector3 playerRotationAxis;
    float playerRotationAngle;

    Vector3 playerPosition;
    Vector3 playerSize;
    bool collision;
    int lastkey;
    int ID;

    int UP;
    int DOWN;
    int RIGHT;
    int LEFT;
    int BOOM;

    Vector3 bombaPos;
    bool place_bomba;
    bool bombe_state;

    bool isDead;
    
    std::string bindings;
    std::list<gamebox> boomlist;
    gamebomba bombe;
    std::vector<myVector3> myVector;

public:
    Player();
    Player(Vector3 playerPosition);
    Player(int ID);
    Player(std::string s);
    Player(int ID, std::string s);
    Player(Vector3 playerPosition, std::string s);
    Player(Vector3 playerPosition, int ID);
    Player(Vector3 playerPosition, int ID, std::string s);
    ~Player();

    Vector3 getPos();
    std::list<gamebox> getList();
    Vector3 getSize();
    Vector3 getPlayerRotationAxis();
    float getPlayerRotationAngle();
    Model getModel();
    bool getCollisionState();
    void playerMove();
    void getCollision(Vector3 playerPosition, Vector3 playerSize, gamebox entity);
    int key_to_int(int nb);
    void defineBinding(int ID);
    std::vector<myVector3> bombaPlace();
    void setMyVector3(std::vector<myVector3> v);

    void setDeath();
    void setboomlist(std::list<gamebox> b);
    void updateboomlist(std::list<gamebox> b);
};

enum LASTDIR{
    LEFT = 1,
    RIGHT = 2,
    UP = 3,
    DOWN = 4
};


#endif /* !_PLAYER_HPP_ */
