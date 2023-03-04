#include "../include/bishop.hpp"

Bishop::Bishop(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool isWhite): Piece(position, size, color)
{
    this->isWhite = isWhite;
    if(isWhite)
    {
        setTexturePath("resources/bishop_w.png");
    }
    else
    {
        setTexturePath("resources/bishop_b.png");
    }
    if(this->texture.loadFromFile(getTexturePath()))
    {
        setSprite(sf::Sprite(this->texture));
    }else{
        std::cerr << "Error loading texture: " << getTexturePath() << std::endl;
    }
}

Bishop::~Bishop()
{
    //dtor
}

void Bishop::move(sf::Vector2f position)
{
    // this->position = position;
}

void Bishop::move(sf::Vector2f position, sf::Time deltaTime)
{
    // this->position = position;
}

void Bishop::setTexture(sf::Texture texture)
{
    this->texture = texture;
}

void Bishop::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

sf::Texture Bishop::getTexture()
{
    return texture;
}

sf::Sprite Bishop::getSprite()
{
    return sprite;
}

void Bishop::setTexturePath(std::string texturePath)
{
    this->texturePath = texturePath;
}

std::string Bishop::getTexturePath()
{
    return texturePath;
}


bool Bishop::isMoveValid(int x1, int y1, int x2, int y2, std::string **board){
    return true;
}