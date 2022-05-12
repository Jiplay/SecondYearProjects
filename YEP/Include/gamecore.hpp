/*
** EPITECH PROJECT, 2021
** gamecore.hpp
** File description:
** gamecore.hpp
*/

#ifndef _GAMECORE_HPP_
#define _GAMECORE_HPP_

#include "encapsulation/MyAudioE.hpp"
#include "../Include/gamebox.hpp"
#include "../Include/gamebomba.hpp"
#include "../Include/destructibleWall.hpp"
#include "../Include/player.hpp"
#include <memory>
#include <map>
#include <list>
#include <vector>

class gamecore
{
public:
    gamecore(std::map<int, std::string> m);
    ~gamecore();

    gamebomba bombaPlace();
    
    void createWall();
    void drawWall();

    int gamecoreLoop();
    void soundtrack();
    void createPlayer();
    void updatedestlist();
    void allPlayerMove(int frame);
    void drawPlayerList();
    void getPlayerCollision();
    void destructionboom(std::list<gamebox> *b);
    void handleBoxCollision();
    void drawdestructible();
    void handleDestBoxCollision();
    void cameraShaking();
    void compareList(std::list<gamebox> playerList);
    void updatePlayerPosition();
    void ggbg();
    int updateAlive();
    void prepareMyBoxes(std::list<Vector3> pos);
    void handleBorderCollision();
    void fillMyList();

    std::vector<myVector3> getPlayerPosition();

private:
    std::unique_ptr <MyAudioE> Audio;
    std::unique_ptr <MyCoreE> Core;
    std::unique_ptr <MyModelsE> Model;
    std::unique_ptr <MyTextE> Text;
    std::unique_ptr <MyTextureE> Texture;

    std::unique_ptr <Player> readyPlayerOne;
    std::unique_ptr <Player> readyPlayerTwo;
    std::unique_ptr <Player> readyPlayerThree;
    std::unique_ptr <Player> readyPlayerFour;
    std::map<int, std::unique_ptr<Player>> playerMap;
    std::map<int, std::string> mappy;

    std::list<gamebox> boomlist;

    std::vector<myVector3> myVectorPlayer;

    gamebox BBox;
    gamebox BUpWall;
    gamebox BDownWall;
    gamebox BLeftWall;
    gamebox BRightWall;    
    gamebox DestBox;
    Camera camera;
    Camera Basecamera;
    Music music;

    Vector3 defaultBlockSize;

    int framesCounter;
    int randValue;
    float bombaSize;
    int num_frames;
    int screenWidth;
    int screenHeight;

    float x;
    float y;
    float z;
    bool isgoingup;
    bool gr;
    bool cam;
    bool isplayingcam;
    bool victory;

    // Vector3 bombaPos;
    // bool place_bomba;
};

char **generateMap(void);

#endif /* !_GAMECORE_HPP_ */
