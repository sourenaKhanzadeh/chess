#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "boardObject.hpp"
#include "cell.hpp"
#include "pawn.hpp"
#include "rook.hpp"

class Board : public BoardObject
{
public:
    Board(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool playAsWhite);
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
    bool playAsWhite;
    void setupBoard();
protected:
    std::vector<std::vector<Cell*>> cells;
    std::string **board = new std::string*[8]{
        new std::string[8]{"RW", "KW", "BW", "QW", "KW", "BW", "KW", "RW"},
        new std::string[8]{"PW", "PW", "PW", "PW", "PW", "PW", "PW", "PW"},
        new std::string[8]{"", "", "", "", "", "", "", ""},
        new std::string[8]{"", "", "", "", "", "", "", ""},
        new std::string[8]{"", "", "", "", "", "", "", ""},
        new std::string[8]{"", "", "", "", "", "", "", ""},
        new std::string[8]{"PB", "PB", "PB", "PB", "PB", "PB", "PB", "PB"},
        new std::string[8]{"RB", "KB", "BB", "QB", "KB", "BB", "KB", "RB"}
    };
};


#endif