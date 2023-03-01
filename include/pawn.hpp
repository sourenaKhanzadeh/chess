#ifndef PAWN_HPP
#define PAWN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "piece.hpp"

class Pawn : public Piece
{
public:
    Pawn(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool isWhite);
    ~Pawn();
    void move(sf::Vector2f position);
    void move(sf::Vector2f position, sf::Time deltaTime);
    void setTexture(sf::Texture texture);
    void setSprite(sf::Sprite sprite);
    sf::Texture getTexture();
    sf::Sprite getSprite();
    void setTexturePath(std::string texturePath);
    std::string getTexturePath();
private:
    
};

#endif