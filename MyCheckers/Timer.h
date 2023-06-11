#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Timer
{
public:
	Timer();
	void collectTime();
	void reset();
	void draw();	
	void updateTime();
	void ButtonPressed();
	sf::Text timer;
	sf::Texture RestartButton_texture;
	sf::Sprite RestartButton_sprite;
	sf::Texture PauseButton_texture;
	sf::Sprite PauseButton_sprite;
	sf::FloatRect collisionOfRstBttn;
	float collectedTime=1;
private:
	
	sf::Clock clock;
	sf::Font TimerFont;
	
};

