#include "../include/cell.hpp"

Cell::Cell(sf::Vector2f position, sf::Vector2f size, sf::Color color): BoardObject(position, size, color)
{
}

Cell::~Cell()
{
    delete piece;
}

void Cell::setPosition(sf::Vector2f position)
{
    this->position = position;
    shape.setPosition(position);
}

void Cell::setSize(sf::Vector2f size)
{
    this->size = size;
    shape.setSize(size);
}

void Cell::setColor(sf::Color color)
{
    this->color = color;
    shape.setFillColor(color);
}

sf::Vector2f Cell::getPosition()
{
    return position;
}

sf::Vector2f Cell::getSize()
{
    return size;
}


sf::Color Cell::getColor()
{
    return color;
}

void Cell::draw(sf::RenderWindow& window)
{
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
    window.draw(shape);
    if (piece != nullptr)
    piece->draw(window);
}

void Cell::update(sf::Time deltaTime)
{
}

void Cell::setPiece(Piece* piece)
{
    this->piece = piece;
}

Piece* Cell::getPiece()
{
    return piece;
}


