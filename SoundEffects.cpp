#include "SoundEffects.h"

SoundEffects::SoundEffects()
{
	bgmBuff.loadFromFile("assets/Sounds/bgm.ogg");
	bgm.setBuffer(bgmBuff);
	bgm.setLoop(true);

	chaseBuff.loadFromFile("assets/Sounds/SharkChase.ogg");
	chase.setBuffer(chaseBuff);
	chase.setLoop(true);
	chase.setVolume(25);

	damageBuff.loadFromFile("assets/Sounds/axolotlhurt.ogg");
	damage.setBuffer(damageBuff);
	damage.setVolume(200);

	eatBuff.loadFromFile("assets/Sounds/axolotlniom.ogg");
	eat.setBuffer(eatBuff);
	eat.setVolume(200);

	deathBuff.loadFromFile("assets/Sounds/axolotldead.ogg");
	death.setBuffer(deathBuff);
	death.setVolume(200);

	bubbleBuff.loadFromFile("assets/Sounds/bubble.ogg");
	bubblePop.setBuffer(bubbleBuff);
	bubblePop.setVolume(50);

	lullabyBuff.loadFromFile("assets/Sounds/littlelullaby.ogg");
	lullabybgm.setBuffer(lullabyBuff);
	lullabybgm.setLoop(true);
	lullabybgm.setVolume(80);

}

void SoundEffects::playBGM()
{
	if (chase.Playing) chase.stop();
	if (lullabybgm.Playing) lullabybgm.stop();
	bgm.play();
}

void SoundEffects::playChase()
{
	if (bgm.Playing) bgm.stop();
	if (lullabybgm.Playing) lullabybgm.stop();
	chase.play();
}

void SoundEffects::playHit()
{
	damage.play();
}

void SoundEffects::playEat()
{
	eat.play();
}

void SoundEffects::playDeath()
{
	death.play();
}

void SoundEffects::playBubblePop()
{
	bubblePop.play();
}

void SoundEffects::playLullaby()
{
	if (chase.Playing) chase.stop();
	if (bgm.Playing) bgm.stop();
	lullabybgm.play();
}
