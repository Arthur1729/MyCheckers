#include "Board.h"
#include <iostream>
Board::Board(const sf::Vector2f& position, float cellSize, int rows, int columns)
    : m_position(position), m_cellSize(cellSize), m_rows(rows), m_columns(columns)
{
    // Инициализация ячеек доски
    m_cells.resize(rows * columns);
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            sf::RectangleShape& cell = m_cells[row * columns + col];

                cell.setSize(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(position.x + col * cellSize, position.y + row * cellSize);
                // Цветa чередуются между четными и нечетными строками
                if ((row + col) % 2 == 0)
                {
                    cell.setFillColor(sf::Color::White);
                }
                else
                {cell.setFillColor(sf::Color::Black);
                    
                }
                cell.setOutlineThickness(1.f);
                cell.setOutlineColor(sf::Color::Black);
        }
    }
}

void Board::draw(sf::RenderWindow& window)
{
    for (const auto& cell : m_cells)
    {
        window.draw(cell);
    }
}
std::vector<sf::Vector2f> Board::ShowLegalMoves(const sf::Vector2f& position, sf::Color color, std::vector<sf::CircleShape*>& checkers) 
{
    std::vector<sf::Vector2f> MovementVector;
    if (color == sf::Color::Red)
    {
        int newPosition1 = position.x - 135;
        int newPosition2 = position.y + 135;
        int newPos3 = position.x + 135;
        int newPos4 = position.y + 135;
        bool LeftCellIsFull = false;
        bool RightCellIsFull = false;
        // Проверка на занятость позиции слева/справa
        for (sf::CircleShape* checker : checkers)
        {   // Проверка для каждой пешки нахождение 
            sf::FloatRect boundCheck = checker->getGlobalBounds();
            for (auto& cell : m_cells)
            {
                if (cell.getGlobalBounds().contains(newPosition1, newPosition2) && cell.getGlobalBounds().intersects(boundCheck))
                {
                    LeftCellIsFull = true;
                }

                if (cell.getGlobalBounds().contains(newPos3, newPos4) && cell.getGlobalBounds().intersects(boundCheck))
                {
                    RightCellIsFull = true;
                }

            }

        }
        if (!LeftCellIsFull)
        {
            for (auto& cell : m_cells)
            {
                if (cell.getGlobalBounds().contains(newPosition1, newPosition2)) cell.setFillColor(sf::Color::Blue);
                MovementVector.push_back(sf::Vector2f(newPosition1, newPosition2));
            

            if (!RightCellIsFull && cell.getGlobalBounds().contains(newPos3, newPos4))
            {
                cell.setFillColor(sf::Color::Blue);
                MovementVector.push_back(sf::Vector2f(newPos3, newPos4));

            }}
        }


    }
    if (color == sf::Color::Green)
    {
        std::cout << "Red";

        int newPosition1 = position.x - 135;
        int newPosition2 = position.y - 135;
        int newPos3 = position.x + 135;
        int newPos4 = position.y - 135;
        bool LeftCellIsFull = false;
        bool RightCellIsFull = false;

        // Проверка на занятость позиции слева/справa
        for (sf::CircleShape* checker : checkers)
        {   // Проверка для каждой пешки нахождение 
            sf::FloatRect boundCheck = checker->getGlobalBounds();
            for (auto& cell : m_cells)
            {
                if (cell.getGlobalBounds().contains(newPosition1, newPosition2) && cell.getGlobalBounds().intersects(boundCheck))
                {
                    LeftCellIsFull = true;
                }

                if (cell.getGlobalBounds().contains(newPos3, newPos4) && cell.getGlobalBounds().intersects(boundCheck))
                {
                    RightCellIsFull = true;
                }

            }

        }
        if (!LeftCellIsFull)
        {
            for (auto& cell : m_cells)
            {
                if (cell.getGlobalBounds().contains(newPosition1, newPosition2)) cell.setFillColor(sf::Color::Blue);
                MovementVector.push_back(sf::Vector2f(newPosition1, newPosition2));
            

            if (!RightCellIsFull)
            {
                if (cell.getGlobalBounds().contains(newPos3, newPos4)) cell.setFillColor(sf::Color::Blue);
                MovementVector.push_back(sf::Vector2f(newPos3, newPos4));

            }}
        }
    }
    return MovementVector;
}


void Board::CheckHitMoves(const sf::Vector2f& position, sf::Color color, std::vector<sf::CircleShape*>& checkers) {
    int newPosition1 = position.x + 135;
    int newPosition2 = position.y + 135;
    for (auto& cell : m_cells)
    {
        if (cell.getPosition().x == newPosition1 && cell.getPosition().y == newPosition2)
            cell.setFillColor(sf::Color::Green);
        
    }
    
    
}



sf::Vector2f Board::getPosition() const
{
    return m_position;
}

float Board::getCellSize() const
{
    return m_cellSize;
}

int Board::getRows() const
{
    return m_rows;
}

int Board::getColumns() const
{
    return m_columns;
}

sf::RectangleShape& Board::getCellShape(int row, int column)
{
    return m_cells[row * m_columns + column];
}
void Board::AfterSelection(sf::RenderWindow& window, const sf::Vector2f& position) {
    {   int rows = 8;
    int columns = 8;
    float cellSize = 135;
    // Инициализация ячеек доски
    m_cells.resize(rows * columns);
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            sf::RectangleShape& cell = m_cells[row * columns + col];

            cell.setSize(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(position.x + col * cellSize, position.y + row * cellSize);
            // Цветa чередуются между четными и нечетными строками
            if ((row + col) % 2 == 0)
            {
                cell.setFillColor(sf::Color::White);
            }
            else
            {
                cell.setFillColor(sf::Color::Black);

            }
            cell.setOutlineThickness(1.f);
            cell.setOutlineColor(sf::Color::Black);
        }
    }
    }
}