#include "../Include/menu.hpp"
#include "../Include/gamecore.hpp"
#include "../Include/error.hpp"
#include <unistd.h>
#include <memory>
#include <fstream>

bool save_control(std::map<int, std::string> *savedMap)
{
    std::ofstream myfile;
    myfile.open ("save_control.txt");
    for(std::map<int, std::string>::iterator it = savedMap->begin(); it != savedMap->end(); it++) {
        myfile << it->second << "\n";
    }
    myfile.close();
    return true;
}

void victoryscreen()
{
    const int screenWidth = 800;
    const int screenHeight = 650;
    InitWindow(screenWidth, screenHeight, "Victory Screen");
    Texture2D texture = LoadTexture("src/resources/victoire.png");        // Texture loading
    std::unique_ptr <MyAudioE> Audio = std::make_unique <MyAudioE>();
    Sound win = Audio->my_LoadSound("src/resources/buttonfx.wav");
    Audio->my_SetSoundVolume(win, 0.3);
    const char message[128] = "CREDITS :\nby Julien G., Theau B., Ibrahim Z.,\nOlivier B., Lucas S., Oscar L.\n;)";

    int framesCounter = 0;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        framesCounter++;
        BeginDrawing();
        Audio->my_PlaySound(win);
        ClearBackground(BLACK);

        DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
        DrawText(TextSubtext(message, 0, framesCounter/10), 150, 520, 20, YELLOW);
        EndDrawing();
    }
    UnloadTexture(texture);       // Texture unloading
    CloseWindow();                // Close window and OpenGL context
}

int main(void)
{
    try
    {
        std::map<int, std::string> mainMap;
        Menu *mn = new Menu();
        int players = mn->getPlayer();
        if (mn->MenuLoop() == 2) {
            mainMap = mn->getMap();
            save_control(&mainMap);
            delete mn;
            gamecore *gc = new gamecore(mainMap);
            int i = gc->gamecoreLoop();
            delete gc;
            if (i == 1)
                 victoryscreen();
        }
    }
    catch(const IndieError &e)
    {
        std::cerr << e.what() << '\n';
    }
    


    return 0;
}
