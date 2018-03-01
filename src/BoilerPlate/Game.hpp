#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include "App.hpp"
#include <iostream>
#include <algorithm>
#include "Player.hpp"
#include "Asteroid.hpp"
#include "Bullet.h"
#include "InputManager.hpp"
#include <vector>
// OpenGL includes
#include <GL/glew.h>
#include <SDL_opengl.h>

class Game
{
private:
	/*MEMBERS*/
	int m_width;
	int m_height;
	bool m_debuggingOn;
	bool m_resetGame;
	Player m_player;
	MathUtilities mathUtilities;
	std::vector<Asteroid> m_asteroidVector;
	std::vector<Bullet> m_bulletVector;
	std::vector<float> m_framerates;
	int m_time;
	int m_asteroidCount;
	int m_score;

public:

	/*FUNCTIONS*/
	void Update(float);
	void updateEntities(float);
	void updateBulletCollision();
	void updatePlayerCollision();
	void updateBullets(float deltaTime);
	void updateAsteroidsDebugging();
	void updateFrameratesGraphic(float);
	void updateInputManagerMovement();
	void updateAsteroidCount();

	void Render();
	void renderAsteroids();
	void renderBullets();
	void renderPlayerAsteroidLines();
	void renderBulletAsteroidLines();
	void drawFrameratesGraphic();
	void drawShipLives();

	void setDebug();
	void playerShoot();
	bool isColliding(float, float);


	void addAsteroid();
	void removeAsteroid();
	bool resetGame();
	void loadGame();
	void clearGame();
	Player getPlayer();
	void updateFrames(float, float);


	Game();
	~Game();
};

#endif // !_ASTEROID_H_