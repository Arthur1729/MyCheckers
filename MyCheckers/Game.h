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
protected:
	void drawChessboard(sf::RenderWindow& window);
	sf::RenderWindow m_window;
	sf::Font Logo_font;
	sf::Text Logo_text;
	sf::Text Settings;
	sf::Texture Background_texture;
	sf::Sprite Background_sprite;
	bool m_checkerSelected;
};

