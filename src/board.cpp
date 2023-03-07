#include "../include/board.hpp"

Board::Board(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool playAsWhite): BoardObject(position, size, color)
{
    this->playAsWhite = playAsWhite;
    for (int i = 0; i < 8*8; i++)
    {
        cells.push_back(new Cell(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Color::White));
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
            sf::Vector2f pos(position.x + j * size.x / 8, position.y + i * size.y / 8);
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
                if (piece != nullptr)
                {
                    if (playAsWhite && pos.y > 400 || !playAsWhite && pos.y < 400){
                        piece->setMoveDirectionUp(true);
                    }else{
                        piece->setMoveDirectionUp(false);
                    }
                    piece->setPrevPos(pos);
                    pieces.push_back(piece);
                }
                
                // cells[i * 8 + j]->setPiece(piece);
            }
        }
    }
    for (Piece* piece : pieces)
    {
        piece->setPieces(pieces);
    }

    
    

    
}

Board::~Board()
{
    for (int i = 0; i < 8*2; i++)
    {
        delete cells[i];
    }
    for(Piece* piece : pieces){
        delete piece;
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
    }
    for (Piece* piece : pieces)
    {
        piece->draw(window);
        if(piece->getDestroyed()){
            pieces.erase(std::remove(pieces.begin(), pieces.end(), piece), pieces.end());
            piece = nullptr;
            delete piece;
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
        for (Piece* piece : pieces)
        {
            // drag around the piece if the mouse is touching it
            if (piece->isMouseInside(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
            {
                piece->setDragging(true);
                piece->mousePressed(event, window);
                currentChosenPiecePosition =  piece->getPosition();
            }
        }
    }else if(event.type == sf::Event::MouseMoved){
        if (moving){
            for (Piece* piece : pieces)
            {
                piece->mousePressed(event, window);
            }
        }
    }
}

void Board::mouseReleased(sf::Event event, sf::RenderWindow& window)
{
 for (Piece* piece : pieces)
    {
        if (piece->isDragging()){            
            for (Cell* cell : cells)
            {
                if (cell->isMouseInside(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    // convert the position of the piece to the position of the cell to grid coordinates
                    int x = (piece->getPrevPos().x) / 100;
                    int y = (piece->getPrevPos().y) / 100;
                    int x2 = (cell->getPosition().x) / 100;
                    int y2 = (cell->getPosition().y) / 100;
                    std::vector<std::string> res = MoveGeneration::generateMoves(board, piece);
                    for (const std::string& s : res)
                    {
                        std::cout << s << std::endl;
                    }
                    std::cout << "x: " << x << " y: " << y << " x2: " << x2 << " y2: " << y2 << std::endl;
                    if (piece->isMoveValid(x, y, x2, y2, board))
                    {
                        piece->firstMove = false;
                        movePiece(x, y, x2, y2);
                        std::cout << *this << std::endl;
                        piece->setPosition(cell->getPosition());
                        piece->setPrevPos(cell->getPosition());
                        piece->setDragging(false);
                    }else{
                        piece->setPosition(piece->getPrevPos());
                        piece->setDragging(false);
                    }
                }
            }
        }
    }
    moving = false;
    
}

std::vector<Cell*> Board::getCells()
{
    return cells;
}

void Board::movePiece(int x, int y, int x2, int y2)
{
    if (board[y2][x2] != "  ")
    {
        for (Piece* piece : pieces)
        {
            if (piece->getPosition() == sf::Vector2f(x2 * 100, y2 * 100) && board[y][x][1] != board[y2][x2][1])
            {
                piece->setDestroyed(true);
            }
            //en passant
            // if (piece->getPosition() == sf::Vector2f(x2 * 100, y * 100) && board[y][x][1] != board[y2][x2][1] && board[y][x][0] == 'P' && board[y2][x2][0] == 'P')
            // {
            //     piece->setDestroyed(true);
            // }
        }
    }
    // castling
    if (board[y][x] == "KW" && x2 == 6 && y2 == 0)
    {
        Piece * rooke = getPieceFromBoard(7, 0);
        rooke->setPosition(sf::Vector2f(5 * 100, 0));
        rooke->setPrevPos(sf::Vector2f(5 * 100, 0));
        board[0][5] = "RW";
        board[0][7] = "  ";
    }else if (board[y][x] == "KW" && x2 == 2 && y2 == 0)
    {
        Piece * rooke = getPieceFromBoard(0, 0);
        rooke->setPosition(sf::Vector2f(3 * 100, 0));
        rooke->setPrevPos(sf::Vector2f(3 * 100, 0));
        board[0][3] = "RW";
        board[0][0] = "  ";
    }else if (board[y][x] == "KB" && x2 == 6 && y2 == 7)
    {
        Piece * rooke = getPieceFromBoard(7, 7);
        rooke->setPosition(sf::Vector2f(5 * 100, 7 * 100));
        rooke->setPrevPos(sf::Vector2f(5 * 100, 7 * 100));
        board[7][5] = "RB";
        board[7][7] = "  ";
    }else if (board[y][x] == "KB" && x2 == 2 && y2 == 7)
    {
        Piece * rooke = getPieceFromBoard(0, 7);
        rooke->setPosition(sf::Vector2f(3 * 100, 7 * 100));
        rooke->setPrevPos(sf::Vector2f(3 * 100, 7 * 100));
        board[7][3] = "RB";
        board[7][0] = "  ";
    }
    board[y2][x2] = board[y][x];
    board[y][x] = "  ";

}

Piece* Board::getPieceFromBoard(int x, int y)
{
    for (Piece* piece : pieces)
    {
        if (piece->getPosition() == sf::Vector2f(x * 100, y * 100))
        {
            return piece;
        }
    }
    return nullptr;
}