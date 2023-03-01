#include "../include/game.hpp"

Game::Game()
{
    renderer = new Renderer();
}

Game::~Game()
{
    delete renderer;
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (renderer->getWindow().isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (renderer->getWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            renderer->close();
        }else if (event.type == sf::Event::MouseButtonPressed)
        {
            for (GameObject* gameObject : renderer->getGameObjects())
            {
                gameObject->mousePressed(event, renderer->getWindow());
            }
        }else if (event.type == sf::Event::MouseButtonReleased)
        {
            for (GameObject* gameObject : renderer->getGameObjects())
            {
                gameObject->mouseReleased(event, renderer->getWindow());
            }
        }else if (event.type == sf::Event::MouseMoved)
        {
            for (GameObject* gameObject : renderer->getGameObjects())
            {
                gameObject->mousePressed(event, renderer->getWindow());
            }
        }
        
    }
}

void Game::update(sf::Time deltaTime)
{
    // Update game logic here
    for (GameObject* gameObject : renderer->getGameObjects())
    {
        gameObject->update(deltaTime);
    }
}

void Game::render()
{
    renderer->clear(sf::Color::White);
    // Draw stuff here
    for(GameObject* gameObject : renderer->getGameObjects())
    {
        gameObject->draw(renderer->getWindow());
    }
    renderer->display();

}

void Game::addGameObject(GameObject* gameObject)
{
    renderer->addGameObject(gameObject);
}

std::vector<GameObject*> Game::getGameObjects()
{
    return renderer->getGameObjects();
}
