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
    // check for the condition if pawn next move is out of the board
    if(piece->getWhite() && piece->getMoveDirectionUp()){
        if(y-1 >= 0 && board[y-1][x] == "  "){
            moves.emplace_back(x, y-1);
            if(y-2 >= 0 && board[y-2][x] == "  " && piece->firstMove){
                moves.emplace_back(x, y-2);
            }
        }
        if(x-1 >= 0 && y-1 >= 0 && board[y-1][x-1] != "  " && board[y-1][x-1][1] == 'B'){
            moves.emplace_back(x-1, y-1);
        }
        if(x+1 <= 7 && y-1 >= 0 && board[y-1][x+1] != "  " && board[y-1][x+1][1] == 'B'){
            moves.emplace_back(x+1, y-1);
        }
    }
    else if(piece->getWhite() && !piece->getMoveDirectionUp()){
        if(y+1 <= 7 && board[y+1][x] == "  "){
            moves.emplace_back(x, y+1);
            if(y+2 <= 7 && board[y+2][x] == "  " && piece->firstMove){
                moves.emplace_back(x, y+2);
            }
        }
        if(x-1 >= 0 && y+1 <= 7 && board[y+1][x-1] != "  " && board[y+1][x-1][1] == 'B'){
            moves.emplace_back(x-1, y+1);
        }
        if(x+1 <= 7 && y+1 <= 7 && board[y+1][x+1] != "  " && board[y+1][x+1][1] == 'B'){
            moves.emplace_back(x+1, y+1);
        }
    }
    else if(!piece->getWhite() && piece->getMoveDirectionUp()){
        if(y-1 >= 0 && board[y-1][x] == "  "){
            moves.emplace_back(x, y-1);
            if(y-2 >= 0 && board[y-2][x] == "  " && piece->firstMove){
                moves.emplace_back(x, y-2);
            }
        }
        if(x-1 >= 0 && y-1 >= 0 && board[y-1][x-1] != "  " && board[y-1][x-1][1] == 'W'){
            moves.emplace_back(x-1, y-1);
        }
        if(x+1 <= 7 && y-1 >= 0 && board[y-1][x+1] != "  " && board[y-1][x+1][1] == 'W'){
            moves.emplace_back(x+1, y-1);
        }
    }
    return moves;
}

