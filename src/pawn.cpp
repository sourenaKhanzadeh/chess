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
    // possibleMoves.clear();
    // sf::Vector2f pos = this->position;
    // // round position to nearest 100
    // pos.x = round(this->position.x / 100) * 100;
    // pos.y = round(this->position.y / 100) * 100;
    // // add normal moves for pawn
    // if(isMoveDirectionUp)
    // {
    //     possibleMoves.push_back(sf::Vector2f(this->prevPos.x, this->prevPos.y - 100));
    //     possibleMoves.push_back(sf::Vector2f(this->prevPos.x, this->prevPos.y - 200));
    // }
    // else
    // {
    //     possibleMoves.push_back(sf::Vector2f(this->prevPos.x, this->prevPos.y + 100));
    //     possibleMoves.push_back(sf::Vector2f(this->prevPos.x, this->prevPos.y + 200));
    // }
    // for(Piece* piece : pieces){
    //     // check if piece other than self is colliding with pawn
    //     if(piece != this){
    //         // find out if piece is colliding with pawn in the possible moves
    //         for(int i = 0; i < possibleMoves.size(); i++)
    //         {
    //             if(piece->getPosition() == possibleMoves[i])
    //             {
    //                 // remove move from possible moves
    //                 possibleMoves.erase(possibleMoves.begin() + i);
    //             }
    //         }
    //     }
    // }
    // // get current possible moves
    // for (Piece* piece : pieces)
    // {
    //     if(piece->getWhite() != this->isWhite)
    //     {
    //         if (piece->getPosition() == pos){
    //             // add attack moves for pawn
    //             if(isMoveDirectionUp)
    //             {
    //                 if (piece->getPosition().x == this->prevPos.x - 100 || piece->getPosition().x == this->prevPos.x + 100)
    //                 possibleMoves.push_back(piece->getPosition());
    //             }
    //             else
    //             {
    //                 if (piece->getPosition().x == this->prevPos.x - 100 || piece->getPosition().x == this->prevPos.x + 100)
    //                 possibleMoves.push_back(piece->getPosition());
    //             }
    //         }
    //     }
    // }
    // for(int i = 0; i < possibleMoves.size(); i++)
    // {
    //     // check if size and position match
    //     if(possibleMoves[i] == position)
    //     {
    //         this->position = position;
    //         this->prevPos = this->position;
    //         for (Piece *piece : pieces)
    //         {
    //             if (piece->getPosition() == position)
    //             {
    //                 if (piece->getWhite() != this->isWhite)
    //                 {
    //                     // remove piece from pieces
    //                     pieces.erase(std::remove(pieces.begin(), pieces.end(), piece), pieces.end());
    //                     piece->setDestroyed(true);
    //                 }
    //             }
    //         }
    //         return;
    //     }
    // }
    // this->position = this->prevPos;

}

void Pawn::move(sf::Vector2f position, sf::Time deltaTime)
{
    // this->position = position;
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


bool Pawn::isMoveValid(int x1, int y1, int x2, int y2, std::string **board){
    std::cout << "Board: " << board[y2][x2] << std::endl;
    if(isMoveDirectionUp){
        if(y1 == 6){
            if(y2 == 4 && x1 == x2){
                if(board[y2][x2] == ""){
                    return true;
                }
            }
        }
        if(y2 == y1 - 1 && x1 == x2){
            if(board[y2][x2] == ""){
                return true;
            }
        }
        if(y2 == y1 - 1 && (x2 == x1 + 1 || x2 == x1 - 1)){
            if(board[y2][x2] != ""){
                return true;
            }
        }
    }
    else{
        if(y1 == 1){
            if(y2 == 3 && x1 == x2){
                if(board[y2][x2] == ""){
                    return true;
                }
            }
        }
        if(y2 == y1 + 1 && x1 == x2){
            if(board[y2][x2] == ""){
                return true;
            }
        }
        if(y2 == y1 + 1 && (x2 == x1 + 1 || x2 == x1 - 1)){
            if(board[y2][x2] != ""){
                return true;
            }
        }
    }
    return false;
}