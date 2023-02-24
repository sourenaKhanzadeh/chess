#include "../include/boardObject.hpp"

BoardObject::BoardObject(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    this->position = position;
    this->size = size;
    this->color = color;
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
}

BoardObject::~BoardObject()
{
}

void BoardObject::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void BoardObject::update(sf::Time deltaTime)
{
}

