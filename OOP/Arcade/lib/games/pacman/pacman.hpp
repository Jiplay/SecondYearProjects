/*
** EPITECH PROJECT, 2021
** pacman.hpp
** File description:
** pacma,.hpp
*/

#ifndef _PACMAN_HPP_
#define _PACMAN_HPP_

#include "../AGames.hpp"
#include <iostream>
#include <csignal>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};


class Pacman : public AGames
{
    public: 
        struct ScoreStruct {
            int x;
            int y;
            bool stat;
            sf::CircleShape shape;
        };
    public:
        Pacman();
        ~Pacman() = default;

        void setGame();
        int hit();
        int move();
        void endGame();
        void gameLoop();
        int game(bool t);
        bool get_colision(int x, int y);
        void setBouffe();
        void setScore();
        void setPhantom();
        ScoreStruct updateScore(ScoreStruct s1);
        ScoreStruct setPoint(ScoreStruct s1, int x, int y);
    
    public:
        struct Pacpac {
            int tileX;
            int tileY;
        };
        struct Phantom {
            int tileX;
            int tileY;
            bool lr;
        };
        int exit_status;
        int score;
        Pacpac p;
        Phantom booPos1;
        Phantom booPos2;
        Phantom booPos3;
        Phantom booPos4;
        sf::RenderWindow _win;
        sf::Event event;
        sf::CircleShape circle;
        sf::CircleShape boo1;
        sf::CircleShape boo2;
        sf::CircleShape boo3;
        sf::CircleShape boo4;
        TileMap map;
        int TileUnderPlayer;
        sf::Time t1;
        sf::CircleShape bouffe;
        sf::Font font;
        sf::Text text;
        sf::Text scorenb;
};

extern "C" Pacman* create_object();
extern "C" void destroy_object(Pacman* object);

#endif /* !_PACMAN_HPP_ */
