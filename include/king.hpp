#ifndef KING_HPP
#define KING_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "piece.hpp"

class King : public Piece
{
public:
    King(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool isWhite);
    ~King();
    void move(sf::Vector2f position);
    void move(sf::Vector2f position, sf::Time deltaTime);
    void setTexture(sf::Texture texture);
    void setSprite(sf::Sprite sprite);
    sf::Texture getTexture();
    sf::Sprite getSprite();
    void setTexturePath(std::string texturePath);
    std::string getTexturePath();
    bool isMoveValid(int x1, int y1, int x2, int y2, std::string **board);
private:
};

#endif