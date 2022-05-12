/*
** EPITECH PROJECT, 2021
** SFML.hpp
** File description:
** SFML.hpp
*/

#include "SFML.hpp"

extern "C" SFML* create_object()
{
  return new SFML;
}

extern "C" void destroy_object(SFML* object)
{
  delete object;
}

SFML::SFML()
{
    _height = 1200;
    _width = 1200;
}

void SFML::setGame()
{

}

int SFML::gameLoop()
{

}

int SFML::randInt(int rmin, int rmax) {
    return rand() % rmax + rmin;
}

int SFML::getCommand()
{
    return 0;
}
int SFML::createWindow()
{
    _win.create(sf::VideoMode(_height, _width), "Arcade Project");
    _win.setFramerateLimit(30);
    
    sf::Font font;
    sf::Text text;
    if (!font.loadFromFile("police.ttf")) {
        return 84;
    }
    text.setFont(font);
    text.setString("Press E to go back to main menu\nPress Z to open Pacman\nPress R to open Nibbler\nPress Q to quit");
    text.setCharacterSize(50);
    text.setColor(sf::Color::White);
    while (_win.isOpen()) {
        while (_win.pollEvent(_event)) {
            switch (_event.type) {
                case sf::Event::KeyPressed:
                    if (_event.key.code == sf::Keyboard::E) {
                        _win.clear();
                        return 3;
                    }
                    if (_event.key.code == sf::Keyboard::Z) {
                        _win.clear();
                        return 11;
                    }
                    if (_event.key.code == sf::Keyboard::R) {
                        _win.clear();
                        return 14;
                    }
                    if (_event.key.code == sf::Keyboard::Q) {
                        _win.clear();
                        return 0;
                    }
                    break;
                case sf::Event::Closed:
                    _win.close();
                    break;
            }
        }
        _win.draw(text);
        displayWindow();
    }
}

void SFML::destroyWindow()
{
    _win.close();
}

void SFML::displayWindow()
{
    _win.display();
}

SFML::Snake::Snake(sf::RenderWindow &window, int sSize, int sSpeed) : mWindow(window), mSize(sSize), mSpeed(sSpeed)
{
    mTimeToUpdate = 250; // 1/4 second
    mCurrentTime = 0.0f;
    mLeft = mUp = mDown = false;
    mRight = true;
    _score = -1;
    srand(std::time(0));
    AddCase();
    AddCase();
    AddCase();
    AddCase();

    mFood.setRadius(mSize / 2); // Food circle
    mFood.setFillColor(sf::Color::Green);
    FoodGenerator();
}

void SFML::Snake::FoodGenerator() // Generates the new food position
{
    int randomY = rand() % (mWindow.getSize().y / mSize);
    int randomX = rand() % (mWindow.getSize().x / mSize);

    for(unsigned int i = 0; i < mSnakes.size(); i++) {
        if((mSnakes[0].getPosition().x != randomX * mSize) && (mSnakes[0].getPosition().y != randomY)) {
            mFood.setPosition(randomX * mSize, randomY * mSize);
        }
    }
    _score +=1;
}

void SFML::Snake::AddCase() // Add 1 more case
{
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(32, 32));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);

    if (mSnakes.empty()) {
        rect.setFillColor(sf::Color::Red);
        rect.setPosition(320, 256);
    } else {
        rect.setFillColor(sf::Color::Yellow);
        rect.setPosition(mSnakes[mSnakes.size() - 1].getPosition().x - rect.getSize().x, mSnakes[mSnakes.size() - 1].getPosition().y);
    }

    mSnakes.push_back(rect);
}

void SFML::Snake::Move() // Move the snake every 250 ms and check collision
{
    if (mCurrentTime < mTimeToUpdate) {
        mCurrentTime += mClock.restart().asMilliseconds();
    }
    else {
        mCurrentTime = 0.0f;

        if (mSnakes.size() > 1) {
            for (unsigned int i = mSnakes.size() - 1; i > 0; i--) {
                mSnakes[i].setPosition(sf::Vector2f(mSnakes[i-1].getPosition().x, mSnakes[i-1].getPosition().y));
            }
        }

        if (mLeft)
            mSnakes[0].move(-mSpeed, 0);

        if (mRight)
            mSnakes[0].move(mSpeed, 0);

        if (mUp)
            mSnakes[0].move(0, -mSpeed);

        if (mDown)
            mSnakes[0].move(0, mSpeed);

        CheckCollision();
    }
}

void SFML::Snake::CheckCollision()
{
    for (unsigned int i = 2; i < mSnakes.size(); i++) // Snake's boxes
    {
        if (mSnakes[0].getPosition().x == mSnakes[i].getPosition().x
        && mSnakes[0].getPosition().y == mSnakes[i].getPosition().y)
        {
            mWindow.close();
        }
    }

    if (mSnakes[0].getPosition().x < 0 || mSnakes[0].getPosition().x + mSnakes[0].getSize().x > mWindow.getSize().x // Window collision
    || mSnakes[0].getPosition().y < 0 || mSnakes[0].getPosition().y + mSnakes[0].getSize().y > mWindow.getSize().y)
    {
        mWindow.close();
    }

    if (mSnakes[0].getPosition().x == mFood.getPosition().x // Food collision
    && mSnakes[0].getPosition().y == mFood.getPosition().y)
    {
        
        AddCase();
        FoodGenerator();
    }
}

void SFML::Snake::Update(sf::Event &event) // Check key input
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            if(mSnakes[0].getPosition().x - mSnakes[0].getSize().x != mSnakes[1].getPosition().x) {
                if(!mLeft && !mRight) {
                    mLeft = true;
                    mRight = false;
                    mUp = false;
                    mDown = false;
                }
            }
        }

        if (event.key.code == sf::Keyboard::Right) {
            if(mSnakes[0].getPosition().x + mSnakes[0].getSize().x != mSnakes[1].getPosition().x) {
                if(!mRight && !mLeft) {
                    mLeft = false;
                    mRight = true;
                    mUp = false;
                    mDown = false;
                }
            }
        }

        if (event.key.code == sf::Keyboard::Up) {
            if(mSnakes[0].getPosition().y - mSnakes[0].getSize().x != mSnakes[1].getPosition().y) {
                if(!mUp && !mDown) {
                    mLeft = false;
                    mRight = false;
                    mUp = true;
                    mDown = false;
                }
            }
        }

        if (event.key.code == sf::Keyboard::Down) {
            if(mSnakes[0].getPosition().y + mSnakes[0].getSize().x != mSnakes[1].getPosition().y) {
                if(!mUp && !mDown) {
                    mLeft = false;
                    mRight = false;
                    mUp = false;
                    mDown = true;
                }
            }
        }
    }
}

void SFML::Snake::Draw()
{
    mWindow.draw(mFood);

    for (unsigned int i = 0; i < mSnakes.size(); i++)
        mWindow.draw(mSnakes[i]);
}

int SFML::Snake::getScore()
{
    return _score;
}

int SFML::mainLoop()
{
    sf::RenderWindow window(sf::VideoMode(800, 640), "SFML nibbler");

    Snake snake(window, 32, 32);
    window.setFramerateLimit(45);
    window.setKeyRepeatEnabled(false);

    while (window.isOpen()) {
        snake.Move();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            snake.Update(event);
        }

        window.clear(sf::Color(0,162,255));
        snake.Draw();
        window.display();
    }
    return snake.getScore();
}

