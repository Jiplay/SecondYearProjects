/*
** EPITECH PROJECT, 2021
** gamecore.cpp
** File description:
** gamecore.cpp
*/

#include "../../Include/gamecore.hpp"
#include "../../Include/error.hpp"

void gamecore::createPlayer()
{
    playerMap[0] = std::make_unique<Player> (Vector3{ -13.0f, 1.0f, 13.0f }, 1, mappy[3]);
    playerMap[1] = std::make_unique<Player> (Vector3{ -13.0f, 1.0f, -13.0f }, 2, mappy[1]);
    playerMap[2] = std::make_unique<Player> (Vector3{ 13.0f, 1.0f, -13.0f }, 3, mappy[2]);
    playerMap[3] = std::make_unique<Player> (Vector3{ 13.0f, 1.0f, 13.0f }, 4, mappy[0]);

    playerMap[0].get()->setboomlist(boomlist);
    playerMap[1].get()->setboomlist(boomlist);
    playerMap[2].get()->setboomlist(boomlist);
    playerMap[3].get()->setboomlist(boomlist);

}

void gamecore::fillMyList()
{
    char **myMap = generateMap();
    std::vector<float> blockIndex = {-16.0f, -13.0f, -10.0f, -7.0f, -4.0f, -1.0f,
                                    1.0f, 4.0f, 7.0f, 10.0f, 13.0f, 16.0f};
    std::list<Vector3> res;
    int x = 0;
    int y = 0;

    while (y != 12) {
        if (myMap[y][x] == 'x' || myMap[y][x] == 'b' || myMap[y][x] == 'c')
            res.push_back(Vector3({blockIndex.at(x), 1.0f, blockIndex.at(y)}));
        x++;
        if (x == 12) {
            x = 0;
            y++;
        }
    }
    prepareMyBoxes(res);
}

