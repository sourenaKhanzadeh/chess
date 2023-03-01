#include "../include/cell.hpp"

Cell::Cell(sf::Vector2f position, sf::Vector2f size, sf::Color color): BoardObject(position, size, color)
{
}

Cell::~Cell()
{
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
}

void Cell::update(sf::Time deltaTime)
{
}


void Cell::mousePressed(sf::Event event, sf::RenderWindow& window)
{
}

void Cell::mouseReleased(sf::Event event, sf::RenderWindow& window)
{
}

bool Cell::isMouseInside(sf::Vector2f mousePosition)
{
    if (mousePosition.x > position.x && mousePosition.x < position.x + size.x && mousePosition.y > position.y && mousePosition.y < position.y + size.y)
    {
        return true;
    }
    return false;
}