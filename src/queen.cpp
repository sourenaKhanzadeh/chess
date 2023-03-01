#include "../include/queen.hpp"

Queen::Queen(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool isWhite): Piece(position, size, color)
{
    this->isWhite = isWhite;
    if(isWhite)
    {
        setTexturePath("resources/queen_w.png");
    }
    else
    {
        setTexturePath("resources/queen_b.png");
    }
    if(this->texture.loadFromFile(getTexturePath()))
    {
        setSprite(sf::Sprite(this->texture));
    }else{
        std::cerr << "Error loading texture: " << getTexturePath() << std::endl;
    }
}

Queen::~Queen()
{
    //dtor
}


void Queen::move(sf::Vector2f position)
{
    this->position = position;
}

void Queen::move(sf::Vector2f position, sf::Time deltaTime)
{
    this->position = position;
}

void Queen::setTexture(sf::Texture texture)
{
    this->texture = texture;
}

void Queen::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

sf::Texture Queen::getTexture()
{
    return texture;
}

sf::Sprite Queen::getSprite()
{
    return sprite;
}

void Queen::setTexturePath(std::string texturePath)
{
    this->texturePath = texturePath;
}

std::string Queen::getTexturePath()
{
    return texturePath;
}
