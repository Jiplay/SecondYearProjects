/*
** EPITECH PROJECT, 2021
** pacman.cpp
** File description:
** pacman.cpp
*/

#include "pacman.hpp"

const int lvl[] =
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };

sf::Vector2f speed(14, 14);


extern "C" Pacman* create_object()
{
    return new Pacman;
}

extern "C" void destroy_object(Pacman* object)
{
    delete object;
}


Pacman::ScoreStruct Pacman::setPoint(ScoreStruct s1, int x, int y)
{
    s1.shape.setRadius(5);
    s1.shape.setFillColor(sf::Color(220, 232, 144));
    s1.x = x;
    s1.y = y;
    s1.shape.setPosition(s1.x*32 + 11, s1.y*32 + 11);
    s1.stat = true;
    return s1;
}

void Pacman::setScore()
{
    if (!font.loadFromFile("police.ttf")) {
        std::raise(84); // use throw
    }
    text.setFont(font);
    text.setString("Score: ");
    text.setCharacterSize(30);
    text.setPosition(0, 340);
    text.setColor(sf::Color::White);
    scorenb.setFont(font);
    score = 0;
    scorenb.setString(std::to_string(score));
    scorenb.setCharacterSize(30);
    scorenb.setPosition(75, 340);
    scorenb.setColor(sf::Color::White);
}

void Pacman::setPhantom()
{
    booPos1.tileX = 1;
    booPos1.tileY = 1;
    sf::CircleShape test(16, 3);
    boo1 = test;
    boo1.setFillColor(sf::Color::Yellow);
    boo1.setPosition(booPos1.tileX*32, booPos1.tileY*32);
    _win.draw(boo1);
    booPos2.tileX = 9;
    booPos2.tileY = 9;
    boo2 = test;
    boo2.setFillColor(sf::Color::Green);
    boo2.setPosition(booPos2.tileX*32, booPos2.tileY*32);
    _win.draw(boo2);
    booPos3.tileX = 1;
    booPos3.tileY = 9;
    boo3 = test;
    boo3.setFillColor(sf::Color::Magenta);
    boo3.setPosition(booPos3.tileX*32, booPos3.tileY*32);
    _win.draw(boo3);
    booPos4.tileX = 9;
    booPos4.tileY = 1;
    boo4 = test;
    boo4.setFillColor(sf::Color::Red);
    boo4.setPosition(booPos4.tileX*32, booPos4.tileY*32);
    _win.draw(boo3);
}

void Pacman::setGame()
{
    _win.create(sf::VideoMode(352, 375), "Pacman :)");
    if (!map.load("tileset.png", sf::Vector2u(32, 32), lvl, 11, 11))
        return;
    _win.setFramerateLimit(60);
    circle.setRadius(15);
    circle.setFillColor(sf::Color::Yellow);
    p.tileX = 5;
    p.tileY = 5;
    circle.setPosition(p.tileX, p.tileY);
    _win.draw(circle);
    t1 = sf::seconds(0.3f);
    setScore();
    setPhantom();
}

bool Pacman::get_colision(int x, int y)
{
    if (x == 0 || y == 0 || x == 10 || y == 10)
        return false;
    int test = 0;
    test = x + (y*11);
    if (lvl[test] == 1)
        return false;
    else
        return true;
}

Pacman::ScoreStruct Pacman::updateScore(ScoreStruct s1)
{
    if (p.tileX == s1.x && p.tileY == s1.y && s1.stat) {
        score = score + 1;
        s1.stat = false;
        scorenb.setString(std::to_string(score));
    }
    return s1;
}

int Pacman::move()
{
    int nextX = 0;
    int nextY = 0;
    //sf::sleep(t1);
    if (event.key.code == sf::Keyboard::Z) {
            nextX = p.tileX;
            nextY = p.tileY - 1;
        if (get_colision(nextX, nextY)) {
            p.tileY = nextY;
            p.tileX = nextX;
        }
    }
    if (event.key.code == sf::Keyboard::Q) {
            nextX = p.tileX - 1;
            nextY = p.tileY;
        if (get_colision(nextX, nextY)) {
            p.tileY = nextY;
            p.tileX = nextX;
        }
    }
    if (event.key.code == sf::Keyboard::S) {
            nextX = p.tileX;
            nextY = p.tileY + 1;
        if (get_colision(nextX, nextY)) {
            p.tileY = nextY;
            p.tileX = nextX;
        }
    }
    if (event.key.code == sf::Keyboard::D) {
            nextY = p.tileY;
            nextX = p.tileX + 1;
        if (get_colision(nextX, nextY)) {
            p.tileY = nextY;
            p.tileX = nextX;
        }
    }
    if (event.key.code == sf::Keyboard::H) {
            return 84;
        }
}

void Pacman::gameLoop()
{
    ScoreStruct s1;
    ScoreStruct s2;
    s1 = setPoint(s1, 4, 5);
    s2 = setPoint(s2, 3, 5);
    sf::Clock clock;

    while (_win.isOpen())
    {
    ///////
        sf::Time dt = clock.restart();
       // std::cout << boo1.getPosition().x/32 << std::endl;
        if (boo1.getPosition().x/32 <= 1) {
            //boo1.move(1 * speed.y * dt.asSeconds(), 0);
            booPos1.tileX += 1;
            // std::cout << "OUI" << std::endl;
        }
        if (boo1.getPosition().x/32 >= 5) {
            booPos1.tileX += 1;
            // std::cout << "NON" << std::endl;
            //boo1.move(-1 * speed.y * dt.asSeconds(), 0);
        }
    ///////
        while (_win.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                int a = move();
                if (a == 84) {
                    exit_status = 2;
                    _win.close();
                    break;
                }
                //move a la main
                s1 = updateScore(s1);
                s2 = updateScore(s2);
            }
            if (event.type == sf::Event::Closed)
                _win.close();
        }
        circle.setPosition(p.tileX * 32, p.tileY * 32);
        boo1.setPosition(booPos1.tileX * 32, booPos1.tileY * 32);
        _win.clear();
        _win.draw(map);
        if (s1.stat)
            _win.draw(s1.shape);
        if (s2.stat)
            _win.draw(s2.shape);
        _win.draw(circle);
        _win.draw(text);
        _win.draw(boo1);
        _win.draw(boo2);
        _win.draw(boo3);
        _win.draw(boo4);
        _win.draw(scorenb);
        _win.display();
    }
}

int Pacman::hit()
{

}

void Pacman::endGame()
{

}

Pacman::Pacman()
{
    exit_status = 0;
}

int Pacman::game(bool t)
{
    setGame();
    gameLoop();
    return exit_status;
}