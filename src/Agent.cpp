//
// Created by sourena khanzadeh on 2023-03-06.
//

#include "../include/Agent.hpp"

MoveGeneration::MoveGeneration() = default;

MoveGeneration::~MoveGeneration() = default;

std::vector<std::string> MoveGeneration::generateMoves(std::string **board, Piece *piece, bool check, bool stalemate) {
    if(piece->getType() == "Pawn"){
        return pawnMoves(board, piece);
    }
    else if(piece->getType() == "Rook"){
        return rookMoves(board, piece);
    }
    else if(piece->getType() == "Knight"){
        return knightMoves(board, piece);
    }
    else if(piece->getType() == "Bishop"){
        return bishopMoves(board, piece);
    }
    else if(piece->getType() == "Queen"){
        return queenMoves(board, piece);
    }
    else if(piece->getType() == "King"){
        return kingMoves(board, piece);
    }
    else{
        std::cout << "Error: Invalid piece type" << std::endl;
        return {};
    }
}

std::vector<std::string> MoveGeneration::pawnMoves(std::string **board, Piece *piece) {
    std::vector<std::string> moves;
    int x = piece->getPosition().x / 100;
    int y = piece->getPosition().y / 100;
    if(piece->getWhite() && piece->getMoveDirectionUp()){
        if(board[x][y-1] == "  "){
            moves.push_back(std::to_string(x) + std::to_string(y-1));
            if(board[x][y-2] == "  " && piece->firstMove){
                moves.push_back(std::to_string(x) + std::to_string(y-2));
            }
        }
        if(x-1 >= 0 && board[x-1][y-1] != "  " && !piece->getWhite()){
            moves.push_back(std::to_string(x-1) + std::to_string(y-1));
        }
        if(x+1 <= 7 && board[x+1][y-1] != "  " && !piece->getWhite()){
            moves.push_back(std::to_string(x+1) + std::to_string(y-1));
        }
    }
    else if(piece->getWhite() && !piece->getMoveDirectionUp()){
        if(board[x][y+1] == "  "){
            moves.push_back(std::to_string(x) + ", " + std::to_string(y+1));
            if(board[x][y+2] == "  " && piece->firstMove){
                moves.push_back(std::to_string(x) + ", " + std::to_string(y+2));
            }
        }
        if(x-1 >= 0 && board[x-1][y+1] != "  " && !piece->getWhite()){
            moves.push_back(std::to_string(x-1) + ", " + std::to_string(y+1));
        }
        if(x+1 <= 7 && board[x+1][y+1] != "  " && !piece->getWhite()){
            moves.push_back(std::to_string(x+1) + ", " + std::to_string(y+1));
        }
    }
    else if(!piece->getWhite() && piece->getMoveDirectionUp()){
        if(board[x][y-1] == "  "){
            moves.push_back(std::to_string(x) + ", " + std::to_string(y-1));
            if(board[x][y-2] == "  " && piece->firstMove){
                moves.push_back(std::to_string(x) + ", " + std::to_string(y-2));
            }
        }
        if(x-1 >= 0 && board[x-1][y-1] != "  " && piece->getWhite()){
            moves.push_back(std::to_string(x-1) + ", " + std::to_string(y-1));
        }
        if(x+1 <= 7 && board[x+1][y-1] != "  " && piece->getWhite()){
            moves.push_back(std::to_string(x+1) + ", " + std::to_string(y-1));
        }
    }
    else if(!piece->getWhite() && !piece->getMoveDirectionUp()){
        if(board[x][y+1] == "  "){
            moves.push_back(std::to_string(x) + ", " + std::to_string(y+1));
            if(board[x][y+2] == "  " && piece->firstMove){
                moves.push_back(std::to_string(x) + ", " + std::to_string(y+2));
            }
        }
        if(x-1 >= 0 && board[x-1][y+1] != "  " && piece->getWhite()){
            moves.push_back(std::to_string(x-1) + ", " + std::to_string(y+1));
        }
        if(x+1 <= 7 && board[x+1][y+1] != "  " && piece->getWhite()){
            moves.push_back(std::to_string(x+1) + ", " + std::to_string(y+1));
        }
    }
    return moves;
}

std::vector<std::string> MoveGeneration::rookMoves(std::string **board, Piece *piece) {
    std::vector<std::string> moves;
    // make move for rook

    return moves;
}

std::vector<std::string> MoveGeneration::knightMoves(std::string **board, Piece *piece) {
    std::vector<std::string> moves;
    return moves;
}

std::vector<std::string> MoveGeneration::bishopMoves(std::string **board, Piece *piece) {
    std::vector<std::string> moves;
    return moves;
}

std::vector<std::string> MoveGeneration::queenMoves(std::string **board, Piece *piece) {
    std::vector<std::string> moves;
    return moves;
}

std::vector<std::string> MoveGeneration::kingMoves(std::string **board, Piece *piece) {
    std::vector<std::string> moves;
    return moves;
}

