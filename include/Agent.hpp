//
// Created by sourena khanzadeh on 2023-03-06.
//

#ifndef CHESS_AGENT_HPP
#define CHESS_AGENT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "piece.hpp"

class MoveGeneration{
public:
    MoveGeneration();
    ~MoveGeneration();
    static std::vector<std::pair<int, int>> generateMoves(std::string **board, Piece* piece, bool check=false, bool stalemate=false);
private:
    static std::vector<std::pair<int, int>> pawnMoves(std::string **board, Piece* piece);
    static std::vector<std::pair<int, int>> rookMoves(std::string **board, Piece* piece);
    static std::vector<std::pair<int, int>> knightMoves(std::string **board, Piece* piece);
    static std::vector<std::pair<int, int>> bishopMoves(std::string **board, Piece* piece);
    static std::vector<std::pair<int, int>> queenMoves(std::string **board, Piece* piece);
    static std::vector<std::pair<int, int>> kingMoves(std::string **board, Piece* piece);

};

// Agent is an abstract class that defines the basic functions of an agent
// for the game of chess
class Agent {
public:

protected:

};

#endif //CHESS_AGENT_HPP