gamecore::gamecore(std::map<int, std::string> m)
{
    num_frames = 3;
    screenWidth = 1920;
    screenHeight = 1080;


    Core = std::make_unique <MyCoreE> (screenWidth, screenHeight, "Game");
    Model = std::make_unique <MyModelsE>();
    Text = std::make_unique <MyTextE>();
    camera = { { 0.0f, 30.0f, 30.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
    Basecamera = { { 0.0f, 30.0f, 30.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };

    mappy = m;

    gamebox Box({ -4.0f, 1.0f, 0.0f }, { 2.0f, 2.0f, 2.0f }, false);
    BBox = Box;
    
    gamebox DBox({ 4.0f, 1.0f, 0.0f }, { 2.0f, 2.0f, 2.0f }, true);
    DestBox = DBox;
    // boomlist.push_back(DBox);

    defaultBlockSize = {2.0f, 2.0f, 2.0f};
    fillMyList();

    createPlayer();
    createWall();
    framesCounter = 0;

    x = 0.0f;
    y = 30.0f;
    z = 30.0f;
    isgoingup = false;
    gr = false;
    cam = false;
    isplayingcam = true;

    myVectorPlayer = getPlayerPosition();


    Core->my_SetTargetFPS(60);
    soundtrack();
    victory = false;
}

void gamecore::soundtrack()
{
    Audio = std::make_unique <MyAudioE>();
    music = Audio->my_LoadMusicStream("src/resources/codbo.mp3");
    Audio->my_PlayMusicStream(music);
    Audio->my_SetMusicVolume(music, 0.1);
}

void gamecore::drawPlayerList()
{
    std::vector<myVector3>::iterator itbis = myVectorPlayer.begin();
    for (std::map<int, std::unique_ptr<Player>>::iterator it = playerMap.begin(); it != playerMap.end(); it++){
        if (itbis->getAlive() != false) {
            Model->my_DrawModelEx(it->second->getModel(), it->second->getPos(), it->second->getPlayerRotationAxis(), it->second->getPlayerRotationAngle(), (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
        }
        itbis++;
    }
}

void gamecore::updatedestlist()
{
    for (std::map<int, std::unique_ptr<Player>>::iterator it = playerMap.begin(); it != playerMap.end(); it++) {
        it->second->updateboomlist(boomlist);
    }
        // std::cout << "####################### @" << boomlist.size() << std::endl;
    for (std::list<gamebox>::iterator ittri = boomlist.begin(); ittri != boomlist.end(); ittri++) {
        // std::cout << "###################### @" << ittri->enemyBoxPos.x << " " << ittri->is_no_more << " " << ittri->is_destructible << std::endl;
    }

}

void gamecore::compareList(std::list<gamebox> playerList)
{
    std::list<gamebox>::iterator itbis = playerList.begin();
    for (std::list<gamebox>::iterator it = boomlist.begin(); it != boomlist.end(); it++) {
        if (itbis->getIsNoMore() == true && it->getIsNoMore() == false) {
            boomlist.clear();
            boomlist = playerList;
            updatedestlist();
            break;
        }
        itbis++;
    }
}

void gamecore::allPlayerMove(int frame)
{
    for (std::map<int, std::unique_ptr<Player>>::iterator it = playerMap.begin(); it != playerMap.end(); it++) {
        it->second->playerMove();
        it->second->setMyVector3(myVectorPlayer);
        myVectorPlayer = it->second->bombaPlace();
        compareList(it->second->getList());
    }
}

void gamecore::handleBoxCollision()
{
    for (std::map<int, std::unique_ptr<Player>>::iterator it = playerMap.begin(); it != playerMap.end(); it++) {
        it->second->getCollision(it->second->getPos(), it->second->getSize(), BBox);
    }
}

void gamecore::handleDestBoxCollision()
{
    for (std::map<int, std::unique_ptr<Player>>::iterator it = playerMap.begin(); it != playerMap.end(); it++) {
        for (std::list<gamebox>::iterator itbis = boomlist.begin(); itbis != boomlist.end(); itbis++) {
            if (itbis->getIsNoMore() == false) {
                it->second->getCollision(it->second->getPos(), it->second->getSize(), gamebox({itbis->getEnemyPos()}, itbis->getEnemySize(), itbis->getIsDestrucible()));
            }
        }
    }

}

void gamecore::destructionboom(std::list<gamebox> *b)
{
    for (std::list<gamebox>::iterator it = boomlist.begin(); (it != boomlist.end()); it++) {
        if (it->getIsNoMore() == true) {
            b->erase(it);
        }
    }
}

std::vector<myVector3> gamecore::getPlayerPosition()
{
    std::vector<myVector3> myPlayerVector;
    for (std::map<int, std::unique_ptr<Player>>::iterator it = playerMap.begin(); it != playerMap.end(); it++) {
        myPlayerVector.push_back(it->second->getPos());
    }
    return myPlayerVector;
}

void gamecore::handleBorderCollision()
{
    for (std::map<int, std::unique_ptr<Player>>::iterator it = playerMap.begin(); it != playerMap.end(); it++) {
        it->second->getCollision(it->second->getPos(), it->second->getSize(), BLeftWall);
        it->second->getCollision(it->second->getPos(), it->second->getSize(), BRightWall);
        it->second->getCollision(it->second->getPos(), it->second->getSize(), BUpWall);
        it->second->getCollision(it->second->getPos(), it->second->getSize(), BDownWall);
    }
}

void gamecore::getPlayerCollision()
{
    handleBorderCollision();
    handleBoxCollision();
    handleDestBoxCollision();
}

void gamecore::drawdestructible()
{
    for (std::list<gamebox>::iterator it = boomlist.begin(); (it != boomlist.end()); it++)
    {
        if (it->getIsNoMore() == false) {
            Model->my_DrawCubeV(it->getEnemyPos(), it->getEnemySize(), DARKBROWN);
        } else {
        }
    }
}

void gamecore::updatePlayerPosition()
{
    std::vector<myVector3>::iterator itbis = myVectorPlayer.begin();
    for (std::map<int, std::unique_ptr<Player>>::iterator it = playerMap.begin(); it != playerMap.end(); it++) {
        itbis->setPosition(it->second->getPos());
        itbis++;
    }

}

void gamecore::ggbg()
{
    Texture2D winnerpic = Texture->my_LoadTexture("src/resources/wallpaper.png");
    std::cout << "winner" << std::endl;
    Texture->my_DrawTexture(winnerpic, 0, 0, PURPLE);
}

int gamecore::updateAlive()
{
    int i = 0;
    int j = 0;
    for (std::vector<myVector3>::iterator it = myVectorPlayer.begin(); it != myVectorPlayer.end(); it++) {
        if (it->getAlive() == false) {
            playerMap[i].get()->setDeath();
            j++;
        }
        i += 1;
        if (j== 3) {
            //ggbg();
            victory = true;
        }
    }
}

int gamecore::gamecoreLoop()
{
    if (Core->my_IsWindowReady() == false)
        throw GameError("Window is not ready", "");
    while (!Core->my_WindowShouldClose())
    {
        Audio->my_UpdateMusicStream(music);
        // if (IsKeyPressed(KEY_SPACE))
        if (isplayingcam == true)
            cameraShaking();
        Core->my_BeginDrawing();
        Core->my_ClearBackground(RAYWHITE);
        Core->my_BeginMode3D(camera);
        if(victory == false) {
            updatePlayerPosition();
            allPlayerMove(framesCounter);
            updateAlive();
            // Model->my_DrawCube(BBox.getEnemyPos(), BBox.getEnemySize().x, BBox.getEnemySize().y, BBox.getEnemySize().z, GRAY);
            drawWall();
            getPlayerCollision();
            drawdestructible();
            drawPlayerList();
            Model->my_DrawGrid(35, 1.0f);
        }
        else
        {
            return 1;
        }
        Core->my_EndMode3D();
        Text->my_DrawFPS(10, 10);
        Core->my_EndDrawing();
        //----------------------------------------------------------------------------------
    }
    return 0;
}

gamecore::~gamecore()
{   
}

void gamecore::cameraShaking()
{
    framesCounter++;
    camera = { { x, y, z }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
    if (((framesCounter/2)%2) == 1) {
        if (y >= 25 && isgoingup == false && isplayingcam == true) {
            y -= 0.4f;
        if (y <= 25)
            isgoingup = true;
        } else if (y <= 30 && isgoingup == true && isplayingcam == true) {
            y += 0.05;
            //x += 1;
            z -= 0.5;
        }
        if (y >= 30 && isgoingup == true) {
            cam = true;
        }
        if (cam == true) {
            camera = Basecamera;
            cam = false;
            isgoingup = true;
            isplayingcam = false;
        }
        framesCounter = 0;
    }
}

void gamecore::prepareMyBoxes(std::list<Vector3> pos)
{
    for (std::list<Vector3>::iterator it = pos.begin(); it != pos.end(); it++) {
        boomlist.push_back(gamebox ({it->x, it->y, it->z}, defaultBlockSize, true));
    }
}