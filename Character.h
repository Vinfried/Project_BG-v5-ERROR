#pragma once
#include "GameObject.h"
#include "SDL.h"
#include "Vector2.h"

class Character :
    public GameObject
{
public:
    Character(Texture* characterTexture, Vector2 pos, int numberOfFrames = 1);
    ~Character();

    void draw(SDL_Renderer* renderer) override;
    virtual void update(float deltaTime) override;
    virtual void processInput(Input *userInput) override;

protected:
    float maxSpeed;

    void setMovementAxis(Vector2 axis);
    Vector2 getMovementAxis();

private:
    unsigned int numberOfFrames;

    //velocity is the true representation of speed, this will gave a x and y value
    Vector2 velocity;
    //this is going to detect input and move our character based on it's direction
    //make sure the number is normally between 0 and 1
    Vector2 movementAxis;
};