std::vector<std::pair<int, int>> MoveGeneration::rookMoves(std::string **board, Piece *piece) {
    std::vector<std::pair<int, int>> moves;
    // make move for rook
    if (piece->getWhite()) {
        int x = piece->getPrevPos().x / 100;
        int y = piece->getPrevPos().y / 100;
        int i = 1;
        while (x + i <= 7) {
            if (board[y][x + i] == "  ") {
                moves.emplace_back(x + i, y);
                i++;
            } else if (board[y][x + i][1] == 'B') {
                moves.emplace_back(x + i, y);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (x - i >= 0) {
            if (board[y][x - i] == "  ") {
                moves.emplace_back(x - i, y);
                i++;
            } else if (board[y][x - i][1] == 'B') {
                moves.emplace_back(x - i, y);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (y + i <= 7) {
            if (board[y + i][x] == "  ") {
                moves.emplace_back(x, y + i);
                i++;
            } else if (board[y + i][x][1] == 'B') {
                moves.emplace_back(x, y + i);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (y - i >= 0) {
            if (board[y - i][x] == "  ") {
                moves.emplace_back(x, y - i);
                i++;
            } else if (board[y - i][x][1] == 'B') {
                moves.emplace_back(x, y - i);
                break;
            } else {
                break;
            }
        }
    } else {
        int x = piece->getPrevPos().x / 100;
        int y = piece->getPrevPos().y / 100;
        int i = 1;
        while (x + i <= 7) {
            if (board[y][x + i] == "  ") {
                moves.emplace_back(x + i, y);
                i++;
            } else if (board[y][x + i][1] == 'W') {
                moves.emplace_back(x + i, y);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (x - i >= 0) {
            if (board[y][x - i] == "  ") {
                moves.emplace_back(x - i, y);
                i++;
            } else if (board[y][x - i][1] == 'W') {
                moves.emplace_back(x - i, y);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (y + i <= 7) {
            if (board[y + i][x] == "  ") {
                moves.emplace_back(x, y + i);
                i++;
            } else if (board[y + i][x][1] == 'W') {
                moves.emplace_back(x, y + i);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (y - i >= 0) {
            if (board[y - i][x] == "  ") {
                moves.emplace_back(x, y - i);
                i++;
            } else if (board[y - i][x][1] == 'W') {
                moves.emplace_back(x, y - i);
                break;
            } else {
                break;
            }
        }
    }
    return moves;
}

std::vector<std::pair<int, int>> MoveGeneration::knightMoves(std::string **board, Piece *piece) {
    std::vector<std::pair<int, int>> moves;
    // make move for knight
    if (piece->getWhite()) {
        int x = piece->getPrevPos().x / 100;
        int y = piece->getPrevPos().y / 100;
        if (x + 2 <= 7 && y + 1 <= 7 && board[y + 1][x + 2][1] != 'W') {
            moves.emplace_back(x + 2, y + 1);
        }
        if (x + 2 <= 7 && y - 1 >= 0 && board[y - 1][x + 2][1] != 'W') {
            moves.emplace_back(x + 2, y - 1);
        }
        if (x - 2 >= 0 && y + 1 <= 7 && board[y + 1][x - 2][1] != 'W') {
            moves.emplace_back(x - 2, y + 1);
        }
        if (x - 2 >= 0 && y - 1 >= 0 && board[y - 1][x - 2][1] != 'W') {
            moves.emplace_back(x - 2, y - 1);
        }
        if (x + 1 <= 7 && y + 2 <= 7 && board[y + 2][x + 1][1] != 'W') {
            moves.emplace_back(x + 1, y + 2);
        }
        if (x + 1 <= 7 && y - 2 >= 0 && board[y - 2][x + 1][1] != 'W') {
            moves.emplace_back(x + 1, y - 2);
        }
        if (x - 1 >= 0 && y + 2 <= 7 && board[y + 2][x - 1][1] != 'W') {
            moves.emplace_back(x - 1, y + 2);
        }
        if (x - 1 >= 0 && y - 2 >= 0 && board[y - 2][x - 1][1] != 'W') {
            moves.emplace_back(x - 1, y - 2);
        }
    } else {
        int x = piece->getPrevPos().x / 100;
        int y = piece->getPrevPos().y / 100;
        if (x + 2 <= 7 && y + 1 <= 7 && board[y + 1][x + 2][1] != 'B') {
            moves.emplace_back(x + 2, y + 1);
        }
        if (x + 2 <= 7 && y - 1 >= 0 && board[y - 1][x + 2][1] != 'B') {
            moves.emplace_back(x + 2, y - 1);
        }
        if (x - 2 >= 0 && y + 1 <= 7 && board[y + 1][x - 2][1] != 'B') {
            moves.emplace_back(x - 2, y + 1);
        }
        if (x - 2 >= 0 && y - 1 >= 0 && board[y - 1][x - 2][1] != 'B') {
            moves.emplace_back(x - 2, y - 1);
        }
        if (x + 1 <= 7 && y + 2 <= 7 && board[y + 2][x + 1][1] != 'B') {
            moves.emplace_back(x + 1, y + 2);
        }
        if (x + 1 <= 7 && y - 2 >= 0 && board[y - 2][x + 1][1] != 'B') {
            moves.emplace_back(x + 1, y - 2);
        }
        if (x - 1 >= 0 && y + 2 <= 7 && board[y + 2][x - 1][1] != 'B') {
            moves.emplace_back(x - 1, y + 2);
        }
        if (x - 1 >= 0 && y - 2 >= 0 && board[y - 2][x - 1][1] != 'B') {
            moves.emplace_back(x - 1, y - 2);
        }
    }

    return moves;
}

std::vector<std::pair<int, int>> MoveGeneration::bishopMoves(std::string **board, Piece *piece) {
    std::vector<std::pair<int, int>> moves;
    // make move for bishop
    if (piece->getWhite()) {
        int x = piece->getPrevPos().x / 100;
        int y = piece->getPrevPos().y / 100;
        int i = 1;
        while (x + i <= 7 && y + i <= 7) {
            if (board[y + i][x + i] == "  ") {
                moves.emplace_back(x + i, y + i);
                i++;
            } else if (board[y + i][x + i][1] == 'B') {
                moves.emplace_back(x + i, y + i);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (x - i >= 0 && y + i <= 7) {
            if (board[y + i][x - i] == "  ") {
                moves.emplace_back(x - i, y + i);
                i++;
            } else if (board[y + i][x - i][1] == 'B') {
                moves.emplace_back(x - i, y + i);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (x + i <= 7 && y - i >= 0) {
            if (board[y - i][x + i] == "  ") {
                moves.emplace_back(x + i, y - i);
                i++;
            } else if (board[y - i][x + i][1] == 'B') {
                moves.emplace_back(x + i, y - i);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (x - i >= 0 && y - i >= 0) {
            if (board[y - i][x - i] == "  ") {
                moves.emplace_back(x - i, y - i);
                i++;
            } else if (board[y - i][x - i][1] == 'B') {
                moves.emplace_back(x - i, y - i);
                break;
            } else {
                break;
            }
        }
    } else {
        int x = piece->getPrevPos().x / 100;
        int y = piece->getPrevPos().y / 100;
        int i = 1;
        while (x + i <= 7 && y + i <= 7) {
            if (board[y + i][x + i] == "  ") {
                moves.emplace_back(x + i, y + i);
                i++;
            } else if (board[y + i][x + i][1] == 'W') {
                moves.emplace_back(x + i, y + i);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (x - i >= 0 && y + i <= 7) {
            if (board[y + i][x - i] == "  ") {
                moves.emplace_back(x - i, y + i);
                i++;
            } else if (board[y + i][x - i][1] == 'W') {
                moves.emplace_back(x - i, y + i);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (x + i <= 7 && y - i >= 0) {
            if (board[y - i][x + i] == "  ") {
                moves.emplace_back(x + i, y - i);
                i++;
            } else if (board[y - i][x + i][1] == 'W') {
                moves.emplace_back(x + i, y - i);
                break;
            } else {
                break;
            }
        }
        i = 1;
        while (x - i >= 0 && y - i >= 0) {
            if (board[y - i][x - i] == "  ") {
                moves.emplace_back(x - i, y - i);
                i++;
            } else if (board[y - i][x - i][1] == 'W') {
                moves.emplace_back(x - i, y - i);
                break;
            } else {
                break;
            }
        }
    }
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

