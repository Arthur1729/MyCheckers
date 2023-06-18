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
    bool LeftCellIsFull = false;
    bool RightCellIsFull = false;
    bool NextFromLeftCell = false;
    bool NextFromRightCell = false;
    bool NextFromRDCell = false;
    bool NextFromLDCell = false;
    bool Lmove = false;
    bool Rmove = false;
    bool rDmove = false;
    bool lDmove = false;
    std::vector<sf::Vector2f> MovementVector;

    if (color == sf::Color::Red)
    {
        int newPosition1 = position.x - 135;
        int newPosition2 = position.y + 135; //y для хода слеваВниз
        int newPos3 = position.x + 135;
        int newPos4 = position.y + 135;// y для хода справаВниз
        int LeftDownHitPosX = position.x-135;
        int LeftDownHitPosY = position.y-135;
        int RightDownHitPosX = position.x+135;
        int RightDownHitPosY = position.y-135;
        Lmove = CheckCellsForMove(checkers, sf::Vector2f(newPosition1, newPosition2),color);
        if (!Lmove) NextFromLeftCell = CheckForHit(checkers, sf::Vector2f(newPosition1, newPosition2), sf::Vector2f(newPosition1 - 135, newPosition2 + 135), color);
      
        Rmove = CheckCellsForMove(checkers, sf::Vector2f(newPos3, newPos4), color);
        if (!Rmove)NextFromRightCell = CheckForHit(checkers, sf::Vector2f(newPos3 , newPos4 ), sf::Vector2f(newPos3 + 135, newPos4 + 135), color);
        
        rDmove = CheckCellsForMove(checkers, sf::Vector2f(RightDownHitPosX, RightDownHitPosY), color);
        if (!rDmove) NextFromRDCell = CheckForHit(checkers, sf::Vector2f(RightDownHitPosX, RightDownHitPosY), sf::Vector2f(RightDownHitPosX+135, RightDownHitPosY-135), color);

        lDmove = CheckCellsForMove(checkers, sf::Vector2f(LeftDownHitPosX, LeftDownHitPosY), color);
        if (!lDmove) NextFromLDCell = CheckForHit(checkers, sf::Vector2f(LeftDownHitPosX,LeftDownHitPosY), sf::Vector2f(LeftDownHitPosX - 135, LeftDownHitPosY-135), color);

        // Выделение синим цветов полей пригодных для сбития
        for (auto& cell : m_cells)
        {
            if (!Lmove && NextFromLeftCell && cell.getGlobalBounds().contains(newPosition1 - 135, newPosition2 + 135)) // Проверка условия для сбития (сбитиие всегда в приоритете над перемещением
            {
                MovementVector.push_back(sf::Vector2f(newPosition1 - 135, newPosition2 + 135));
                cell.setFillColor(sf::Color::Blue);

            }
            if (NextFromRightCell &&!Rmove)
            {
                for (auto& cell : m_cells)
                {
                    if (cell.getGlobalBounds().contains(newPos3 + 135, newPos4 + 135)) {
                        MovementVector.push_back(sf::Vector2f(newPos3 + 135, newPos4 + 135));
                        cell.setFillColor(sf::Color::Blue);
                        
                    }
                }
            }
            if (NextFromLDCell && !lDmove)
            {
                for (auto& cell : m_cells)
                {
                    if (cell.getGlobalBounds().contains(LeftDownHitPosX-135, LeftDownHitPosY-135)) {
                        MovementVector.push_back(sf::Vector2f(LeftDownHitPosX-135, LeftDownHitPosY - 135));
                        cell.setFillColor(sf::Color::Blue);

                    }
                }
            }
            if (NextFromRDCell && !rDmove)
            {
                for (auto& cell : m_cells)
                {
                    if (cell.getGlobalBounds().contains(RightDownHitPosX + 135, RightDownHitPosY - 135)) {
                        MovementVector.push_back(sf::Vector2f(RightDownHitPosX + 135, RightDownHitPosY - 135));
                        cell.setFillColor(sf::Color::Blue);

                    }
                }
            }
            
           
        }
        if (!MovementVector.empty()) return MovementVector;
    
            // Выделение синим цветов полей пригодных для хода
            for (auto& cell : m_cells)
            {   
                if ( Lmove  
                    && cell.getGlobalBounds().contains(newPosition1, newPosition2))
                {
                    cell.setFillColor(sf::Color::Blue);
                    MovementVector.push_back(sf::Vector2f(newPosition1, newPosition2));
                }

            if (Rmove && cell.getGlobalBounds().contains(newPos3, newPos4))
            {
                cell.setFillColor(sf::Color::Blue);
                MovementVector.push_back(sf::Vector2f(newPos3, newPos4));

            }
        }


    }
    else if (color == sf::Color::Green)
    {

        int newPos1 = position.x - 135;
        int newPos2 = position.y - 135;
        int newPos3 = position.x + 135;
        int newPos4 = position.y - 135;
        int LeftDownHitPosX = position.x - 135;
        int LeftDownHitPosY = position.y + 135;
        int RightDownHitPosX = position.x + 135;
        int RightDownHitPosY = position.y + 135;
       
       
        Lmove = CheckCellsForMove(checkers, sf::Vector2f(newPos1, newPos2), color);
        if (!Lmove) NextFromLeftCell = CheckForHit(checkers, sf::Vector2f(newPos1 , newPos2), sf::Vector2f(newPos1 - 135, newPos2 - 135), color);

        Rmove = CheckCellsForMove(checkers, sf::Vector2f(newPos3, newPos4), color);
        if (!Rmove)NextFromRightCell = CheckForHit(checkers, sf::Vector2f(newPos3, newPos4), sf::Vector2f(newPos3 + 135, newPos4 - 135), color);


        rDmove = CheckCellsForMove(checkers, sf::Vector2f(RightDownHitPosX, RightDownHitPosY), color);
        if (!rDmove) NextFromRDCell=CheckForHit(checkers, sf::Vector2f(RightDownHitPosX, RightDownHitPosY), sf::Vector2f(RightDownHitPosX+135, RightDownHitPosY+135), color);

        lDmove = CheckCellsForMove(checkers, sf::Vector2f( LeftDownHitPosX,  LeftDownHitPosY), color);
        if (!lDmove) NextFromLDCell=CheckForHit(checkers, sf::Vector2f(LeftDownHitPosX, LeftDownHitPosY), sf::Vector2f(LeftDownHitPosX - 135, LeftDownHitPosY + 135), color);
   


                // Выделение синим цветов полей пригодных для сбития
      
            if (!Lmove && NextFromLeftCell ) 
            {
                for (auto& cell : m_cells)
                {
                    if( cell.getGlobalBounds().contains(newPos1 - 135, newPos2 - 135))
                    { 
                        MovementVector.push_back(sf::Vector2f(newPos1 - 135, newPos2 - 135));
                        cell.setFillColor(sf::Color::Blue);
                }

                }
            }
            if (NextFromRightCell && !Rmove)
            {
                for (auto& cell : m_cells)
                {
                    if (cell.getGlobalBounds().contains(newPos3 + 135, newPos4 - 135)) {
                        MovementVector.push_back(sf::Vector2f(newPos3 + 135, newPos4 - 135));
                        cell.setFillColor(sf::Color::Blue);

                    }
                }}
                if (NextFromLDCell && !lDmove)
                {
                   
                    for (auto& cell : m_cells)
                    {
                        if (cell.getGlobalBounds().contains(LeftDownHitPosX - 135, LeftDownHitPosY + 135)) {
                            MovementVector.push_back(sf::Vector2f(LeftDownHitPosX - 135, LeftDownHitPosY + 135));
                            cell.setFillColor(sf::Color::Blue);
                         

                        }
                    }
                }
                if (NextFromRDCell && !rDmove)
                {
                    for (auto& cell : m_cells)
                    {

                        if (cell.getGlobalBounds().contains(RightDownHitPosX + 135, RightDownHitPosY + 135)) {
                            MovementVector.push_back(sf::Vector2f(RightDownHitPosX + 135, RightDownHitPosY + 135));
                            cell.setFillColor(sf::Color::Blue);

                        }
                    }
                }
            

        if (!MovementVector.empty()) return MovementVector;

        // Выделение синим цветов полей пригодных для хода
        for (auto& cell : m_cells)
        {
            if (Lmove
                && cell.getGlobalBounds().contains(newPos1, newPos2))
            {
                cell.setFillColor(sf::Color::Blue);
                MovementVector.push_back(sf::Vector2f(newPos1, newPos2));
            }

            if (Rmove && cell.getGlobalBounds().contains(newPos3, newPos4))
            {
                cell.setFillColor(sf::Color::Blue);
                MovementVector.push_back(sf::Vector2f(newPos3, newPos4));

            }
            
        }




        
    }
    return MovementVector;
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
bool Board::CheckCellsForMove(std::vector<sf::CircleShape*>& checkers, const sf::Vector2f& position, sf::Color color)
{
    for (sf::CircleShape* checker : checkers)
    {   // Проверка на наличие свободных полей для перемещения пешек на доске
        sf::Vector2f chckPos = checker->getPosition();
        for (int i = 0; i < m_cells.size() - 1; i++)
        {
            if (m_cells[i].getGlobalBounds().contains(position.x, position.y) && m_cells[i].getGlobalBounds().contains(chckPos)) // Если поле находится на координатах след. хода и содержит в ней пешку(проверка слеваВнизу)
            {
                // Следовательно влево нельзя идти, так как клетка содержит пешку какого либо цвета
                m_cells[i].setFillColor(sf::Color::Yellow);

                return false;
                


            }
        }
    }
    return true;
}
bool Board::CheckForHit(std::vector<sf::CircleShape*>& checkers, const sf::Vector2f& position,sf::Vector2f hitPos, sf::Color color)
{

    for (sf::CircleShape* checker : checkers)
    {   // Проверка на наличие свободных полей для перемещения пешек на доске
        sf::Vector2f chckPos = checker->getPosition();
        sf::Color color1= checker->getFillColor();
        for (int i = 0; i < m_cells.size() - 1; i++)
        {
            if (m_cells[i].getGlobalBounds().contains(position.x, position.y) && m_cells[i].getGlobalBounds().contains(chckPos) ) // Если поле находится на координатах след. хода и содержит в ней пешку
            {


                if (!(checker->getFillColor() == color))
                {

                    for (sf::CircleShape* checker1 : checkers)
                    {
                        for (auto& cell : m_cells)
                        {
                            if (cell.getGlobalBounds().contains(hitPos.x, hitPos.y) && cell.getGlobalBounds().contains(checker1->getPosition()))
                            {   // Если след. после пешки которую хотим сбить занята,то нельзя сбивать

                                return false;
                            }
                        }
                    }
                }
                else
                {

                    return false;
                }

            }
          
        }
    }
    return true;
}