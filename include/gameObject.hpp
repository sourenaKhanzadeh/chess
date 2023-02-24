#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject
{
public:
    GameObject();
    ~GameObject();

    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);

    sf::Vector2f getVelocity();
    void setVelocity(sf::Vector2f velocity);

    sf::Vector2f getAcceleration();
    void setAcceleration(sf::Vector2f acceleration);

    float getMass();
    void setMass(float mass);

    float getRadius();
    void setRadius(float radius);

    sf::Color getColor();
    void setColor(sf::Color color);

private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float mass;
    float radius;
    sf::Color color;
};


#endif