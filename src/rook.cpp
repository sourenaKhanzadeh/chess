#include "../include/rook.hpp"

Rook::Rook(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool isWhite): Piece(position, size, color)
{
    //ctor
    this->isWhite = isWhite;
    if(isWhite)
    {
        setTexturePath("resources/rook_w.png");
    }
    else
    {
        setTexturePath("resources/rook_b.png");
    }
    if(this->texture.loadFromFile(getTexturePath()))
    {
        setSprite(sf::Sprite(this->texture));
    }else{
        std::cerr << "Error loading texture: " << getTexturePath() << std::endl;
    }
}

Rook::~Rook()
{
    //dtor
}

void Rook::draw(sf::RenderWindow& window)
{
    sprite.setPosition(position);
    sprite.setScale(size.x / sprite.getGlobalBounds().width, size.y / sprite.getGlobalBounds().height);
    window.draw(sprite);
}

void Rook::move(sf::Vector2f position)
{
    this->position = position;
}

void Rook::move(sf::Vector2f position, sf::Time deltaTime)
{
    this->position = position;
}

void Rook::setTexture(sf::Texture texture)
{
    this->texture = texture;
}

void Rook::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

sf::Texture Rook::getTexture()
{
    return texture;
}

sf::Sprite Rook::getSprite()
{
    return sprite;
}

void Rook::setTexturePath(std::string texturePath)
{
    this->texturePath = texturePath;
}

std::string Rook::getTexturePath()
{
    return this->texturePath;
}
