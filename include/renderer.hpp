#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>

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

private:
    sf::RenderWindow window;
};

#endif