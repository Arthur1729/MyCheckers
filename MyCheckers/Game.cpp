#include "Game.h"

#include "Board.h"

Game::Game() : m_window(sf::VideoMode(1080, 1080), "MyCheckers", sf::Style::Titlebar | sf::Style::Close)
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
   

    sf::Vector2u windowSize = m_window.getSize();
    unsigned int windowWidth = windowSize.x;
    unsigned int windowHeight = windowSize.y;

    float cellSize = windowSize.x / 8;
    Board board(sf::Vector2f(0, 0), cellSize, 8, 8);


    sf::CircleShape firstChecker(windowSize.x /20);
    firstChecker.setFillColor(sf::Color::Red);
    firstChecker.setPosition(0, 135);
    sf::Color orange(255, 140, 0);
        
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
  
    
    bool mode = 0;
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                run();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {

                if (event.mouseButton.button == sf::Mouse::Left)
                {   double mouseX = sf::Mouse::getPosition(m_window).x;
                    double mouseY = sf::Mouse::getPosition(m_window).y;
                    if(selectedChecker==nullptr)
                    { 
                    for (sf::CircleShape* checker : checkers)
                    {   
                        if (checker->getGlobalBounds().contains(mouseX, mouseY) )
                        {
                            
                            MovementVector=board.ShowLegalMoves(checker->getPosition(),checker->getFillColor(),checker->getOutlineColor(),checkers);
                            selectedChecker = checker;
                            
                            break;
                           
                        }
                       }
                        
                    }
                    else
                    {
                        
                        if (selectedChecker->getGlobalBounds().contains(mouseX, mouseY))
                        {   
                            selectedChecker = nullptr;
                            
                            board.AfterSelection(m_window,sf::Vector2f(0,0));// �������� �����
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
                                            // ��� ����� �������������
                                           RemovablePos= sf::Vector2f (selectedChecker->getPosition().x + 135, selectedChecker->getPosition().y + 135);
                                        }
                                        else if (removeCheckerX > 0 && removeCheckerY < 0) {
                                            // a �������������, b �������������
                                             RemovablePos = sf::Vector2f(selectedChecker->getPosition().x + 135, selectedChecker->getPosition().y - 135);
                                        }
                                        else if (removeCheckerX < 0 && removeCheckerY > 0) {
                                            // a �������������, b �������������
                                             RemovablePos = sf::Vector2f(selectedChecker->getPosition().x - 135, selectedChecker->getPosition().y + 135);
                                        }
                                        else {
                                            // ��� ����� ������������� 
                                             RemovablePos = sf::Vector2f(selectedChecker->getPosition().x - 135, selectedChecker->getPosition().y - 135);
                                        }
                                        
                                        
                                         
                                        std::cout << "x: " << RemovablePos.x << " y: " << RemovablePos.y << "\n";
                                        for (sf::CircleShape* checker : checkers) {
                                            if (checker->getGlobalBounds().contains(RemovablePos)) {
                                                
                                                hitChecker = checker;
                                                break;
                                            }
                                        }

                                        // ���� ����� ���� �����, ������� � �� ������� checkers � ����������� ������
                                        if (hitChecker != nullptr) {
                                            auto it = std::find(checkers.begin(), checkers.end(), hitChecker);
                                            if (it != checkers.end()) {
                                                checkers.erase(it);
                                                
                                            }
                                        
                                    }
                                   }
                                    
                                    selectedChecker->setPosition(movement);
                                    
                                    selectedChecker->setPosition(movement);
                                   
                                    if (selectedChecker->getFillColor() == sf::Color::Red && selectedChecker->getPosition().y >= 945) selectedChecker->setOutlineColor(sf::Color::Green); //����� ��� ������� �����
                                    else if (selectedChecker->getFillColor() == sf::Color::Green && selectedChecker->getPosition().y <= 30) selectedChecker->setOutlineColor(sf::Color::Red);// ����� ��� ������� �����
                                    else selectedChecker->setOutlineColor(sf::Color(128, 128, 128, 200));

                                    selectedChecker = nullptr;
                                    board.AfterSelection(m_window, sf::Vector2f(0, 0)); // �������� �����
                                    break;
                                }
                            }}
                            else
                            {

                                selectedChecker->setOutlineColor(sf::Color(128, 128, 128, 200));
                                selectedChecker = nullptr;
                            }
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

        m_window.display();
    }
}
