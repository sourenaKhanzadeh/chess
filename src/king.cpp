#include "../include/king.hpp"

King::King(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool isWhite): Piece(position, size, color)
{
    this->isWhite = isWhite;
    if(isWhite)
    {
        setTexturePath("resources/king_w.png");
    }
    else
    {
        setTexturePath("resources/king_b.png");
    }
    if(this->texture.loadFromFile(getTexturePath()))
    {
        setSprite(sf::Sprite(this->texture));
    }else{
        std::cerr << "Error loading texture: " << getTexturePath() << std::endl;
    }
}

King::~King()
{
    //dtor
}

void King::draw(sf::RenderWindow& window)
{
    sprite.setPosition(position);
    sprite.setScale(size.x / sprite.getGlobalBounds().width, size.y / sprite.getGlobalBounds().height);
    window.draw(sprite);
}

void King::move(sf::Vector2f position)
{
    this->position = position;
}

void King::move(sf::Vector2f position, sf::Time deltaTime)
{
    this->position = position;
}

void King::setTexture(sf::Texture texture)
{
    this->texture = texture;
}

void King::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

sf::Texture King::getTexture()
{
    return texture;
}

sf::Sprite King::getSprite()
{
    return sprite;
}

void King::setTexturePath(std::string texturePath)
{
    this->texturePath = texturePath;
}

std::string King::getTexturePath()
{
    return texturePath;
}
