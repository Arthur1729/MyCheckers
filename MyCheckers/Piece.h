#include <SFML / Graphics.hpp>

enum class PieceType { Red, Black };
enum class PieceStatus { Regular, King };

class Piece : public sf::RectangleShape {
public:
    //  онструктор класса
    Piece(PieceType pieceType, PieceStatus pieceStatus, sf::Vector2f position, float pieceSize);

    // ћетоды дл€ установки и получени€ текущей позиции фигуры
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    // ћетоды дл€ проверки текущего типа и статуса фигуры
    PieceType getType();
    PieceStatus getStatus();

private:
    sf::Vector2f m_position;
    PieceType m_type;
    PieceStatus m_status;
};
