#pragma once
#include<SFML/Graphics.hpp>

#include <iostream>
class Game
{
public:
	Game();
	void run();
	sf::FloatRect rect(float x, float y, float b, float c);
	sf::RectangleShape rect(sf::Vector2f(float n,float b));
	sf::CircleShape* selectedChecker = nullptr;
	sf::CircleShape* hitChecker = nullptr;

protected:
	void drawChessboard(sf::RenderWindow& window);
	sf::RenderWindow m_window;

	sf::Texture settings_Texture;
	sf::Texture restartButton_Texture;
	sf::Sprite restartButton_Sprite;
	sf::Texture instruc_Texture;
	sf::Sprite settings_Sprite;
	sf::Sprite instuc_Sprite;
	bool isRectangleVisible;
	sf::RectangleShape rectangle;
};

