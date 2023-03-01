#ifndef GAME_HPP
#define GAME_HPP

#define FPS 60
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "renderer.hpp"
#include "gameObject.hpp"

#define TIME_PER_FRAME sf::seconds(1.f/60.f)
class Game
{
public:
    Game();
    ~Game();

    void run();

    void addGameObject(GameObject* gameObject);
    std::vector<GameObject*> getGameObjects();
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    Renderer * renderer;
};
#endif