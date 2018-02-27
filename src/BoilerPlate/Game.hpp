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
	private:
		/*MEMBERS*/
		bool m_debuggingOn;
		Player m_player;
		MathUtilities mathUtilities;
		std::vector<Asteroid> m_asteroidVector;
		std::vector<Bullet> m_bulletVector;
		InputManager m_inputManager;
		std::vector<float> m_framerates;
		int m_time;

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

		void Render();
		void renderAsteroids();
		void renderBullets();
		void renderPlayerAsteroidLines();
		void renderBulletAsteroidLines();
		void drawFrameratesGraphic();

		void setDebug();
		void playerShoot();
		bool isColliding(float, float);
		
		
		void addAsteroid();
		void removeAsteroid();
		Player getPlayer();
		InputManager getInputManager();
		void updateFrames(float, float);
		void movingUp();
		void movingLeft();
		void movingRight();
		void notMovingUp();
		void notMovingLeft();
		void notMovingRight();

	
		Game();
		~Game();
};

#endif // !_ASTEROID_H_
