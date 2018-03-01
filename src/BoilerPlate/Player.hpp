#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Entity.h"
#include "Bullet.h"

class Player : public Entity
{

private:

	/*MEMBERS*/
	bool m_thrusterOn;
	bool m_isAlive;
	bool m_respawning;
	int m_shipLives;
	int m_respawnCounter;
	bool m_initialRespawn;
	std::vector<Vector2> thrusterPoints;
	

public:
	
	/*CTOR*/
	Player();

	/*FUNCTIONS*/
	void Update(float) override;
	void Render() override;
	void MoveForward();
	void RotateLeft(float);
	void RotateRight(float);
	void Thruster();
	void setThrusterOn(bool);
	bool getThrusterOn();
	void setIsAlive(bool);
	bool getIsAlive();
	bool getRespawning();
	int getShipLives();
	void respawn();
	Bullet Shoot();
};

	
#endif // !_PLAYER_H_

