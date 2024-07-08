#pragma once
#include <SFML/Graphics.hpp>
class HealthBar
{
private:
	sf::Texture healthTexture;
	sf::Sprite healthSprite;

public:
	HealthBar();
	void draw(sf::RenderWindow &window, int aHealth);
	void setPosition(sf::Vector2f aPos);


};

