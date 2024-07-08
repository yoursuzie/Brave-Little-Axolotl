#pragma once
#include <SFML/Graphics.hpp>

sf::Vector2f operator>(sf::Vector2f&, int);

class Enemy
{
protected:
	float size;
	int damage;
	float speed;
	int direction;
	int phase;
	int maxPhase;
	int animationSpeed;
	float pointsGained;
	int bckgrHeight;
	int bckgrWidth;
	int margin;
	sf::Texture texture;
	sf::Sprite enemy;


public:
	Enemy(float aSize, int aDamage, float aSpeed);
	virtual void move();
	virtual void setPosition(sf::Vector2f aPos);
	void drawOnWindow(sf::RenderWindow &window);
	sf::FloatRect getBounds() const;
	float getPoints() const;
	float getSize() const;
	int getDamage() const;
};

