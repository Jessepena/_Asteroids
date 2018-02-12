#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Vector_2.hpp"
#include "SDLEvent.hpp"


class Player
{

private:
	/*MEMBERS*/
	Vector2 position;

public:
	
	/*CTOR*/
	Player();

	/*PUBLIC MEMBERS*/
	bool thrusterOn;

	/*FUNCTIONS*/
	void Update(SDL_KeyboardEvent);
	void Render();
	void move(Vector2 position, SDL_KeyboardEvent event);
	void Warping();
	void MoveForward();
	void RotateLeft();
	void RotateRight();
	void Thruster();
	Vector2 getPosition();
};

	

#endif // !_PLAYER_H_

