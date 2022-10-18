#include "Player.h"
#include "SDL.h"

Player::Player(Texture* characterTexture, Vector2 pos, int numberOfFrames)
	:Character::Character(characterTexture, pos, numberOfFrames)
{

}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	Character::update(deltaTime);
}

void Player::processInput(Input *userInput)
{
	float movementX = 0.0f;
	float movementY = 0.0f;

	if (userInput->isKeyDown(SDL_SCANCODE_W)) {
		movementY = -1.0f;
	}

	if (userInput->isKeyDown(SDL_SCANCODE_S)) {
		movementY = 1.0f;
	}

	if (userInput->isKeyDown(SDL_SCANCODE_A)) {
		movementX = -1.0f;
	}
	
	if (userInput->isKeyDown(SDL_SCANCODE_D)) {
		movementX = 1.0f;
	}

	setMovementAxis(Vector2(movementX, movementY));
}


