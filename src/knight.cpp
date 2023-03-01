#include "../include/knight.hpp"

Knight::Knight(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool isWhite): Piece(position, size, color)
{
    this->isWhite = isWhite;
    if(isWhite)
    {
        setTexturePath("resources/knight_w.png");
    }
    else
    {
        setTexturePath("resources/knight_b.png");
    }
    if(this->texture.loadFromFile(getTexturePath()))
    {
        setSprite(sf::Sprite(this->texture));
    }else{
        std::cerr << "Error loading texture: " << getTexturePath() << std::endl;
    }
}

Knight::~Knight()
{
    //dtor
}

void Knight::draw(sf::RenderWindow& window)
{
    sprite.setPosition(position);
    sprite.setScale(size.x / sprite.getGlobalBounds().width, size.y / sprite.getGlobalBounds().height);
    window.draw(sprite);
}

void Knight::move(sf::Vector2f position)
{
    this->position = position;
}

void Knight::move(sf::Vector2f position, sf::Time deltaTime)
{
    this->position = position;
}

void Knight::setTexture(sf::Texture texture)
{
    this->texture = texture;
}

void Knight::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

sf::Texture Knight::getTexture()
{
    return texture;
}

sf::Sprite Knight::getSprite()
{
    return sprite;
}

void Knight::setTexturePath(std::string texturePath)
{
    this->texturePath = texturePath;
}

std::string Knight::getTexturePath()
{
    return texturePath;
}