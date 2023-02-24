#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include "boardObject.hpp"

class Cell : public BoardObject
{
public:
    Cell(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~Cell();
    void draw(sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setColor(sf::Color color);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::Color getColor();
private:
};

#endif