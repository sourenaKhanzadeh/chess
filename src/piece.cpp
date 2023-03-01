#include "../include/piece.hpp"

Piece::Piece(sf::Vector2f position, sf::Vector2f size, sf::Color color): BoardObject(position, size, color)
{
    //ctor
}


void Piece::setPosition(sf::Vector2f position)
{
    this->position = position;
    shape.setPosition(position);
}

void Piece::setSize(sf::Vector2f size)
{
    this->size = size;
    shape.setSize(size);
}

void Piece::setColor(sf::Color color)
{
    this->color = color;
    shape.setFillColor(color);
}

sf::Vector2f Piece::getPosition()
{
    return position;
}

sf::Vector2f Piece::getSize()
{
    return size;
}

sf::Color Piece::getColor()
{
    return color;
}

void Piece::draw(sf::RenderWindow& window)
{
    // shape.setPosition(position);
    // shape.setSize(size);
    // shape.setFillColor(color);
    // window.draw(shape);
    sprite.setPosition(position);
    sprite.setScale(size.x / sprite.getTexture()->getSize().x, size.y / sprite.getTexture()->getSize().y);
    window.draw(sprite);
}

void Piece::update(sf::Time deltaTime)
{

}


void Piece::mousePressed(sf::Event event, sf::RenderWindow& window)
{
    // move the piece to the mouse position if dragging is true
    if (dragging)
    {
        // change relative to window
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        position = sf::Vector2f(mousePosition.x - size.x / 2, mousePosition.y - size.y / 2);
    }
}

void Piece::mouseReleased(sf::Event event, sf::RenderWindow& window)
{
}

bool Piece::isMouseInside(sf::Vector2f mousePosition)
{
    if (mousePosition.x > position.x && mousePosition.x < position.x + size.x)
    {
        if (mousePosition.y > position.y && mousePosition.y < position.y + size.y)
        {
            return true;
        }
    }
    return false;
}

void Piece::setDragging(bool dragging)
{
    this->dragging = dragging;
}

void Piece::setPrevPos(sf::Vector2f prevPosition)
{
    this->prevPos = prevPosition;
}