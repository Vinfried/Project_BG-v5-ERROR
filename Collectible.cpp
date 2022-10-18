#include "Collectible.h"
#include "SDL.h"
#include <iostream>

Collectible::Collectible(Texture* collectibleTexture, Vector2 pos, int numberOfFrames)
{
	position = pos;
	objectTexture = collectibleTexture;
	this->numberOfFrames = numberOfFrames;
}

Collectible::~Collectible()
{
}

void Collectible::draw(SDL_Renderer* renderer)
{
	SDL_Rect clip;
	clip.x = 0;
	clip.y = 0;
	clip.h = objectTexture->getImageHeight();
	clip.w = objectTexture->getImageWidth() / SDL_max(1, numberOfFrames);

	objectTexture->draw(renderer, position, &clip);
}

void Collectible::update(float deltaTime)
{
}
