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
    possibleMoves.clear();
    sf::Vector2f pos = this->position;
    // round position to nearest 100
    pos.x = round(this->position.x / 100) * 100;
    pos.y = round(this->position.y / 100) * 100;
    // get current possible moves
    for (Piece* piece : pieces)
    {
        if(piece->getWhite() != this->isWhite)
        {
            if (piece->getPosition() == pos){
                // add attack moves for pawn
                if(isMoveDirectionUp)
                {
                    if (piece->getPosition().x == this->prevPos.x - 100 || piece->getPosition().x == this->prevPos.x + 100)
                    possibleMoves.push_back(piece->getPosition());
                }
                else
                {
                    if (piece->getPosition().x == this->prevPos.x - 100 || piece->getPosition().x == this->prevPos.x + 100)
                    possibleMoves.push_back(piece->getPosition());
                }
            }
        }
        // add normal moves for pawn
        if(isMoveDirectionUp)
        {
            if (piece->getPosition() != sf::Vector2f(pos.x, pos.y - 100))
            {
                possibleMoves.push_back(sf::Vector2f(this->prevPos.x, this->prevPos.y - 100));
            }
            if (piece->getPosition() != sf::Vector2f(pos.x, pos.y - 200))
            {
                possibleMoves.push_back(sf::Vector2f(this->prevPos.x, this->prevPos.y - 200));
            }
        }
        else
        {
            if (piece->getPosition() != sf::Vector2f(pos.x, pos.y + 100))
            {
                possibleMoves.push_back(sf::Vector2f(this->prevPos.x, this->prevPos.y + 100));
            }
            if (piece->getPosition() != sf::Vector2f(pos.x, pos.y + 200))
            {
                possibleMoves.push_back(sf::Vector2f(this->prevPos.x, this->prevPos.y + 200));
            }
        }
    }
    std::cout << "prevPos: " << this->prevPos.x << " " << this->prevPos.y << std::endl;
    for(int i = 0; i < possibleMoves.size(); i++)
    {
        std::cout << "Possible move: " << possibleMoves[i].x << " " << possibleMoves[i].y << std::endl;
        std::cout << "Position: " << position.x << " " << position.y << std::endl;   
        // check if size and position match
        if(possibleMoves[i] == position)
        {
            this->position = position;
            this->prevPos = this->position;
            return;
        }
    }
    this->position = this->prevPos;

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
