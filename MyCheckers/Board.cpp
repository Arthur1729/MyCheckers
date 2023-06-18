#include "Board.h"
#include <iostream>
Board::Board(const sf::Vector2f& position, float cellSize, int rows, int columns)
    : m_position(position), m_cellSize(cellSize), m_rows(rows), m_columns(columns)
{
    // ������������� ����� �����
    m_cells.resize(rows * columns);
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            sf::RectangleShape& cell = m_cells[row * columns + col];

                cell.setSize(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(position.x + col * cellSize, position.y + row * cellSize);
                // ����a ���������� ����� ������� � ��������� ��������
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
    bool OneHitL = false;
    bool OneHitR = false;

    std::vector<sf::Vector2f> MovementVector;
    if (color == sf::Color::Red)
    {
        int newPosition1 = position.x - 135;
        int newPosition2 = position.y + 135; //y ��� ���� ���������
        int newPos3 = position.x + 135;
        int newPos4 = position.y + 135;// y ��� ���� ����������
       
        // �������� �� ��������� ������� �����/�����a
        for (sf::CircleShape* checker : checkers)
        {   // �������� �� ������� ��������� ����� ��� ����������� ����� �� �����
            sf::Vector2f chckPos = checker->getPosition();
            for (int i=0;i<m_cells.size()-1; i++)
            {
                if (m_cells[i].getGlobalBounds().contains(newPosition1, newPosition2) && m_cells[i].getGlobalBounds().contains(chckPos)) // ���� ���� ��������� �� ����������� ����. ���� � �������� � ��� �����(�������� ����������)
                {
                   
                    LeftCellIsFull = true; // ������������� ����� ������ ����, ��� ��� ������ �������� ����� ������ ���� �����
                    m_cells[i].setFillColor(sf::Color::Yellow);
                   
                    if (checker->getFillColor() == sf::Color::Green) 
                    {   
                        OneHitL = true;// ����� �����(�����) ����� �����, ���� ...
                        for (sf::CircleShape* checker1 : checkers)
                        {
                            for (auto& cell : m_cells)
                            {       
                                if (cell.getGlobalBounds().contains(newPosition1 - 135, newPosition2 + 135) && cell.getGlobalBounds().contains(checker1->getPosition()))
                                {   // ���� ����. ����� ����� ������� ����� ����� ������,�� ������ �������
                                    NextFromLeftCell = true;
                                    break;
                                }
                            }
                        }
                    }
                    
                    }

                if (m_cells[i].getGlobalBounds().contains(newPos3, newPos4) && m_cells[i].getGlobalBounds().contains(chckPos))//(�������� �����������)
                {
                    RightCellIsFull = true;
                    m_cells[i].setFillColor(sf::Color::Yellow);
                    if (checker->getFillColor() == sf::Color::Green)
                    {
                        OneHitR = true;// ����� ������(�����) ����� �����, ���� ...
                        for (sf::CircleShape* checker1 : checkers)
                        {   
                            for (auto& cell : m_cells)
                            {
                                if (cell.getGlobalBounds().contains(newPos3 + 135, newPos4 + 135) && cell.getGlobalBounds().contains(checker1->getPosition()))
                                {   // ���� ����. ������ ����� ����� ������� ����� ����� ������,�� ������ �������
                                    NextFromRightCell = true;
                                    break;
                                }
                            }
                        }
                    }
                   ;
                }

            }

        }   


        // ��������� ����� ������ ����� ��������� ��� ����
        for (auto& cell : m_cells)
        {
            if (OneHitL && !NextFromLeftCell && LeftCellIsFull && cell.getGlobalBounds().contains(newPosition1 - 135, newPosition2 + 135)) // �������� ������� ��� ������ (������� ������ � ���������� ��� ������������
            {
                MovementVector.push_back(sf::Vector2f(newPosition1 - 135, newPosition2 + 135));
                cell.setFillColor(sf::Color::Blue);



            }
            if (!NextFromRightCell && RightCellIsFull&&OneHitR)
            {
                for (auto& cell : m_cells)
                {
                    if (cell.getGlobalBounds().contains(newPos3 + 135, newPos4 + 135)) {
                        MovementVector.push_back(sf::Vector2f(newPos3 + 135, newPos4 + 135));
                        cell.setFillColor(sf::Color::Blue);

                    }
                }
            }
            
           
        }
        if (!MovementVector.empty()) return MovementVector;
    
            // ��������� ����� ������ ����� ��������� ��� ����
            for (auto& cell : m_cells)
            {   
                if (!LeftCellIsFull && cell.getGlobalBounds().contains(newPosition1, newPosition2))
                {
                    cell.setFillColor(sf::Color::Blue);
                    MovementVector.push_back(sf::Vector2f(newPosition1, newPosition2));
                }

            if (!RightCellIsFull && cell.getGlobalBounds().contains(newPos3, newPos4))
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
       
        for (sf::CircleShape* checker : checkers)
        {   // �������� �� ������� ��������� ����� ��� ����������� ����� �� �����
            sf::Vector2f chckPos = checker->getPosition();
            for (int i = 0; i < m_cells.size() - 1; i++)
            {
                if (m_cells[i].getGlobalBounds().contains(newPos1, newPos2) && m_cells[i].getGlobalBounds().contains(chckPos)) // ���� ���� ��������� �� ����������� ����. ���� � �������� � ��� �����(�������� ����������)
                {
                    LeftCellIsFull = true; // ������������� ����� ������ ����, ��� ��� ������ �������� ����� ������ ���� �����
                    m_cells[i].setFillColor(sf::Color::Yellow);

                    if (checker->getFillColor() == sf::Color::Red)
                    {
                        OneHitL = true;// ����� �����(������) ����� �����, ���� ...
                        for (sf::CircleShape* checker1 : checkers)
                        {
                            for (auto& cell : m_cells)
                            {
                                if (cell.getGlobalBounds().contains(newPos1 - 135, newPos2 - 135) && cell.getGlobalBounds().contains(checker1->getPosition()))
                                {   // ���� ����. ����� ����� ������� ����� ����� ������,�� ������ �������
                                    NextFromLeftCell = true;
                                    break;
                                }
                            }
                        }
                    }

                }

                if (m_cells[i].getGlobalBounds().contains(newPos3, newPos4) && m_cells[i].getGlobalBounds().contains(chckPos))//(�������� �����������)
                {
                    RightCellIsFull = true;
                    m_cells[i].setFillColor(sf::Color::Yellow);
                    if (checker->getFillColor() == sf::Color::Red)
                    {
                        OneHitR = true;// ����� ������(�����) ����� �����, ���� ...
                        for (sf::CircleShape* checker1 : checkers)
                        {
                            for (auto& cell : m_cells)
                            {
                                if (cell.getGlobalBounds().contains(newPos3 + 135, newPos4 - 135) && cell.getGlobalBounds().contains(checker1->getPosition()))
                                {   // ���� ����. ������ ����� ����� ������� ����� ����� ������,�� ������ �������
                                    NextFromRightCell = true;
                                    break;
                                }
                            }
                        }
                    }
                    
                }

            }

        }


        // ��������� ����� ������ ����� ��������� ��� ����
        for (auto& cell : m_cells)
        {
            if (OneHitL && !NextFromLeftCell && LeftCellIsFull && cell.getGlobalBounds().contains(newPos1 - 135, newPos2 - 135)) // �������� ������� ��� ������ (������� ������ � ���������� ��� ������������)
            {
                MovementVector.push_back(sf::Vector2f(newPos1 - 135, newPos2 - 135));
                cell.setFillColor(sf::Color::Blue);



            }
            if (!NextFromRightCell && RightCellIsFull && OneHitR)
            {
                for (auto& cell : m_cells)
                {
                    if (cell.getGlobalBounds().contains(newPos3 + 135, newPos4 - 135)) {
                        MovementVector.push_back(sf::Vector2f(newPos3 + 135, newPos4 - 135));
                        cell.setFillColor(sf::Color::Blue);

                    }
                }
            }


        }
        if (!MovementVector.empty()) return MovementVector;
        // ��������� ����� ������ ����� ��������� ��� ����
        for (auto& cell : m_cells)
        {
            if (!LeftCellIsFull && cell.getGlobalBounds().contains(newPos1, newPos2))
            {
                cell.setFillColor(sf::Color::Blue);
                MovementVector.push_back(sf::Vector2f(newPos1, newPos2));
            }

            if (!RightCellIsFull && cell.getGlobalBounds().contains(newPos3, newPos4))
            {
                cell.setFillColor(sf::Color::Blue);
                MovementVector.push_back(sf::Vector2f(newPos3, newPos4));

            }
        }
    }
    return MovementVector;
}

std::vector<sf::Vector2f> Board::CheckCells(sf::Vector2f& position)
{

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
    // ������������� ����� �����
    m_cells.resize(rows * columns);
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            sf::RectangleShape& cell = m_cells[row * columns + col];

            cell.setSize(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(position.x + col * cellSize, position.y + row * cellSize);
            // ����a ���������� ����� ������� � ��������� ��������
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
