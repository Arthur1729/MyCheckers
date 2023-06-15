#include "Board.h"

Board::Board(const sf::Vector2f& position, float cellSize, int rows, int columns)
    : m_position(position), m_cellSize(cellSize), m_rows(rows), m_columns(columns)
{
    // »нициализаци€ €чеек доски
    m_cells.resize(rows * columns);
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            sf::RectangleShape& cell = m_cells[row * columns + col];

                cell.setSize(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(position.x + col * cellSize, position.y + row * cellSize);
                // ÷веты чередуютс€ между четными и нечетными строками
                if ((row + col) % 2 == 0)
                {
                    cell.setFillColor(sf::Color::Black);
                }
                else
                {
                    cell.setFillColor(sf::Color::White);
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
