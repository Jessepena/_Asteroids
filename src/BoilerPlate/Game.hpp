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
//Sound Library includes
#include <irrKlang.h>
//Text Renderer
#include "TextRenderer.hpp"

class Game
{
private:
	/*MEMBERS*/
	int m_width;
	int m_height;
	bool m_debuggingOn;
	bool m_resetGame;
	bool m_isPaused;
	bool m_gameStarted;
	Player m_player;
	MathUtilities mathUtilities;
	std::vector<Asteroid> m_asteroidVector;
	std::vector<Bullet> m_bulletVector;
	std::vector<float> m_framerates;
	int m_time;
	int m_asteroidCount;
	int m_score;
	int m_lifeScoreCounter;
	TextRenderer textRenderer;
	TTF_Font *gameFont;
	SDL_Color gameFontColor;

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
	void updatePlayerLives();

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
	int getWidth();
	int getHeight();

	void addAsteroid();
	void removeAsteroid();
	bool resetGame();
	void loadGame();
	void clearGame();
	Player getPlayer();
	void updateFrames(float, float);
	void initGameFontColor(int, int, int, int);
	void renderGameGUI();
	


	Game();
	~Game();
};

#endif // !_ASTEROID_H_