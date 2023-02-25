#ifndef PIECE_HPP
#define PIECE_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "boardObject.hpp"

class Piece : public BoardObject
{
public:
    Piece(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    virtual ~Piece() = default;
    void draw(sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setColor(sf::Color color);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::Color getColor();

    virtual void move(sf::Vector2f position) = 0;
    virtual void move(sf::Vector2f position, sf::Time deltaTime) = 0;
    virtual void setTexture(sf::Texture texture) = 0;
    virtual void setSprite(sf::Sprite sprite) = 0;
    virtual sf::Texture getTexture() = 0;
    virtual sf::Sprite getSprite() = 0;
    virtual void setTexturePath(std::string texturePath) = 0;
    virtual std::string getTexturePath() = 0;
private:
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string texturePath;
    bool isWhite;
};

#endif