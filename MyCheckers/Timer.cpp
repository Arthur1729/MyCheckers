#include "Timer.h"
#include "Game.h"
Timer::Timer() 
{
	if (!TimerFont.loadFromFile("assets/Playfair_9pt_SemiCondensed-Bold.ttf"))
		std::cout << "Error";
	
	sf::Color TextColor(136, 176, 75);
	timer.setFont(TimerFont);
	timer.setPosition(20,250);
	timer.setCharacterSize(72);
	timer.setFillColor(TextColor);
	timer.setStyle(sf::Text::Bold);
	timer.setString("10:01");


	if (!RestartButton_texture.loadFromFile("assets/restartButton.png"))
		std::cout << "Error";
	RestartButton_sprite.setTexture(RestartButton_texture);
	RestartButton_sprite.setPosition(3, 1080/2);
	RestartButton_sprite.setScale(0.2f, 0.2f);

	if (!PauseButton_texture.loadFromFile("assets/Pause.png"))
		std::cout << "Error";
	PauseButton_sprite.setTexture(PauseButton_texture);
	
	
	PauseButton_sprite.setPosition(RestartButton_sprite.getPosition().x + 200, 1080 / 2);
	PauseButton_sprite.setScale(0.2f, 0.2f);
	
}

void Timer::updateTime()
{
	int minutes = int(collectedTime) / 60;
	int seconds = int(collectedTime) % 60;

	std::string minutesStr = std::to_string(minutes);
	if (minutesStr.length() == 1) 
		minutesStr = "0" + minutesStr;

	std::string secondsStr = std::to_string(seconds);
	if (secondsStr.length() == 1) 
		secondsStr = "0" + secondsStr;
	
	timer.setString("Time: " + minutesStr + ":" + secondsStr);
}

void Timer::collectTime()
{
	collectedTime += clock.getElapsedTime().asSeconds();
	clock.restart();
	updateTime();
}

void Timer::reset()
{
	collectedTime = 0;
	updateTime();
}


