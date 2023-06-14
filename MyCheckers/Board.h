#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Board
{
public:
    Board(const sf::Vector2f& position, float cellSize, int rows, int columns);

    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    float getCellSize() const;
    int getRows() const;
    int getColumns() const;
    sf::RectangleShape& getCellShape(int row, int column); // Добавленный метод

private:
    sf::Vector2f m_position;
    float m_cellSize;
    int m_rows;
    int m_columns;
    std::vector<sf::RectangleShape> m_cells;
};
