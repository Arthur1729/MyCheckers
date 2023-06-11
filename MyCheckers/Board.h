#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Board {
public:
    Board();
    void draw(sf::RenderWindow& window);

private:
    // Инициализация свойств доски
    void initBoard(sf::RenderWindow& window);
    void createCheckerPiece(sf::RectangleShape& rect, sf::Color fill_color, sf::Vector2f position);

    // Установка игровых объектов
    void initGameObjects();

    // Настройка игровой логики
    void initGameLogic();
    void resetGame();

    // Длина и ширина модели доски в пикселях
    unsigned int mScreenWidth;
    unsigned int mScreenHeight;

    // Количество клеток на доске
    const unsigned int mNumSquaresPerRow = 8;

    // Начальный Х и размер клетки
    float mStartX;
    float mSquareSize;

    // Клетки на доске
    sf::RectangleShape mWhiteSquareShape;
    sf::RectangleShape mBlackSquareShape;

    // Шашки на доске
    sf::RectangleShape mCheckerPieces[12];

    // Цвета шашек
    sf::Color mWhitePieceColor = sf::Color::White;
    sf::Color mBlackPieceColor = sf::Color::Red;

    // Игроки
    enum Player {
        None,
        White,
        Black
    };

    // Ткущий игрок
    Player mCurrentPlayer = White;

    // Переменные для игровой логики (необходимо изменить на методы)
    bool mIsCheckerSelected = false;
    int mSelectedCheckerIndex = -1;
    sf::Vector2f mSelectedCheckerOriginalPosition;

    // Все методы ниже отвечают за игровую логику и будут реализованы позже
    bool checkIfCheckerCanBeSelected(int checkerIndex);
    void selectChecker(int checkerIndex);
    void deselectChecker();
    bool checkIfSquareIsValidMove(sf::Vector2i clickedSquare);
    void moveSelectedChecker(sf::Vector2i clickedSquare);
    void switchPlayerTurn();
    bool checkIfMoveHasCapture(sf::Vector2i clickedSquare);
};

