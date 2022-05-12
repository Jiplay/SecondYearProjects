/*
** menu.cpp for B-YEP-400-PAR-4-1-indiestudio-julien.garsia in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/final/B-YEP-400-PAR-4-1-indiestudio-julien.garsia/src/menu
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri May 28 11:26:36 AM 2021 julien.garsia
** Last update Fri May 28 11:26:36 AM 2021 julien.garsia
*/

#include "../../Include/menu.hpp"
#include "../../Include/controlData.hpp"
#include "../../Include/error.hpp"

Menu::Menu()
{
    num_frames = 3;
    framesCounter = 0;
    currentFrame = 0;
    Xscarfy = 0;
    screenWidth = 1920;
    screenHeight = 1080;
    nbPlayer = 1;
    mouseOnText = false;
    letterCount = 0;

    Core = std::make_unique <MyCoreE> (screenWidth, screenHeight, "Menu");
    Shapes = std::make_unique <MyShapesE>();
    Key = std::make_unique <MyKeyE>();
    Control<std::string> b("save_control.txt");
    mappy = b.getctrl();
    init_textures();
    init_sounds();
    init_rects();
    mousePoint = { 0.0f, 0.0f };
    timePlayed = 0.0f;
}

void Menu::init_sounds()
{
    Audio = std::make_unique <MyAudioE>();
    music = Audio->my_LoadMusicStream("src/resources/music.mp3");
    fxButton = Audio->my_LoadSound("src/resources/buttonfx.wav");// Load button sound
    Audio->my_PlayMusicStream(music);
    Audio->my_SetSoundVolume(fxButton, 0.3);
    Audio->my_SetMusicVolume(music, 0.3);
}

void Menu::init_rects()
{
    gear_Rect = {1800, 932, 1909, 1020};
    rect_less = {271, 109, 80, 80};
    rect_upp = {379, 109, 80, 80};
    exitRec = {40, 915, 330, 1023};
    frameHeight = (float)button.height/num_frames;
    sourceRec = { 0, 0, (float)button.width, frameHeight };
    btnBounds = { screenWidth/2.0f - button.width/2.0f, screenHeight/2.0f - button.height/num_frames/2.0f + 300, (float)button.width, frameHeight };
    nbPlayerUp = { 350, 213, 80, 80};
    nbPlayerDown = { 260, 213, 80, 80};
    rectList.push_back({1550, 200, 50, 50});
    rectList.push_back({1550, 250, 50, 50});
    rectList.push_back({1550, 300, 50, 50});
    rectList.push_back({1550, 350, 50, 50});
}

void Menu::init_textures()
{
    wallpaper = Texture->my_LoadTexture("src/resources/wallpaper.png");
    button = Texture->my_LoadTexture("src/resources/button.png"); // Load button texture
    fireball = Texture->my_LoadTexture("src/resources/scarfy.png");
    fireballPosition = { 50.0f, 50.0f };
    fireballFrameRec = { 0.0f, 0.0f, (float)fireball.width/6, (float)fireball.height };
    gear = Texture->my_LoadImage("src/resources/gear.png"); // Load button texture
    exit_btn = Texture->my_LoadImage("src/resources/exit.png"); // Load exit texture
    Texture->my_ImageResize(&exit_btn, 190, 108);
    Texture->my_ImageResize(&gear, 190, 108);
    text_gear = Texture->my_LoadTextureFromImage(gear);
    text_exit = Texture->my_LoadTextureFromImage(exit_btn);

    btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    btnAction = false;         // Button action should be activated
    status = 0;
    option_on = false;
    volume = 0.1;
}

Menu::~Menu()
{
    Texture->my_UnloadTexture(text_exit); // Unload exit button texture
    Texture->my_UnloadTexture(button);  // Unload button texture
    Texture->my_UnloadTexture(text_gear);  // Unload text_gear texture
    Texture->my_UnloadTexture(wallpaper);  // Unload button texture
    Audio->my_UnloadSound(fxButton);  // Unload sound
    Audio->my_UnloadMusicStream(music);
}

