#ifndef PIECE_HPP
#define PIECE_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <math.h>
#include "boardObject.hpp"
#include "cell.hpp"


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
    void mousePressed(sf::Event event, sf::RenderWindow& window);
    void mouseReleased(sf::Event event, sf::RenderWindow& window);
    bool isMouseInside(sf::Vector2f mousePosition);
    void setDragging(bool dragging);
    void setPrevPos(sf::Vector2f prevPos);
    sf::Vector2f getPrevPos(){return prevPos;}

    virtual void move(sf::Vector2f position) = 0;
    virtual void move(sf::Vector2f position, sf::Time deltaTime) = 0;
    virtual void setTexture(sf::Texture texture) = 0;
    virtual void setSprite(sf::Sprite sprite) = 0;
    virtual sf::Texture getTexture() = 0;
    virtual sf::Sprite getSprite() = 0;
    virtual void setTexturePath(std::string texturePath) = 0;
    virtual std::string getTexturePath() = 0;
    virtual bool isMoveValid(int x1, int y1, int x2, int y2, std::string **board) = 0;

    void setPieces(std::vector<Piece*> pieces){this->pieces = pieces;}
    void setWhite(bool isWhite){this->isWhite = isWhite;}
    void setMoveDirectionUp(bool isMoveDirectionUp){this->isMoveDirectionUp = isMoveDirectionUp;}
    bool getWhite(){return isWhite;}
    void setDestroyed(bool isDestroyed){this->isDestroyed = isDestroyed;}
    bool getDestroyed(){return isDestroyed;}
private:
    bool isDestroyed = false;
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string texturePath;
    bool isWhite;
    bool dragging = false;
    sf::Vector2f prevPos;
    std::vector<sf::Vector2f> possibleMoves;
    bool isMoveDirectionUp;
    std::vector<Piece*> pieces;
};

#endif
