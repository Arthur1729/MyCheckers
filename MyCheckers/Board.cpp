#include "Board.h"

Board::Board() {}

// Нарисовать игровую доску
void Board::draw(sf::RenderWindow& m_window) {
    initBoard(m_window);

    // Рисуем клетки на доске
    for (int row = 0; row < mNumSquaresPerRow; ++row) {
        for (int col = 0; col < mNumSquaresPerRow; ++col) {
            sf::RectangleShape square;
            square.setSize(sf::Vector2f(mSquareSize, mSquareSize));
            square.setPosition(mStartX + col * mSquareSize, (row * mSquareSize));
            if ((row + col) % 2 == 0) {
                square.setFillColor(sf::Color::White);
            }
            else {
                square.setFillColor(sf::Color::Black);
            }
            m_window.draw(square);
        }
    }

    // Рисуем шашки на доске
    for (int i = 0; i < 12; ++i) {
        m_window.draw(mCheckerPieces[i]);
    }
}

// Создаем шашки на доске
void Board::createCheckerPiece(sf::RectangleShape& rect, sf::Color fill_color, sf::Vector2f position) {
    rect.setSize(sf::Vector2f(mSquareSize * 0.4, mSquareSize * 0.4));
    rect.setFillColor(fill_color);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(3.f);
    rect.setOrigin(rect.getSize() / 2.f);
    rect.setPosition(position);
}

// Инициализируем свойства доски
void Board::initBoard(sf::RenderWindow& m_window) {
    mScreenWidth = m_window.getSize().x;
    mScreenHeight = m_window.getSize().y;
    mStartX = (mScreenWidth / 3) + (mScreenWidth * 0.66) / 12;
    mSquareSize = (mScreenWidth / mNumSquaresPerRow) * 0.55;
    mBlackSquareShape.setSize(sf::Vector2f(mSquareSize, mSquareSize));
    mBlackSquareShape.setFillColor(sf::Color::Yellow);
    mWhiteSquareShape.setSize(sf::Vector2f(mSquareSize, mSquareSize));
    mWhiteSquareShape.setFillColor(sf::Color::Red);
}

// Устанавливаем игровые объекты
void Board::initGameObjects() {}

// Настраиваем игровую логику
void Board::initGameLogic() {}

// Сбрасываем игру
void Board::resetGame() {}

// Выбор шашки
bool Board::checkIfCheckerCanBeSelected(int checkerIndex) {
    // TODO: реализовать метод
    return true;
}
void Board::selectChecker(int checkerIndex) {}
void Board::deselectChecker() {}

// Движение шашки
bool Board::checkIfSquareIsValidMove(sf::Vector2i clickedSquare) {
    // TODO: реализовать метод
    return true;
}
void Board::moveSelectedChecker(sf::Vector2i clickedSquare) {}

// Смена игрока
void Board::switchPlayerTurn() {}

// Проверяем, было ли захвачено
bool Board::checkIfMoveHasCapture(sf::Vector2i clickedSquare) {
    // TODO: реализовать метод
    return false;
}
