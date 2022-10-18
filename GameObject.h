#pragma once

#include"SDL.h"
#include "Texture.h"
#include "Vector2.h"
#include "Input.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void draw(SDL_Renderer* renderer);
	virtual void update(float deltaTime);
	virtual void processInput(Input *userInput);

protected:
	//position for the game object to display
	Vector2 position;
	//the objects texture
	Texture* objectTexture;
};

