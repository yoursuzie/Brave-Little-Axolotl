#pragma once
#include <SFML/Audio.hpp>
class SoundEffects
{
private:
	sf::SoundBuffer bgmBuff;
	sf::SoundBuffer chaseBuff;
	sf::SoundBuffer damageBuff;
	sf::SoundBuffer eatBuff;
	sf::SoundBuffer deathBuff;
	sf::SoundBuffer bubbleBuff;
	sf::SoundBuffer lullabyBuff;
	sf::Sound bgm;
	sf::Sound chase;
	sf::Sound damage;
	sf::Sound eat;
	sf::Sound death;
	sf::Sound bubblePop;
	sf::Sound lullabybgm;

public:
	SoundEffects();
	void playBGM();
	void playChase();
	void playHit();
	void playEat();
	void playDeath();
	void playBubblePop();
	void playLullaby();
	
};

