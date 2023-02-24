#ifndef BOARD_OBJECT_HPP
#define BOARD_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <ostream>
#include "gameObject.hpp"

class BoardObject : public GameObject
{
public:
    BoardObject(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~BoardObject();
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void setPosition(sf::Vector2f position) = 0;
    virtual void setSize(sf::Vector2f size) = 0;
    virtual void setColor(sf::Color color) = 0;
    virtual sf::Vector2f getPosition() = 0;
    virtual sf::Vector2f getSize() = 0;
    virtual sf::Color getColor() = 0;
private:
protected:
    sf::RectangleShape shape;
    sf::Vector2f size;
};


#endif 