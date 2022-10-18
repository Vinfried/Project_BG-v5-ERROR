#include "Character.h"
#include "SDL.h"
#include <iostream>
#include "Vector2.h"

using namespace std;

Character::Character(Texture* characterTexture, Vector2 pos, int numberOfFrames)
{
	position = pos;
	objectTexture = characterTexture;
	this->numberOfFrames = numberOfFrames;
	velocity = Vector2().zero();
	movementAxis = Vector2().zero();
	maxSpeed = 100.0f;
}

Character::~Character()
{

}

void Character::draw(SDL_Renderer* renderer)
{
	SDL_Rect clip;
	clip.x = 0;
	clip.y = 0;
	clip.h = objectTexture->getImageHeight();
	clip.w = objectTexture->getImageWidth() / SDL_max(1, numberOfFrames);

	objectTexture->draw(renderer, position, &clip);
}

void Character::update(float deltaTime)
{
	velocity = movementAxis * maxSpeed;
	SDL_Log("%f", velocity.length());

	position += velocity * deltaTime;
}

void Character::processInput(Input *userInput)
{
}

void Character::setMovementAxis(Vector2 axis)
{
	movementAxis = axis;
}

Vector2 Character::getMovementAxis()
{
	return movementAxis;
}


