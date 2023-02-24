#include "../include/renderer.hpp"

Renderer::Renderer()
{
    window.create(sf::VideoMode(800, 800), "My window");
}

Renderer::~Renderer()
{
    window.close();
    for (GameObject* gameObject : gameObjects)
    {
        delete gameObject;
    }
}

void Renderer::draw(sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Renderer::clear(sf::Color color)
{
    window.clear(color);
}

void Renderer::display()
{
    window.display();
}

bool Renderer::isOpen()
{
    return window.isOpen();
}

void Renderer::close()
{
    window.close();
}

void Renderer::pollEvent(sf::Event& event)
{
    window.pollEvent(event);
}

sf::RenderWindow& Renderer::getWindow()
{
    return window;
}

void Renderer::addGameObject(GameObject* gameObject)
{
    gameObjects.push_back(gameObject);
}

std::vector<GameObject*> Renderer::getGameObjects()
{
    return gameObjects;
}