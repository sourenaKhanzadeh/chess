#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject
{
public:
    GameObject();
    virtual ~GameObject() = default;

    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void mousePressed(sf::Event event) = 0;
    virtual void mouseReleased(sf::Event event) = 0;

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

    friend std::ostream& operator<<(std::ostream& os, const GameObject& obj)
    {
        os << "Position: " << obj.position.x << ", " << obj.position.y << std::endl;
        os << "Color: " << obj.color.r << ", " << obj.color.g << ", " << obj.color.b << ", " << obj.color.a << std::endl;
        return os;
    }
private:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float mass;
    float radius;
protected:
    sf::Vector2f position;
    sf::Color color;

};


#endif