#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Board
{
public:
    
    Board(const sf::Vector2f& position, float cellSize, int rows, int columns);

    void AfterSelection(sf::RenderWindow& window, const sf::Vector2f& position);

    std::vector<sf::Vector2f> ShowLegalMoves(const sf::Vector2f& position, sf::Color color, sf::Color outlineColor, std::vector<sf::CircleShape*>& checkers);
    std::vector<sf::Vector2f> checkCellForKingsMove(sf::CircleShape* ñhecker, float startX, float startY, float step, float endX, float endY, sf::Color color);

    sf::CircleShape* findSelectedChecker(const std::vector<sf::CircleShape*>& checkers, float targetX, float targetY, float step, sf::RectangleShape* cell);
  
   

     
   

    sf::Vector2f getPosition() const;
    float getCellSize() const;
    int getRows() const;
    int getColumns() const;
    sf::RectangleShape& getCellShape(int row, int column);
    void draw(sf::RenderWindow& window);

    int PiecesPos[8][8]
    {   0,1,0,1,0,1,0,0,
        1,0,1,0,1,0,1,0,
        0,1,0,1,0,1,0,0,
        1,0,1,0,1,0,1,0,
        0,1,0,1,0,1,0,0,
        1,0,1,0,1,0,1,0,
        0,1,0,1,0,1,0,0,
        1,0,1,0,1,0,1,0
    };
    

private: 
    bool CheckCellsForMove(std::vector<sf::CircleShape*>& checkers, const sf::Vector2f& position, sf::Color color);
    bool CheckForHit(std::vector<sf::CircleShape*>& checkers, const sf::Vector2f& position, sf::Vector2f hitPos, sf::Color color);
    sf::Vector2f m_position;
    float m_cellSize = 135;
    int m_rows;
    int m_columns;
    std::vector<sf::RectangleShape> m_cells;
};
