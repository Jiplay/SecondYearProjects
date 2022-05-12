/*
** EPITECH PROJECT, 2021
** player.cpp
** File description:
** player.cpp
*/

#include "../../Include/player.hpp"

Player::Player()
{
}

Player::Player(Vector3 playerPosition)
{
}

Player::Player(int ID)
{
}

Player::Player(std::string s)
{
}

Player::Player(int ID, std::string s)
{
}

Player::Player(Vector3 playerPosition, std::string s)
{
}

Player::Player(Vector3 playerPosition, int ID)
{
}

Player::Player(Vector3 playerPosition, int ID, std::string s)
{
    ModelE = std::make_unique <MyModelsE>();
    playerModel = ModelE->my_loadModel(TextFormat("src/game/resources/players/Plane0%i.obj", ID));
    playerTexture = ModelE->my_loadTexture(TextFormat("src/game/resources/players/Plane0%i.png", ID));
    ModelE->my_setMaterialTexture(&playerModel.materials[0], MAP_DIFFUSE, playerTexture);
    this->playerPosition = playerPosition;
    playerSize = { 1.0f, 2.0f, 1.0f };
    this->ID = ID;
    place_bomba = false;
    bombe_state = false;
    collision = false;
    bindings = s;
    playerRotationAxis = {0.0f, 1.0f, 0.0f};
    playerRotationAngle = -90;
    isDead = false;
    defineBinding(ID);
}

Player::~Player()
{
}

Vector3 Player::getPos()
{
    return playerPosition;
}

Vector3 Player::getSize()
{
    return playerSize;
}

float Player::getPlayerRotationAngle()
{
    return playerRotationAngle;
}

Vector3 Player::getPlayerRotationAxis()
{
    return playerRotationAxis;
}

Model Player::getModel()
{
    return playerModel;
}

bool Player::getCollisionState()
{
    return collision;
}

int Player::key_to_int(int nb)
{
    int a = 0;
    for(std::string::iterator it = bindings.begin(); it!= bindings.end(); it++){
        if (a==nb)
            return int(*it);
        a++;
    }
    return 0;
}

void Player::defineBinding(int ID)
{
    if (ID == 1) {
        UP = key_to_int(0);
        DOWN =  key_to_int(1);
        LEFT = key_to_int(2);
        RIGHT =  key_to_int(3);
        BOOM = KEY_R;
    }
    else if (ID == 2) {
        UP = key_to_int(0);
        DOWN =  key_to_int(1);
        LEFT = key_to_int(2);
        RIGHT =  key_to_int(3);
        BOOM = KEY_U;
    }
    else if (ID == 3) {
        UP = KEY_UP;
        LEFT = KEY_LEFT;
        DOWN = KEY_DOWN;
        RIGHT = KEY_RIGHT;
        BOOM = KEY_Y;
    }
    else if (ID == 4) {
        UP = key_to_int(0);
        DOWN =  key_to_int(1);
        LEFT = key_to_int(2);
        RIGHT =  key_to_int(3);
        BOOM = KEY_T;
    }
}

void Player::playerMove()
{
    if (ModelE->my_IsKeyDown(RIGHT)) {
        playerRotationAngle = 0;
        if (collision && lastkey == RIGHT) {
            playerPosition.x -= 0.2f;
        } else {
            playerPosition.x += 0.1f;
            lastkey = RIGHT;
        }
        collision = false;
    }
    else if (ModelE->my_IsKeyDown(LEFT)) {
        playerRotationAngle = 180;
        if (collision && lastkey == LEFT) {
            playerPosition.x += 0.2f;
        } else {
            playerPosition.x -= 0.1f;
            lastkey = LEFT;
        }
        collision = false;
    }
    else if (ModelE->my_IsKeyDown(DOWN)) {
        playerRotationAngle = -90;
        if (collision && lastkey == DOWN) {
            playerPosition.z -= 0.2f;
        } else {
            playerPosition.z += 0.1f;
            lastkey = DOWN;
        }
        collision = false;
    }
    else if (ModelE->my_IsKeyDown(UP)) {
        playerRotationAngle = 90;
        if (collision && lastkey == UP) {
            playerPosition.z += 0.2f;
        } else {
            playerPosition.z -= 0.1f;
            lastkey = UP;
        }
        collision = false;
    }
}

void Player::getCollision(Vector3 playerPosition, Vector3 playerSize, gamebox entity)
{
    if (ModelE->my_CheckCollisionBoxes(
        (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
                                 playerPosition.y - playerSize.y/2,
                                 playerPosition.z - playerSize.z/2 },
                      (Vector3){ playerPosition.x + playerSize.x/2,
                                 playerPosition.y + playerSize.y/2,
                                 playerPosition.z + playerSize.z/2}},
        (BoundingBox){(Vector3){ entity.getEnemyPos().x - entity.getEnemySize().x/2,
                                 entity.getEnemyPos().y - entity.getEnemySize().y/2,
                                 entity.getEnemyPos().z - entity.getEnemySize().z/2 },
                      (Vector3){ entity.getEnemyPos().x + entity.getEnemySize().x/2,
                                 entity.getEnemyPos().y + entity.getEnemySize().y/2,
                                 entity.getEnemyPos().z + entity.getEnemySize().z/2 }}))
                                     collision = true; 
}

std::vector<myVector3> Player::bombaPlace()
{
    if (ModelE->my_IsKeyDown(BOOM) && isDead == false) {
        if (place_bomba == false) {
            place_bomba = true;
            bombe = gamebomba(playerPosition, boomlist);
            place_bomba = false;
            bombe_state = true;
        }
    }
    else if (bombe_state == true && bombe.check_time(2) == true) {
        bombe.bombaStay();
    }
    else if (bombe_state == true && bombe.check_time(2) == false && bombe.check_time(3) == true) {
        bombe.explode(&myVector);
        setboomlist(bombe.getList());
    }
    return myVector;
}

void Player::setboomlist(std::list<gamebox> b)
{
    for (std::list<gamebox>::iterator it = b.begin(); it != b.end(); it++) {
        // std::cout << it->enemyBoxPos.x << " " << it->is_no_more << std::endl;
    }
    boomlist = b;
}

void Player::updateboomlist(std::list<gamebox> b)
{
    b.clear();
    boomlist = b;
}

std::list<gamebox> Player::getList()
{
    return boomlist;
}

void Player::setMyVector3(std::vector<myVector3> v)
{
    myVector = v;
}

void Player::setDeath()
{
    isDead = true;
}