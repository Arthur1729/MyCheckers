#pragma once
#include<SFML/Graphics.hpp>

#include <iostream>
class Game
{
public:
	Game();
	void run();

protected:
	void drawChessboard(sf::RenderWindow& window);
	sf::RenderWindow m_window;
	sf::Font Logo_font;
	sf::Text Logo_text;
	sf::Text Settings;
	sf::Texture Background_texture;
	sf::Sprite Background_sprite;
	
};

