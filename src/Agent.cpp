//
// Created by sourena khanzadeh on 2023-03-06.
//

#include "../include/Agent.hpp"

MoveGeneration::MoveGeneration() = default;

MoveGeneration::~MoveGeneration() = default;

std::vector<std::pair<int, int>> MoveGeneration::generateMoves(std::string **board, Piece *piece, bool check, bool stalemate) {
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

std::vector<std::pair<int, int>> MoveGeneration::pawnMoves(std::string **board, Piece *piece) {
    std::vector<std::pair<int, int>> moves;
    int x = piece->getPrevPos().x / 100;
    int y = piece->getPrevPos().y / 100;
    if(piece->getWhite() && piece->getMoveDirectionUp()){
        if(board[x][y-1] == "  "){
            moves.emplace_back(x, y-1);
            if(board[x][y-2] == "  " && piece->firstMove){
                moves.emplace_back(x, y-2);
            }
        }
        if(x-1 >= 0 && board[x-1][y-1] != "  " && board[x-1][y-1][1] == 'B'){
            moves.emplace_back(x-1, y-1);
        }
        if(x+1 <= 7 && board[x+1][y-1] != "  " && board[x+1][y-1][1] == 'B'){
            moves.emplace_back(x+1, y-1);
        }
    }
    else if(piece->getWhite() && !piece->getMoveDirectionUp()){
        if(board[x][y+1] == "  "){
            moves.emplace_back(x, y+1);
            if(board[x][y+2] == "  " && piece->firstMove){
                moves.emplace_back(x, y+2);
            }
        }
        if(x-1 >= 0 && board[x-1][y+1] != "  " && board[x-1][y+1][1] == 'B'){
            moves.emplace_back(x-1, y+1);
        }
        if(x+1 <= 7 && board[x+1][y+1] != "  " && board[x+1][y+1][1] == 'B'){
            moves.emplace_back(x+1, y+1);
        }
    }
    else if(!piece->getWhite() && piece->getMoveDirectionUp()){
        if(board[x][y-1] == "  "){
            moves.emplace_back(x, y-1);
            if(board[x][y-2] == "  " && piece->firstMove){
                moves.emplace_back(x, y-2);
            }
        }
        if(x-1 >= 0 && board[x-1][y-1] != "  " && board[x-1][y-1][1] == 'W'){
            moves.emplace_back(x-1, y-1);
        }
        if(x+1 <= 7 && board[x+1][y-1] != "  " && board[x+1][y-1][1] == 'W'){
            moves.emplace_back(x+1, y-1);
        }
    }
    else if(!piece->getWhite() && !piece->getMoveDirectionUp()){
        if(board[x][y+1] == "  "){
            moves.emplace_back(x, y+1);
            if(board[x][y+2] == "  " && piece->firstMove){
                moves.emplace_back(x, y+2);
            }
        }
        if(x-1 >= 0 && board[x-1][y+1] != "  " && board[x-1][y+1][1] == 'W'){
            moves.emplace_back(x-1, y+1);
        }
        if(x+1 <= 7 && board[x+1][y+1] != "  " && board[x+1][y+1][1] == 'W'){
            moves.emplace_back(x+1, y+1);
        }
    }
    return moves;
}

std::vector<std::pair<int, int>> MoveGeneration::rookMoves(std::string **board, Piece *piece) {
    std::vector<std::pair<int, int>> moves;
    // make move for rook

    return moves;
}

std::vector<std::pair<int, int>> MoveGeneration::knightMoves(std::string **board, Piece *piece) {
    std::vector<std::pair<int, int>> moves;
    return moves;
}

std::vector<std::pair<int, int>> MoveGeneration::bishopMoves(std::string **board, Piece *piece) {
    std::vector<std::pair<int, int>> moves;
    return moves;
}

std::vector<std::pair<int, int>> MoveGeneration::queenMoves(std::string **board, Piece *piece) {
    std::vector<std::pair<int, int>> moves;
    return moves;
}

std::vector<std::pair<int, int>> MoveGeneration::kingMoves(std::string **board, Piece *piece) {
    std::vector<std::pair<int, int>> moves;
    return moves;
}

