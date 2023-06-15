#include "Game.h"

#include "Board.h"

Game::Game() : m_window(sf::VideoMode(1920, 1080), "MyCheckers", sf::Style::Fullscreen)
{

}

void Game::run()
{
 

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
                   
                }
            }
        }

        m_window.clear();
        m_window.draw(Background_sprite);
        m_window.draw(Logo_text);


      
        m_window.display();
    }
}
