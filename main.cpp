#include "include/game.hpp"
#include "include/board.hpp"
#include <iostream>

int main()
{
    Game game;
    game.addGameObject(new Board(sf::Vector2f(0, 0), sf::Vector2f(800, 800), sf::Color::Red));
    game.run();


    return 0;
}