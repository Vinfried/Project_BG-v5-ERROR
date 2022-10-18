#include "GameObject.h"
#include "Vector2.h"

GameObject::GameObject()
{
	position = Vector2(0, 0);
	objectTexture = nullptr;
}

GameObject::~GameObject()
{
}

void GameObject::draw(SDL_Renderer* renderer)
{
}

void GameObject::update(float deltaTime)
{
}

void GameObject::processInput(Input *userInput)
{
}
