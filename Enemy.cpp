#include "Enemy.h"

Enemy::Enemy(Texture* characterTexture, Vector2 pos, int numberOfFrames)
:Character::Character(characterTexture, pos, numberOfFrames)
{

}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
	Character::update(deltaTime);

	setMovementAxis(Vector2(0.0f, 1.0f));
}

void Enemy::processInput(Input* userInput)
{
}


