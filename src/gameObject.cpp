#include "../include/gameObject.hpp"


GameObject::GameObject()
{
    //ctor
}


sf::Vector2f GameObject::getPosition()
{
    return position;
}

void GameObject::setPosition(sf::Vector2f position)
{
    this->position = position;
}

sf::Vector2f GameObject::getVelocity()
{
    return velocity;
}

void GameObject::setVelocity(sf::Vector2f velocity)
{
    this->velocity = velocity;
}

sf::Vector2f GameObject::getAcceleration()
{
    return acceleration;
}

void GameObject::setAcceleration(sf::Vector2f acceleration)
{
    this->acceleration = acceleration;
}

float GameObject::getMass()
{
    return mass;
}

void GameObject::setMass(float mass)
{
    this->mass = mass;
}

float GameObject::getRadius()
{
    return radius;
}

void GameObject::setRadius(float radius)
{
    this->radius = radius;
}

sf::Color GameObject::getColor()
{
    return color;
}

void GameObject::setColor(sf::Color color)
{
    this->color = color;
}
