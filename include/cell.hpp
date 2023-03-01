#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "boardObject.hpp"
#include "piece.hpp"

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
    void mousePressed(sf::Event event, sf::RenderWindow& window);
    void mouseReleased(sf::Event event, sf::RenderWindow& window);
    bool isMouseInside(sf::Vector2f mousePosition);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::Color getColor();
private:
protected:
};

#endif