#include "Game.h"
#include "Timer.h"
#include "Board.h"

Game::Game() : m_window(sf::VideoMode(1920, 1080), "MyCheckers", sf::Style::Fullscreen)
{

}

void Game::run()
{
    Timer* times = new Timer();
    bool Paused = false;

    sf::Vector2u windowSize = m_window.getSize();
    unsigned int windowWidth = windowSize.x;
    unsigned int windowHeight = windowSize.y;

    if (!Logo_font.loadFromFile("assets/Playfair_9pt_SemiCondensed-Bold.ttf"))
        std::cout << "Error";
    if (!Background_texture.loadFromFile("assets/Field.png"))
        std::cout << "Error";

    Logo_text.setFont(Logo_font);
    Logo_text.setString("MyCheckers!");
    Logo_text.setPosition(30, windowHeight / 15);
    Logo_text.setCharacterSize(108);
    sf::Color TextColor(136, 176, 75);
    Logo_text.setFillColor(TextColor);
    Logo_text.setStyle(sf::Text::Bold);

    Settings.setFont(Logo_font);
    Settings.setPosition(0, windowHeight - windowHeight / 3);
    Settings.setCharacterSize(108);
    Settings.setFillColor(TextColor);
    Settings.setStyle(sf::Text::Bold);
    Settings.setString("Settings");

    Background_sprite.setTexture(Background_texture);

    Board board(sf::Vector2f(windowSize.x / 2 - windowSize.x / 12, 0), 120, 8, 8);

    while (m_window.isOpen())
    {
        double mouseX = sf::Mouse::getPosition(m_window).x;
        double mouseY = sf::Mouse::getPosition(m_window).y;

        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                m_window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (times->RestartButton_sprite.getGlobalBounds().contains(mouseX, mouseY))
                    {
                        times->reset();
                        times->updateTime();
                    }

                    if (times->PauseButton_sprite.getGlobalBounds().contains(mouseX, mouseY))
                    {
                        Paused = !Paused;
                    }
                }
            }
        }

        m_window.clear();
        m_window.draw(Background_sprite);
        m_window.draw(Logo_text);
        m_window.draw(times->RestartButton_sprite);
        m_window.draw(times->timer);
        m_window.draw(times->PauseButton_sprite);
        m_window.draw(Settings);

        // Сдвиг позиции фигур шашек
        sf::Vector2f boardPosition = board.getPosition();
        float pieceOffsetX = board.getCellSize() / 2;
        float pieceOffsetY = board.getCellSize() / 2;
        sf::Vector2f piecePosition = boardPosition + sf::Vector2f(pieceOffsetX, pieceOffsetY);

        // Отрисовка фигур шашек на доске
        for (int i = 0; i < board.getRows(); i++)
        {
            for (int j = 0; j < board.getColumns(); j++)
            {
                sf::RectangleShape& piece = board.getCellShape(i, j);
                piece.setPosition(piecePosition);
                m_window.draw(piece);

                piecePosition.x += board.getCellSize();
            }
            piecePosition.x = boardPosition.x + pieceOffsetX;
            piecePosition.y += board.getCellSize();
        }

        m_window.display();
    }
}
