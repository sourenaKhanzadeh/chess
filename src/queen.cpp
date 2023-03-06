#include "../include/queen.hpp"

Queen::Queen(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool isWhite): Piece(position, size, color)
{
    type = "Queen";
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
    // this->position = position;
}

void Queen::move(sf::Vector2f position, sf::Time deltaTime)
{
    // this->position = position;
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


bool Queen::isMoveValid(int x1, int y1, int x2, int y2, std::string **board){
    if(x1 == x2 && y1 == y2)
        return false;

    //if same color piece is in the way
    if(board[y2][x2] != "  "){
        if(isWhite){
            if(board[y2][x2][1] == 'W')
                return false;
        }else{
            if(board[y2][x2][1] == 'B')
                return false;
        }
    }
    if(x1 == x2){
        if(y1 < y2){
            for(int i = y1 + 1; i < y2; i++){
                if(board[i][x1] != "  ")
                    return false;
            }
        }else{
            for(int i = y1 - 1; i > y2; i--){
                if(board[i][x1] != "  ")
                    return false;
            }
        }
        return true;
    }
    if(y1 == y2){
        if(x1 < x2){
            for(int i = x1 + 1; i < x2; i++){
                if(board[y1][i] != "  ")
                    return false;
            }
        }else{
            for(int i = x1 - 1; i > x2; i--){
                if(board[y1][i] != "  ")
                    return false;
            }
        }
        return true;
    }
    if(abs(x1 - x2) == abs(y1 - y2)){
        if(x1 < x2 && y1 < y2){
            for(int i = 1; i < abs(x1 - x2); i++){
                if(board[y1 + i][x1 + i] != "  ")
                    return false;
            }
        }else if(x1 > x2 && y1 > y2){
            for(int i = 1; i < abs(x1 - x2); i++){
                if(board[y1 - i][x1 - i] != "  ")
                    return false;
            }
        }else if(x1 < x2 && y1 > y2){
            for(int i = 1; i < abs(x1 - x2); i++){
                if(board[y1 - i][x1 + i] != "  ")
                    return false;
            }
        }else if(x1 > x2 && y1 < y2){
            for(int i = 1; i < abs(x1 - x2); i++){
                if(board[y1 + i][x1 - i] != "  ")
                    return false;
            }
        }
        return true;
    }
    return false;
}