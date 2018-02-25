#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Entity.h"
#include "Bullet.h"

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
	void Update(float) override;
	void Render() override;
	void MoveForward();
	void RotateLeft(float angle);
	void RotateRight(float angle);
	void Thruster();
	void setThrusterOn(bool);
	bool getThrusterOn();

	Bullet Shoot();
};

	
#endif // !_PLAYER_H_

