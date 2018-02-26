#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include "App.hpp"
#include <iostream>
#include <algorithm>
#include "Player.hpp"
#include "Asteroid.hpp"
#include "Bullet.h"
#include <vector>
// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "InputManager.hpp"
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
	InputManager inputManager;
	std::vector<float> framerates;
	int framerateRenderCount;
	int time;
	

	/*FUNCTIONS*/
	void updateBulletCollision();
	void updatePlayerCollision();
	void updateBullets(float deltaTime);
	void updateAsteroidsDebugging();
	void drawFramesGraphic();
	void setDebug();
	void playerShoot();
	bool isColliding(float, float);
	void Update(float);
	void Render();
	void addAsteroid();
	void removeAsteroid();

	
	Game();
	~Game();
};

#endif // !_ASTEROID_H_
