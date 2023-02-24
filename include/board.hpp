#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "boardObject.hpp"
#include "cell.hpp"

class Board : public BoardObject
{
public:
    Board(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~Board();
    void draw(sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setColor(sf::Color color);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::Color getColor();
private:
protected:
    std::vector<std::vector<Cell*>> cells;
};


#endif