bool Menu::check_collision(Vector2 mousePoint, Rectangle const *rect, int *btnState)
{
    bool btnAction = 0;

    if (Shapes->my_CheckCollisionPointRec(mousePoint, *rect)) {
        if (Core->my_IsMouseButtonDown(0))
            *btnState = 2;
        else *btnState = 1;

        if (Core->my_IsMouseButtonReleased(0)) btnAction = true;
    }
    else *btnState = 0;

    if (btnAction ==  true)
        return true;
    return false; 
}

int Menu::check_all_collision(Vector2 mousePoint)
{
    if (check_collision(mousePoint, &gear_Rect, &status) == 1)
        option_on = !option_on;
    if (check_collision(mousePoint, &rect_less, &status) == 1) {
        if (volume > 0.0)
            volume = volume - 0.1;
    }
    if (check_collision(mousePoint, &rect_upp, &status) == 1) {
        if (volume < 1.0)
            volume = volume + 0.1;
    }
    if (check_collision(mousePoint, &exitRec, &status) == 1)
        return RETURN::EXIT; // allows to exit
    if (check_collision(mousePoint, &nbPlayerUp, &status) == 1) {
        if (nbPlayer < 4)
            nbPlayer++;
    }
    if (check_collision(mousePoint, &nbPlayerDown, &status) == 1) {
        if (nbPlayer != 1)
            nbPlayer--;
    }
    return RETURN::NO_EXIT;
}

void Menu::draw_textures(void)
{
    Texture->my_DrawTexture(wallpaper, 0, 0, PURPLE);
    Texture->my_DrawTexture(text_exit, 40, 915, WHITE);
    Texture->my_DrawTexture(text_gear, 1766, 915, WHITE);
}

void Menu::audio_management(void)
{
    Audio->my_SetMusicVolume(music, volume);
    Audio->my_UpdateMusicStream(music);
    if (Key->my_IsKeyPressed(KEY_P)) {
        pause = !pause;
        if (pause) Audio->my_PauseMusicStream(music);
        else Audio->my_ResumeMusicStream(music);
    }
}

void Menu::editControl()
{
    Text->my_DrawText(TextFormat("%i", nbPlayer), 1310, 190, 80, RED);
    Text->my_DrawText(Text->my_TextFormat("UP"), 1410, 200, 40, RED);
    Text->my_DrawText(Text->my_TextFormat("DOWN"), 1410, 250, 40, RED);
    Text->my_DrawText(Text->my_TextFormat("LEFT"), 1410, 300, 40, RED);
    Text->my_DrawText(Text->my_TextFormat("RIGHT"), 1410, 350, 40, RED);
}

void Menu::settingRec(std::list<Rectangle> *r)
{
    std::map<int, std::string>::iterator mapit = mappy.find(nbPlayer-1);
    std::string str2 = mapit ->second;
    for (std::list<Rectangle>::iterator it = r->begin(); it != r->end(); it++)
    {
        std::string str1;
        str1.push_back(str2.front());
        Shapes->my_DrawRectangleRec(*it, LIGHTGRAY);
        if (mouseOnText) Shapes->my_DrawRectangleLines(it->x, it->y, it->width, it->height, RED);
        else Shapes->my_DrawRectangleLines(it->x, it->y, it->width, it->height, DARKGRAY);
        Text->my_DrawText(str1.c_str(), it->x + 5, it->y + 8, 40, MAROON);
        str2.erase(0, 1);
    }
}

