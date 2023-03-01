#include "../include/pawn.hpp"

Pawn::Pawn(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool isWhite): Piece(position, size, color)
{
    this->isWhite = isWhite;
    if(isWhite)
    {
        setTexturePath("resources/pawn_w.png");
    }
    else
    {
        setTexturePath("resources/pawn_b.png");
    }
    if(this->texture.loadFromFile(getTexturePath()))
    {
        setSprite(sf::Sprite(this->texture));
    }else{
        std::cerr << "Error loading texture: " << getTexturePath() << std::endl;
    }
}

Pawn::~Pawn()
{
    //dtor
}


void Pawn::move(sf::Vector2f position)
{
    this->position = position;
}

void Pawn::move(sf::Vector2f position, sf::Time deltaTime)
{
    this->position = position;
}

void Pawn::setTexture(sf::Texture texture)
{
    this->texture = texture;
}

void Pawn::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

sf::Texture Pawn::getTexture()
{
    return texture;
}

sf::Sprite Pawn::getSprite()
{
    return sprite;
}

void Pawn::setTexturePath(std::string texturePath)
{
    this->texturePath = texturePath;
}

std::string Pawn::getTexturePath()
{
    return texturePath;
}
