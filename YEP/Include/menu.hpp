#include "encapsulation/MyAudioE.hpp"
#include "encapsulation/MyCoreE.hpp"
#include "encapsulation/MyKeyE.hpp"
#include "encapsulation/MyShapesE.hpp"
#include "encapsulation/MyTextE.hpp"
#include "encapsulation/MyTextureE.hpp"
#include <memory>
#include <list>
#include <map>

enum RETURN {
    NEXT_GAME = 2,
    EXIT = 0,
    NO_EXIT = 1
};

class Menu
{
public:
    Menu();
    ~Menu();
    int MenuLoop();
    bool check_collision(Vector2 mousePoint, Rectangle const *rect, int *btnState);
    int check_all_collision(Vector2 mousePoint);
    void init_textures();
    void init_sounds();
    void init_rects();
    void draw_textures();
    void audio_management();
    void show_options();
    int getPlayer();
    void editControl();
    void keybinds();
    void createBoxes();
    void settingRec(std::list<Rectangle> *r);
    void scarfyIsDancing();
    std::map<int, std::string> getMap(void);

private:
    std::unique_ptr <MyCoreE> Core;
    std::unique_ptr <MyAudioE> Audio;
    std::unique_ptr <MyTextureE> Texture;
    std::unique_ptr <MyShapesE> Shapes;
    std::unique_ptr <MyTextE> Text;
    std::unique_ptr <MyKeyE> Key;
    std::string line;
    std::list<Rectangle> rectList;
    std::map<int, std::string> mappy;

    Music music;
    Sound fxButton;
    Image gear;
    Image exit_btn;
    Rectangle nbPlayerUp;
    Rectangle nbPlayerDown;
    Rectangle gear_Rect;
    Rectangle exitRec;
    Rectangle sourceRec;
    Rectangle btnBounds;
    Rectangle rect_less;
    Rectangle rect_upp;
    Texture2D text_gear;
    Texture2D wallpaper;
    Texture2D text_exit;
    Texture2D button;
    Texture2D fireball;
    Vector2 fireballPosition;
    Rectangle fireballFrameRec;

    Vector2 mousePoint;

    int nbPlayer;
    int screenWidth;
    int screenHeight;
    int num_frames;
    int status;
    int btnState;
    int letterCount;
    int framesCounter;
    int currentFrame;
    float Xscarfy;
    float frameHeight;
    float timePlayed;
    float volume;
    bool pause;
    bool btnAction;
    bool option_on;
    bool mouseOnText;
};