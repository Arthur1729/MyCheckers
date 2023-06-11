#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Board {
public:
    Board();
    void draw(sf::RenderWindow& window);

private:
    // ������������� ������� �����
    void initBoard(sf::RenderWindow& window);
    void createCheckerPiece(sf::RectangleShape& rect, sf::Color fill_color, sf::Vector2f position);

    // ��������� ������� ��������
    void initGameObjects();

    // ��������� ������� ������
    void initGameLogic();
    void resetGame();

    // ����� � ������ ������ ����� � ��������
    unsigned int mScreenWidth;
    unsigned int mScreenHeight;

    // ���������� ������ �� �����
    const unsigned int mNumSquaresPerRow = 8;

    // ��������� � � ������ ������
    float mStartX;
    float mSquareSize;

    // ������ �� �����
    sf::RectangleShape mWhiteSquareShape;
    sf::RectangleShape mBlackSquareShape;

    // ����� �� �����
    sf::RectangleShape mCheckerPieces[12];

    // ����� �����
    sf::Color mWhitePieceColor = sf::Color::White;
    sf::Color mBlackPieceColor = sf::Color::Red;

    // ������
    enum Player {
        None,
        White,
        Black
    };

    // ������ �����
    Player mCurrentPlayer = White;

    // ���������� ��� ������� ������ (���������� �������� �� ������)
    bool mIsCheckerSelected = false;
    int mSelectedCheckerIndex = -1;
    sf::Vector2f mSelectedCheckerOriginalPosition;

    // ��� ������ ���� �������� �� ������� ������ � ����� ����������� �����
    bool checkIfCheckerCanBeSelected(int checkerIndex);
    void selectChecker(int checkerIndex);
    void deselectChecker();
    bool checkIfSquareIsValidMove(sf::Vector2i clickedSquare);
    void moveSelectedChecker(sf::Vector2i clickedSquare);
    void switchPlayerTurn();
    bool checkIfMoveHasCapture(sf::Vector2i clickedSquare);
};

