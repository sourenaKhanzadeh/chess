#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "gameObject.hpp"

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void draw(sf::Drawable& drawable);
    void clear(sf::Color color);
    void display();

    bool isOpen();
    void close();

    void pollEvent(sf::Event& event);
    sf::RenderWindow& getWindow();

    void addGameObject(GameObject* gameObject);
    std::vector<GameObject*> getGameObjects();
    
private:
    sf::RenderWindow window;

protected:
    std::vector<GameObject*> gameObjects;
};

#endif