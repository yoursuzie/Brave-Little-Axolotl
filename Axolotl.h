#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>


enum axoState {IDLE, SWIMMING, IDLETOSWIM, SWIMTOIDLE, HURTSWIMMING, HURTIDLE, DYING, FALLINGASLEEP, SLEEPING};

class Axolotl
{
private:
	sf::Texture idle;
	sf::Texture swimming;
	sf::Texture idletoswim;
	sf::Texture swimtoidle;
	sf::Texture hurtSwimming;
	sf::Texture hurtIdle;
	sf::Texture dying;
	sf::Texture preparingToSleep;
	sf::Texture sleeping;
	sf::Texture shieldTxt;
	sf::Sprite bubbleShield;
	sf::Sprite axolotl;
	axoState state;
	int speed;
	float size;
	int phase;
	int maxPhase;
	int health;
	int score;
	int animationSpeed;
	bool changingToIdle;
	bool changingToSwim;
	int rectX;
	int rectY;
	bool hasShield;
	bool isHurt;
	sf::Vector2f shieldMovement;

public:
	Axolotl(float aSize, int aSpeed, int aHealth);
	void move(sf::Vector2f aPos);
	void drawOnWindow(sf::RenderWindow& window);
	void setPosition(sf::Vector2f aPos);
	void setPosition(float, float);
	sf::Vector2f getPosition() const;
	int getSpeed() const;
	sf::FloatRect getBounds() const;
	void hit(int aDamage);
	int getHealth() const;
	float getSize() const;
	void addPoints(float);
	void heal();
	void toggleShield(bool);
	bool shieldDeployed();
	void goToSleep();
	void moveToBottom();
};

