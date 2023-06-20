#include "Game.h"
#include "Board.h"

Game::Game() : m_window(sf::VideoMode(1080, 1080), "Checkers", sf::Style::Titlebar | sf::Style::Close), isRectangleVisible(false)
{
  
}

void setChecker(sf::CircleShape* checker, int line, int part,int row, sf::Color color)
{
    int x = (part+(part+1)) * 135+10;
    if ((line-1) % 2 != 0)
        x-=135;
    
    
    int y = (line - 1) * 135+10;
    
    if (line > 3) y += 275;
   

    checker->setPosition(x, y);
    checker->setFillColor(color);
    checker->setOutlineColor(sf::Color(128, 128, 128, 200));
    checker->setOutlineThickness(10);
   }
void Game::run()
{
    bool isRedTurn = false;

    sf::Vector2u windowSize = m_window.getSize();
    unsigned int windowWidth = windowSize.x;
    unsigned int windowHeight = windowSize.y;

    float cellSize = windowSize.x / 8;
    Board board(sf::Vector2f(0, 0), cellSize, 8, 8);

    
    if (!settings_Texture.loadFromFile("assets/rules.png")) std::cout << "Problem with rule.png";
    if (!instruc_Texture.loadFromFile("assets/rulesPNG.png")) std::cout << "global error!!!!!!!";
    if (!restartButton_Texture.loadFromFile("assets/restart.jpg")) std::cout << "another global error!!!!!!!";
    settings_Texture.setSmooth(10);
    settings_Sprite.setTexture(settings_Texture);
    settings_Sprite.setPosition(550, 550);
    settings_Sprite.setScale(0.2f, 0.2f);
    
    
    instuc_Sprite.setTexture(instruc_Texture);
    instuc_Sprite.setPosition(windowSize.x / 2 - instruc_Texture.getSize().x/2, (windowWidth / 2)-instruc_Texture.getSize().y/2);
    
    restartButton_Sprite.setTexture(restartButton_Texture);
    restartButton_Sprite.setPosition(830, 550);
    restartButton_Sprite.setScale(0.5f, 0.5f);
 
    
    
   
    sf::Font font;
    if (!font.loadFromFile("assets/font.ttf")) {
        // Обработка ошибки загрузки шрифта
    }
    sf::Text text;
    text.setFont(font);
    text.setString(" ");
    text.setCharacterSize(28);
    text.setFillColor(sf::Color::White);
    text.setPosition(270, 565);

    sf::Text Win;
    Win.setFont(font);
    Win.setString(" ");
    Win.setCharacterSize(81);
    Win.setFillColor(sf::Color::White);
    Win.setPosition(windowSize.x/2-450, windowSize.y/2-135);

   
    std::vector<sf::CircleShape*> checkers;

    sf::CircleShape checker1W(windowSize.x / 20);
    checkers.push_back(&checker1W);
    sf::CircleShape checker2W(windowSize.x / 20);
    checkers.push_back(&checker2W);
    sf::CircleShape checker3W(windowSize.x / 20);
    checkers.push_back(&checker3W);
    sf::CircleShape checker4W(windowSize.x / 20);
    checkers.push_back(&checker4W);
    sf::CircleShape checker5W(windowSize.x / 20);
    checkers.push_back(&checker5W);
    sf::CircleShape checker6W(windowSize.x / 20);
    checkers.push_back(&checker6W);
    sf::CircleShape checker7W(windowSize.x / 20);
    checkers.push_back(&checker7W);
    sf::CircleShape checker8W(windowSize.x / 20);
    checkers.push_back(&checker8W);
    sf::CircleShape checker9W(windowSize.x / 20);
    checkers.push_back(&checker9W);
    sf::CircleShape checker10W(windowSize.x / 20);
    checkers.push_back(&checker10W);
    sf::CircleShape checker11W(windowSize.x / 20);
    checkers.push_back(&checker11W);
    sf::CircleShape checker12W(windowSize.x / 20);
    checkers.push_back(&checker12W);

    sf::CircleShape checker1B(windowSize.x / 20);
    checkers.push_back(&checker1B);
    sf::CircleShape checker2B(windowSize.x / 20);
    checkers.push_back(&checker2B);
    sf::CircleShape checker3B(windowSize.x / 20);
    checkers.push_back(&checker3B);
    sf::CircleShape checker4B(windowSize.x / 20);
    checkers.push_back(&checker4B);
    sf::CircleShape checker5B(windowSize.x / 20);
    checkers.push_back(&checker5B);
    sf::CircleShape checker6B(windowSize.x / 20);
    checkers.push_back(&checker6B);
    sf::CircleShape checker7B(windowSize.x / 20); 
    checkers.push_back(&checker7B);
    sf::CircleShape checker8B(windowSize.x / 20);
    checkers.push_back(&checker8B);
    sf::CircleShape checker9B(windowSize.x / 20);
    checkers.push_back(&checker9B);
    sf::CircleShape checker10B(windowSize.x / 20);
    checkers.push_back(&checker10B);
    sf::CircleShape checker11B(windowSize.x / 20);
    checkers.push_back(&checker11B);
    sf::CircleShape checker12B(windowSize.x / 20);
    checkers.push_back(&checker12B);
    
    
    for (int i = 0; i < checkers.size() ; i++)
    {

        sf::CircleShape* checker = checkers[i];
        if (i < 4) setChecker(checker, 1, i,0, sf::Color (255, 0, 0, 255));
        else if (i < 8) setChecker(checker, 2, i-4,1, sf::Color(255, 0, 0, 255));
        else if (i < 12) setChecker(checker, 3, i-8,2, sf::Color(255, 0, 0, 255));
        else if (i < 16) setChecker(checker, 4, i-12,0, sf::Color (0, 255, 0, 255));
        else if (i < 20) setChecker(checker, 5, i-16,1, sf::Color(0, 255, 0, 255));
        else setChecker(checker, 6, i-20,2, sf::Color(0, 255, 0, 255));
      
    }
  
    int WhiteCheckers = 12;
    int BlackCheckers = 12;
    bool whiteWin = false;
    bool blackWin = false;
    std::vector<sf::Vector2f> MovementVector;
    while (m_window.isOpen())
    {
        
        sf::Event event;
        
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                m_window.close();

            }
            if (WhiteCheckers == 1) blackWin = true;
            else if (BlackCheckers == 1) whiteWin = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                run();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                
                if (event.mouseButton.button == sf::Mouse::Left)
                {   double mouseX = sf::Mouse::getPosition(m_window).x;
                    double mouseY = sf::Mouse::getPosition(m_window).y;
                    
                    if (!isRectangleVisible && settings_Sprite.getGlobalBounds().contains(mouseX, mouseY))
                    {
                        isRectangleVisible = true;
                    }
                    else isRectangleVisible = false;
                    if (restartButton_Sprite.getGlobalBounds().contains(mouseX, mouseY)) run();
                    if(selectedChecker==nullptr )
                    { 
                    for (sf::CircleShape* checker : checkers)
                    {   
                        if (checker->getGlobalBounds().contains(mouseX, mouseY) )
                        {   
                            if((isRedTurn && checker->getFillColor() == sf::Color::Red) ||
                                (!isRedTurn && checker->getFillColor() == sf::Color::Green)){ 
                            MovementVector=board.ShowLegalMoves(checker->getPosition(),checker->getFillColor(),checker->getOutlineColor(),checkers,0);
                            selectedChecker = checker;
                            
                            break;}
                           
                        }
                       }
                        
                    } 
                    
                    else if(selectedChecker!=nullptr )
                    {  
                        if (selectedChecker->getGlobalBounds().contains(mouseX, mouseY))
                        {   
                            selectedChecker = nullptr;
                            
                            board.AfterSelection(m_window,sf::Vector2f(0,0));// Сбросить выбор
                        }
                        else
                        {
                            if (!MovementVector.empty())
                            {
                            
                            for (const sf::Vector2f& movement : MovementVector)
                            {
                                sf::FloatRect destinationRect(selectedChecker->getGlobalBounds());
                                destinationRect.left = movement.x;
                                destinationRect.top = movement.y;

                                if (destinationRect.contains(mouseX, mouseY))
                                {
                                    if (abs(movement.x - selectedChecker->getPosition().x) > 140 && abs(movement.y - selectedChecker->getPosition().y))
                                    {
                                       
                                        sf::Vector2f RemovablePos;
                                        sf::CircleShape* hitChecker = nullptr; 
                                        float removeCheckerX=movement.x - selectedChecker->getPosition().x;
                                        float removeCheckerY=movement.y - selectedChecker->getPosition().y;
                                        
                                        if (removeCheckerX > 0 && removeCheckerY > 0) {
                                            // Оба числа положительные
                                           RemovablePos= sf::Vector2f (selectedChecker->getPosition().x + 135, selectedChecker->getPosition().y + 135);
                                        }
                                        else if (removeCheckerX > 0 && removeCheckerY < 0) {
                                            // a положительное, b отрицательное
                                             RemovablePos = sf::Vector2f(selectedChecker->getPosition().x + 135, selectedChecker->getPosition().y - 135);
                                        }
                                        else if (removeCheckerX < 0 && removeCheckerY > 0) {
                                            // a отрицательное, b положительное
                                             RemovablePos = sf::Vector2f(selectedChecker->getPosition().x - 135, selectedChecker->getPosition().y + 135);
                                        }
                                        else {
                                            // Оба числа отрицательные 
                                             RemovablePos = sf::Vector2f(selectedChecker->getPosition().x - 135, selectedChecker->getPosition().y - 135);
                                        }
                                        
                                        
                                         
                                       
                                        for (sf::CircleShape* checker : checkers) {
                                            if (checker->getGlobalBounds().contains(RemovablePos)) {
                                                
                                                hitChecker = checker;
                                                if (hitChecker->getFillColor() == sf::Color::Red) WhiteCheckers--;
                                                else BlackCheckers--;
                                                break;
                                            }
                                        }

                                        // Если пешка была сбита, удаляем её из вектора checkers и освобождаем память
                                        if (hitChecker != nullptr) {
                                            auto it = std::find(checkers.begin(), checkers.end(), hitChecker);
                                            if (it != checkers.end()) 
                                            {
                                                checkers.erase(it);
                                                
                                            }
                                        
                                    }
                                   }
                                    
                             
                                    
                                    selectedChecker->setPosition(movement);
                                   
                                    if (selectedChecker->getFillColor() == sf::Color::Red && selectedChecker->getPosition().y >= 945) selectedChecker->setOutlineColor(sf::Color::Green); //Дамка для красных фигур
                                    else if (selectedChecker->getFillColor() == sf::Color::Green && selectedChecker->getPosition().y <= 30) selectedChecker->setOutlineColor(sf::Color::Red);// Дамка для зеленых фигур
                                    isRedTurn=(isRedTurn == 1) ? 0 : 1;
                                    selectedChecker = nullptr;
                                    board.AfterSelection(m_window, sf::Vector2f(0, 0)); // Сбросить выбор
                                    break;
                                }
                            }}
                            else selectedChecker = nullptr;
                            
                                
                            
                        }
                    }
                   
                }
            }
        }

        m_window.clear();
        board.draw(m_window);
        for (sf::CircleShape* checker : checkers)
        {
          
               
            m_window.draw(*checker);
        }
        m_window.draw(settings_Sprite);
        
        if (isRedTurn)
        {
            text.setFillColor(sf::Color::Red);
            text.setString("Red turn");
        }
        else
        {
            text.setFillColor(sf::Color(0, 100, 0));
            text.setString("Green turn");
        }
        m_window.draw(text);
        m_window.draw(restartButton_Sprite);
        if(isRectangleVisible) m_window.draw(instuc_Sprite);
        if (whiteWin)
        {
            Win.setString("Red checkers - Winners");
            Win.setFillColor(sf::Color::Red);
            m_window.draw(Win);
        }
        else if (blackWin)
        {
            Win.setString("Green checkers - Winners");
            Win.setFillColor(sf::Color(0, 100, 0));
            m_window.draw(Win);
        }
        
        m_window.display();
    }
}


