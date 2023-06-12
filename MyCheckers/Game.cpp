    #include "Game.h"
    #include "Timer.h"
    #include "Board.h"


    Game::Game() : m_window(sf::VideoMode(1920, 1080), "MyCheckers", sf::Style::Fullscreen)
    {

    }

    void Game::run() // Основной метод программы
    {
        Timer* times = new Timer();
        // Создание объекта класса Timer
        bool Paused = false;
    
        sf::Vector2u windowSize = m_window.getSize(); // Получение размеров окна
        unsigned int windowWidth = windowSize.x;
        unsigned int windowHeight = windowSize.y;
        Board board(windowWidth, windowHeight);
        if (!Logo_font.loadFromFile("assets/Playfair_9pt_SemiCondensed-Bold.ttf"))
            std::cout << "Error";
        if (!Background_texture.loadFromFile("assets/Field.png"))
            std::cout << "Error";

        // Название
        Logo_text.setFont(Logo_font);
        Logo_text.setString("MyCheckers!");
        Logo_text.setPosition(30, windowHeight / 15);
        Logo_text.setCharacterSize(108);
        sf::Color TextColor(136, 176, 75);
        Logo_text.setFillColor(TextColor);
        Logo_text.setStyle(sf::Text::Bold);

        // Настройки
        Settings.setFont(Logo_font);
        Settings.setPosition(0, windowHeight - windowHeight / 3);
        Settings.setCharacterSize(108);
        Settings.setFillColor(TextColor);
        Settings.setStyle(sf::Text::Bold);
        Settings.setString("Settings");

        // Фон
        Background_sprite.setTexture(Background_texture);




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

            for (auto& blackPiece : board.m_blackPieces)
            {
                m_window.draw(blackPiece);
            }

            for (auto& redPiece : board.m_redPieces)
            {
                m_window.draw(redPiece);
            }

            // Вызываем функцию для сбора времени
            if (!Paused)
                times->collectTime();

            m_window.display();
        }
    }