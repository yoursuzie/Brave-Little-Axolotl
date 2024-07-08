#pragma once
#include <SFML/Graphics.hpp>

enum class type {HP,MULTPR,SHIELD};

class PowerUps
{
private:
	sf::Texture hpTxt;
	sf::Texture multprTxt;
	sf::Texture shieldTxt;
	sf::Sprite powerUp;
	int bckgrHeight;
	int bckgrWidth;
	bool isSpawned;
	type currentType;
	std::clock_t lastPowerUp;
	int cooldown;
	int margin;
	
public:
	PowerUps();
	void spawn();
	int checkCollision(sf::FloatRect);
	void draw(sf::RenderWindow &window);
	
};

