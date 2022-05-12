/*
** EPITECH PROJECT, 2021
** SFML.hpp
** File description:
** SFML.hpp
*/

#ifndef _SFML_HPP_
#define _SFML_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../ALibs.hpp"
class SFML : public ALibs {
class Snake
{
    public:
        Snake(sf::RenderWindow &window, int sSize, int sSpeed);

        void Move();
        void Update(sf::Event &event);
        void Draw();
        int getScore();

    private:
        sf::RenderWindow &mWindow;
        sf::Clock mClock;
        sf::CircleShape mFood;
        int mTimeToUpdate;
        int mSize;
        int mSpeed;
        bool mLeft, mRight, mUp, mDown;
        float mCurrentTime;
        std::vector<sf::RectangleShape> mSnakes;
        int _score;

        void CheckCollision();
        void AddCase();
        void FoodGenerator();
};
    
    public:
        SFML();
        ~SFML() = default;
        int createWindow();
        void destroyWindow();
        int getCommand();
        int getCommand(sf::Event event);
        void displayWindow();
        int randInt(int rmin, int rmax);
        void setGame();
        int gameLoop();
        int mainLoop();
    private:
        sf::RenderWindow _win;
        sf::Texture _backtext;
        sf::Sprite _backsprite;
        sf::Event _event;
};

extern "C" SFML* create_object();
extern "C" void destroy_object(SFML* object);


#endif /* !_SFML_HPP_ */
