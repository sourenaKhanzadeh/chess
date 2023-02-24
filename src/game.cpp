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
            renderer->getWindow().close();
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
    renderer->display();

    for(GameObject* gameObject : renderer->getGameObjects())
    {
        gameObject->draw(renderer->getWindow());
    }
}

