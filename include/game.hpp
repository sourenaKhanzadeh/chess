#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "renderer.hpp"

#define TIME_PER_FRAME sf::seconds(1.f/60.f)
class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    Renderer * renderer;
};
#endif