#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include "App.hpp"
#include <iostream>
#include <algorithm>
#include "Player.hpp"
#include "Asteroid.hpp"
#include "Bullet.h"
//alo dimelo
// no se que mas hacer
// tengo el cerebro fundio, tengo como 7 hora en eto :(
#include <vector>

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

class Game
{
public:

	/*MEMBERS*/
	bool debuggingOn;
	Player player;
	Asteroid asteroid;
	MathUtilities mathUtilities;
	std::vector<Asteroid> asteroidVector;
	std::vector<Bullet> bulletVector;
	float bulletReset;
	int bulletDeleteCount;
	

	/*FUNCTIONS*/
	void updateBulletCollision();
	void updatePlayerCollision();
	void updateBullets(float deltaTime);
	void updateAsteroidsDebugging();
	void setDebug();
	void playerShoot();
	bool isColliding(float, float);
	void Update(float);
	void Render();
	Game();
	~Game();
};

#endif // !_ASTEROID_H_
