#include "../include/board.hpp"

Board::Board(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool playAsWhite): BoardObject(position, size, color)
{
    this->playAsWhite = playAsWhite;
    for (int i = 0; i < 8*8; i++)
    {
        cells.push_back(new Cell(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Color::White));
    }
    // rotate 'board' 90 degrees to make it easier to read
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::string temp = board[i][j];
            board[i][j] = board[j][i];
            board[j][i] = temp;
        }
    }
    if (playAsWhite)
    {
        // rotate 'board' 180 degrees
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::string temp = board[i][j];
                board[i][j] = board[i][7 - j];
                board[i][7 - j] = temp;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // make the cells like a chess board
            if ((i + j) % 2 == 0)
            {
                cells[i * 8 + j]->setColor(sf::Color(255, 206, 158));
            }
            else
            {
                cells[i * 8 + j]->setColor(sf::Color(209, 139, 71));
            }
            sf::Vector2f pos(position.x + i * size.x / 8, position.y + j * size.y / 8);
            sf::Vector2f si(size.x / 8, size.y / 8);
            cells[i * 8 + j]->setPosition(pos);
            cells[i * 8 + j]->setSize(si);
            if (board[i][j] != "")
            {
                Piece* piece;
                if (board[i][j] == "PW"){
                    piece = new Pawn(pos, si, sf::Color::White, true);
                }else if (board[i][j] == "PB"){
                    piece = new Pawn(pos, si, sf::Color::Black, false);
                }
                else if(board[i][j] == "RW"){
                    piece = new Rook(pos, si, sf::Color::White, true);
                }else if(board[i][j] == "RB"){
                    piece = new Rook(pos, si, sf::Color::Black, false);
                }
                else if(board[i][j] == "NW"){
                    piece = new Knight(pos, si, sf::Color::White, true);
                }else if(board[i][j] == "NB"){
                    piece = new Knight(pos, si, sf::Color::Black, false);
                }else if (board[i][j] == "BW"){
                    piece = new Bishop(pos, si, sf::Color::White, true);
                }else if (board[i][j] == "BB"){
                    piece = new Bishop(pos, si, sf::Color::Black, false);
                }else if (board[i][j] == "QW"){
                    piece = new Queen(pos, si, sf::Color::White, true);
                }else if (board[i][j] == "QB"){
                    piece = new Queen(pos, si, sf::Color::Black, false);
                }
                else if (board[i][j] == "KW"){
                    piece = new King(pos, si, sf::Color::White, true);
                }else if (board[i][j] == "KB"){
                    piece = new King(pos, si, sf::Color::Black, false);
                }
                else{
                    // for now 
                    piece = nullptr;
                }
                cells[i * 8 + j]->setPiece(piece);
            }
        }
    }

}

Board::~Board()
{
    for (int i = 0; i < 8*2; i++)
    {
        delete cells[i];
    }
    for (int i = 0; i < 8; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

void Board::setPosition(sf::Vector2f position)
{
    this->position = position;
    shape.setPosition(position);
}

void Board::setSize(sf::Vector2f size)
{
    this->size = size;
    shape.setSize(size);
}

void Board::setColor(sf::Color color)
{
    this->color = color;
    shape.setFillColor(color);
}

sf::Vector2f Board::getPosition()
{
    return position;
}

sf::Vector2f Board::getSize()
{
    return size;
}

sf::Color Board::getColor()
{
    return color;
}

void Board::draw(sf::RenderWindow& window)
{
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
    window.draw(shape);
    for (Cell* cell : cells)
    {
        cell->draw(window);
        if (cell->getPiece() != nullptr)
        {
            cell->getPiece()->draw(window);
        }
    }
}

void Board::update(sf::Time deltaTime)
{
}



void Board::mousePressed(sf::Event event, sf::RenderWindow& window)
{
    if(event.type == sf::Event::MouseButtonPressed){
        moving = true;
        for (Cell* cell : cells)
        {
            // check if the mouse is inside the cell
            if (cell->getPiece() != nullptr){
                // drag around the piece if the mouse is touching it
                if (cell->getPiece()->isMouseInside(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    cell->getPiece()->setDragging(true);
                    cell->getPiece()->mousePressed(event, window);
                }
            }
        }
    }else if(event.type == sf::Event::MouseMoved){
        if (moving){
            for (Cell* cell : cells)
            {
                if (cell->getPiece() != nullptr){
                    cell->getPiece()->mousePressed(event, window);
                }
            }
        }
    }else{
        moving = false;
        for (Cell* cell : cells)
        {
            if (cell->getPiece() != nullptr){
                cell->getPiece()->setDragging(false);
            }
        }
    }
}

void Board::mouseReleased(sf::Event event, sf::RenderWindow& window)
{
 
    
}