#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Entity.h"


class Player : public Entity
{

private:

	/*MEMBERS*/
	bool thrusterOn;
	std::vector<Vector2> thrusterPoints;
	

public:
	
	/*CTOR*/
	Player();

	/*PUBLIC MEMBERS*/
	

	/*FUNCTIONS*/
	void Update(SDL_KeyboardEvent keyBoardEvent);
	void Render() override;
	void MoveForward();
	void RotateLeft(float angle);
	void RotateRight(float angle);
	void Thruster();
	void setThrusterOn(bool);
	
};

	

#endif // !_PLAYER_H_

