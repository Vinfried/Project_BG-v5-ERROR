#include "Game.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Collectible.h"
#include "Orbs.h"
#include "Input.h"
#include <iostream>
#include <vector>

using namespace std;

//constructor
Game::Game()
{
	//set the SDL Window and Renderer to null in case it has memory
	sdlWindow = nullptr;
	sdlRenderer = nullptr;

	//Initialise the subsystem in the SDL2 Framework
	if (SDL_InitSubSystem(SDL_INIT_EVERYTHING) != 0) {

		bIsGameOver = true;
		//if failed to initialise the subsystem, tell us on console
		cout << "Initialise SDL - failed" << endl;
	}
	else {
		//enable game loop
		bIsGameOver = false;
		//if the subsystem succesfully initialises
		cout << "initialise SDL - success" << endl;
	}

}

//deconstructor
Game::~Game()
{

}

bool Game::Start()
{
	// create the SDL renderer and define it
	sdlRenderer = SDL_CreateRenderer(sdlWindow, 0, -1);

	lastUpdatedTime = SDL_GetTicks();
	
	//make sure the renderer worked
	if (sdlRenderer != nullptr) {
		cout << "Create Renderer - success" << endl;

		//Start detecting input
		userInput = new Input();

		//initialise the player textertexture
		playerTexture = new Texture();
		//load the texture
		playerTexture->loadImageFromFile("Assets/hero_spritesheet_50x37_109.png", sdlRenderer);
		//construct the player as a character
		Player* playerCharacter = new Player(playerTexture, Vector2(0,0), 109);
		gameObjects.push_back(playerCharacter);

		//intialised the enemy texture
		enemyTexture = new Texture();
		//load the player texture
		enemyTexture->loadImageFromFile("Assets/goblin-spritesheet-65x35-28.png", sdlRenderer);
		

		//construct the enemy as a Enemy using the enemy texture
		Enemy* enemyCharacter = new Enemy(enemyTexture, Vector2(0,0), 28);
		gameObjects.push_back(enemyCharacter);
		//construct the second enemy using the same texture
		Enemy* enemyCharacter2 = new Enemy(enemyTexture, Vector2(0,0), 28);
		gameObjects.push_back(enemyCharacter2);
		//initialise collectible(orb) texture
		orbsTexture = new Texture();
		//load the orb texture
		orbsTexture->loadImageFromFile("Assets/rotating_orbs_128x32-4.png", sdlRenderer);
		//construct the orb as a collectible
		Orbs* orb = new Orbs(orbsTexture,Vector2(0,0), 4);
		gameObjects.push_back(orb);

		return true;
	}
	
	cout << "Create Renderer - failed" << endl;

	return false;
}

void Game::ProcessInput()
{
	userInput->updateInput(bIsGameOver);

	//cycle through all gameobjects and run their input
	for (unsigned int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->processInput(userInput);
	}
}

void Game::Update()
{
	//Process any changes to the game
	//int seconds = SDL_GetTicks() / 1000;

	//how long has it been since the last frame updated in milliseconds
	unsigned int tick = SDL_GetTicks() - lastUpdatedTime;

	//change the tick to seconds
	float deltaTime = tick / 1000.0f;

	//Refresh the last update time
	lastUpdatedTime = SDL_GetTicks();

	if (userInput->isKeyDown(SDL_SCANCODE_W)) {
		SDL_Log("Pressing the W key");
	}
	//cycle through all gameobjects and run their update
	for (unsigned int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->update(deltaTime);
	}
}

void Game::Draw()
{
	//set the draw color
	SDL_SetRenderDrawColor(sdlRenderer, 15, 15, 15, 255);

	//clear the renderer
	SDL_RenderClear(sdlRenderer);


	//cycle through all gameobjects and run their draw
	for (unsigned int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->draw(sdlRenderer);
	}

	SDL_RenderPresent(sdlRenderer);
}

void Game::Run(const char* title, int width, int height, bool fullscreen)
{
	//define the creation flag
	int creationFlag = 0;

	//if fullscreen is set to false then set to window mode
	if (!fullscreen) {
		creationFlag = SDL_WINDOW_SHOWN;

	}

	else {
		creationFlag = SDL_WINDOW_FULLSCREEN;
	}

	sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, creationFlag);

	//check if the SDL window work
	////create the renderer and start game loop
	if (sdlWindow != nullptr && Start()) {
		cout << "Create window - success" << endl;

		//run the loop
		while (!bIsGameOver) {
			//check for the player input
			ProcessInput();

			//process any changes that were made either by input or game code
			Update();

			//draw everything to screen
			Draw();

		}
	}

	//debug or was exited
	cout << "Create Window - failed or was exited" << endl;

	Shutdown();
	Destroy();


}

void Game::Shutdown()
{
}

void Game::Destroy()
{
	//dealocate the window
	SDL_DestroyWindow(sdlWindow);

	//dealocate the renderer
	SDL_DestroyRenderer(sdlRenderer);

	//shutdown the SDL framework
	SDL_Quit();

}
