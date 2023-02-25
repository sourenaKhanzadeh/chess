#include "../include/board.hpp"

Board::Board(sf::Vector2f position, sf::Vector2f size, sf::Color color): BoardObject(position, size, color)
{
    for (int i = 0; i < 8; i++)
    {
        std::vector<Cell*> row;
        for (int j = 0; j < 8; j++)
        {
            row.push_back(new Cell(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Color::Black));
        }
        cells.push_back(row);
    }
}

Board::~Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            delete cells[i][j];
        }
    }
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
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // make the cells like a chess board
            if ((i + j) % 2 == 0)
            {
                cells[i][j]->setColor(sf::Color::White);
            }
            else
            {
                cells[i][j]->setColor(sf::Color::Black);
            }
            //add white pawn to the first row
            if (j == 1)
            {
                cells[i][j]->setPiece(new Pawn(sf::Vector2f(position.x + i * size.x / 8, position.y + j * size.y / 8), 
                sf::Vector2f(size.x / 8, size.y / 8), sf::Color::White, true));
            }
            cells[i][j]->setPosition(sf::Vector2f(position.x + i * size.x / 8, position.y + j * size.y / 8));
            cells[i][j]->setSize(sf::Vector2f(size.x / 8, size.y / 8));
            cells[i][j]->draw(window);
        }
    }
}

void Board::update(sf::Time deltaTime)
{
}
