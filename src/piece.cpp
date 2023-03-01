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
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
    window.draw(shape);
}

void Piece::update(sf::Time deltaTime)
{
}


void Piece::mousePressed(sf::Event event)
{
}

void Piece::mouseReleased(sf::Event event)
{
}