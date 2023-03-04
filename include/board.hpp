#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "boardObject.hpp"
#include "piece.hpp"
#include "cell.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"

class Board : public BoardObject
{
public:
    Board(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool playAsWhite);
    ~Board();
    void draw(sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    void mousePressed(sf::Event event, sf::RenderWindow& window);
    void mouseReleased(sf::Event event, sf::RenderWindow &window);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setColor(sf::Color color);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::Color getColor();
    std::vector<Cell*> getCells();
    friend std::ostream& operator<<(std::ostream& os, const Board& board){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                os << board.board[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
private:
    bool playAsWhite;
    bool moving = false;
    void movePiece(int x, int y, int x2, int y2);
    void renderBoard();
    sf::Vector2f currentChosenPiecePosition;
protected:
    std::vector<Cell*> cells;
    std::vector<Piece*> pieces;
    std::string **board = new std::string*[8]{
        new std::string[8]{"RW", "NW", "BW", "QW", "KW", "BW", "NW", "RW"},
        new std::string[8]{"PW", "PW", "PW", "PW", "PW", "PW", "PW", "PW"},
        new std::string[8]{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        new std::string[8]{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        new std::string[8]{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        new std::string[8]{"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        new std::string[8]{"PB", "PB", "PB", "PB", "PB", "PB", "PB", "PB"},
        new std::string[8]{"RB", "NB", "BB", "QB", "KB", "BB", "NB", "RB"}
    };
};


#endif