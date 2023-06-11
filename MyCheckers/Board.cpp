#include "Board.h"

Board::Board() {}

// ���������� ������� �����
void Board::draw(sf::RenderWindow& m_window) {
    initBoard(m_window);

    // ������ ������ �� �����
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
            std::cout << "Hellp";
            m_window.draw(square);
        }
    }

    // ������ ����� �� �����
    for (int i = 0; i < 12; ++i) {
        m_window.draw(mCheckerPieces[i]);
    }
}

// ������� ����� �� �����
void Board::createCheckerPiece(sf::RectangleShape& rect, sf::Color fill_color, sf::Vector2f position) {
    rect.setSize(sf::Vector2f(mSquareSize * 0.4, mSquareSize * 0.4));
    rect.setFillColor(fill_color);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(3.f);
    rect.setOrigin(rect.getSize() / 2.f);
    rect.setPosition(position);
}

// �������������� �������� �����
void Board::initBoard(sf::RenderWindow& m_window) {
    mScreenWidth = m_window.getSize().x;
    mScreenHeight = m_window.getSize().y;
    mStartX = (mScreenWidth / 3) + (mScreenWidth * 0.66) / 12;
    mSquareSize = (mScreenWidth / mNumSquaresPerRow) * 0.55;
    mBlackSquareShape.setSize(sf::Vector2f(mSquareSize, mSquareSize));
    mBlackSquareShape.setFillColor(sf::Color::Black);
    mWhiteSquareShape.setSize(sf::Vector2f(mSquareSize, mSquareSize));
    mWhiteSquareShape.setFillColor(sf::Color::White);
}

// ������������� ������� �������
void Board::initGameObjects() {}

// ����������� ������� ������
void Board::initGameLogic() {}

// ���������� ����
void Board::resetGame() {}

// ����� �����
bool Board::checkIfCheckerCanBeSelected(int checkerIndex) {
    // TODO: ����������� �����
    return true;
}
void Board::selectChecker(int checkerIndex) {}
void Board::deselectChecker() {}

// �������� �����
bool Board::checkIfSquareIsValidMove(sf::Vector2i clickedSquare) {
    // TODO: ����������� �����
    return true;
}
void Board::moveSelectedChecker(sf::Vector2i clickedSquare) {}

// ����� ������
void Board::switchPlayerTurn() {}

// ���������, ���� �� ���������
bool Board::checkIfMoveHasCapture(sf::Vector2i clickedSquare) {
    // TODO: ����������� �����
    return false;
}