void Menu::keybinds()
{
    std::list<Rectangle> rect2 = rectList;
    rect2.pop_front();
    rect2.pop_back();

    if (Shapes->my_CheckCollisionPointRec(Core->my_GetMousePosition(), rectList.front()))
    {
        mappy[nbPlayer -1].replace(0, 1, line);
        line.clear();
    }
    if (Shapes->my_CheckCollisionPointRec(Core->my_GetMousePosition(), rectList.back()))
    {
        mappy[nbPlayer -1].replace(3, 1, line);
        line.clear();
    }
    if (Shapes->my_CheckCollisionPointRec(Core->my_GetMousePosition(), rect2.front()))
    {
        mappy[nbPlayer -1].replace(1, 1, line);
        line.clear();
    }
    if (Shapes->my_CheckCollisionPointRec(Core->my_GetMousePosition(), rect2.back()))
    {
        mappy[nbPlayer -1].replace(2, 1, line);
        line.clear();
    }
}

void Menu::createBoxes()
{
    char name[2] = "\0";
    std::list<Rectangle> rect2 = rectList;
    rect2.pop_front();
    rect2.pop_back();

    for (std::list<Rectangle>::iterator it = rectList.begin(); it != rectList.end(); it++) {
        if (Shapes->my_CheckCollisionPointRec(Core->my_GetMousePosition(), *it))
            mouseOnText = true;
        else
            mouseOnText = false;
        if (mouseOnText) {
            Core->my_SetMouseCursor(MOUSE_CURSOR_IBEAM);
            int key = Core->my_GetKeyPressed();

            while (key > 0) {
                if ((key >= 32) && (key <= 125)){
                    name[letterCount] = (char)key;
                    name[letterCount+1] = '\0';
                    line+=(char)key;
                    keybinds();
                }
                key = Core->my_GetKeyPressed();
            }
        }
        else Core->my_SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
}

void Menu::show_options(void)
{
    if (option_on == true) {
        Text->my_DrawText(Text->my_TextFormat("OPTION : "), 200, 80, 20, RED);
        Text->my_DrawText(Text->my_TextFormat("Volume : - ---------- + (Press P to pause)"), 200, 130, 20, RED);
        Text->my_DrawText(Text->my_TextFormat("Player : -        +"), 200, 230, 20, RED);
        Text->my_DrawText(TextFormat("%i", nbPlayer), 320, 190, 80, RED);
        editControl();
        settingRec(&rectList);
        createBoxes();
    }
}

void Menu::scarfyIsDancing()
{
    framesCounter++;
    if (framesCounter >= (60/10)) {
        framesCounter = 0;
        currentFrame++;
        if (currentFrame > 5) {
            currentFrame = 0;
        }
        fireballFrameRec.x = (float)currentFrame*(float)fireball.width/6;
    }
    Xscarfy += 10.0f;
    if (Xscarfy >= 1920) {
        Xscarfy = 0.0f;
    }
    fireballPosition = {Xscarfy, 50.0f} ;
}

int Menu::MenuLoop(void)
{
    if (Core->my_IsWindowReady() == false)
        throw MenuError("Window is not ready", "");
    while (!Core->my_WindowShouldClose()) {
        audio_management();
        btnAction = false;

        if (check_all_collision(Core->my_GetMousePosition()) == RETURN::EXIT)
            return RETURN::EXIT;
        if (check_collision(Core->my_GetMousePosition(), &btnBounds, &btnState) == true) {
            Audio->my_PlaySound(fxButton);
            return RETURN::NEXT_GAME;
        }
        scarfyIsDancing();
        sourceRec.y = btnState*frameHeight;
        Core->my_BeginDrawing();
        Core->my_ClearBackground(RAYWHITE);
        draw_textures();
        show_options();
        Texture->my_DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE); // Draw button frame
        Texture->my_DrawTextureRec(fireball, fireballFrameRec, fireballPosition, WHITE); // Draw button frame
        Core->my_EndDrawing();
    }
    return 0;
}

int Menu::getPlayer(void)
{
    return nbPlayer;
}

std::map<int, std::string> Menu::getMap(void)
{
    return mappy;
}