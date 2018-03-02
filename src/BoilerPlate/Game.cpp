#include "Game.hpp"
#include "InputManager.hpp"

irrklang::ISoundEngine* soundEngine = irrklang::createIrrKlangDevice();

Game::Game()
{
	m_framerates = std::vector <float>(300);
	m_asteroidVector.push_back(Asteroid(Asteroid::AsteroidSize::Size::BIG));
	m_asteroidCount = 1;
	m_time = 0;
	m_resetGame = false;
	m_score = 0;
	m_debuggingOn = false;
	m_gameStarted = false;

	textRenderer.TextRenderInit();

	initGameFontColor(255, 255, 255, 255);

	gameFont = TTF_OpenFont("Fonts/Space_Age.ttf", 40);

	if (gameFont == NULL) system("PAUSE");
		textRenderer = TextRenderer(gameFont, gameFontColor);
}

Game::~Game()
{

}

void Game::playerShoot()
{
	if (m_bulletVector.size() <= 5) {
		Bullet myBullet = m_player.Shoot();
		myBullet.updateFrame(m_player.getScreenWidth(), m_player.getScreenHeight());
		m_bulletVector.push_back(myBullet);
		soundEngine->play2D("Sounds/fire.wav");
		SDL_Log("Bullet Fired!");
	}
	else
		SDL_Log("Reloading");
}

bool Game::resetGame()
{
	return m_resetGame;
}

void Game::loadGame()
{
	m_framerates = std::vector <float>(300);
	m_asteroidVector.push_back(Asteroid(Asteroid::AsteroidSize::Size::BIG));
	m_time = 0;
	m_score = 0;
	m_asteroidCount = 1;
	m_resetGame = false;
	m_debuggingOn = false;
	m_player = Player();
}

void Game::clearGame()
{
	m_asteroidVector.clear();
	m_bulletVector.clear();
}

void Game::initGameFontColor(int R, int G, int B, int A)
{
	gameFontColor.r = R;
	gameFontColor.g = G;
	gameFontColor.b = B;
	gameFontColor.a = A;
}

void Game::setDebug()
{
	if (m_debuggingOn)
	{
		m_debuggingOn = false;
		m_player.setDebuggingOn(false);
		for (int i = 0; i < m_asteroidVector.size(); i++)
		{
			m_asteroidVector[i].setDebuggingOn(false);
		}
		for (int i = 0; i < m_bulletVector.size(); i++)
		{
			m_bulletVector[i].setDebuggingOn(false);
		}
		SDL_Log("Debugger mode OFF");
	}
	else
	{
		m_debuggingOn = true;
		m_player.setDebuggingOn(true);
		for (int i = 0; i < m_asteroidVector.size(); i++)
		{
			m_asteroidVector[i].setDebuggingOn(true);
		}
		for (int i = 0; i < m_bulletVector.size(); i++)
		{
			m_bulletVector[i].setDebuggingOn(true);
		}
		SDL_Log("Debugger mode ON");
	}
}

void Game::updateBulletCollision()
{
	bool bulletDestroyed = false;
	for (int i = 0; i < m_bulletVector.size(); i++)
	{
		for (int j = 0; j < m_asteroidVector.size(); j++)
		{
			float distanceBulletAsteroid = mathUtilities.calculateDistance(m_bulletVector[i].getPosition().x, m_bulletVector[i].getPosition().y, m_asteroidVector[j].getPosition().x, m_asteroidVector[j].getPosition().y);
			float radiusBulletAsteroid = m_bulletVector[i].getRadius() + m_asteroidVector[j].getRadius();

			if (isColliding(distanceBulletAsteroid, radiusBulletAsteroid) && !m_debuggingOn)
			{
				m_bulletVector.erase(m_bulletVector.begin() + i);
				bulletDestroyed = true;
				if (m_asteroidVector[j].GetSize() == Asteroid::AsteroidSize::Size::BIG)
				{
					soundEngine->play2D("Sounds/bangLarge.wav");
					m_asteroidVector.push_back(Asteroid(m_asteroidVector[j].getPosition(), Asteroid::AsteroidSize::Size::MEDIUM));
					m_asteroidVector.push_back(Asteroid(m_asteroidVector[j].getPosition(), Asteroid::AsteroidSize::Size::MEDIUM));
					m_asteroidVector.erase(m_asteroidVector.begin() + j);
					m_score += 20;
					m_lifeScoreCounter += 20;
				}
				else if (m_asteroidVector[j].GetSize() == Asteroid::AsteroidSize::Size::MEDIUM)
				{
					soundEngine->play2D("Sounds/bangMedium.wav");
					m_asteroidVector.push_back(Asteroid(m_asteroidVector[j].getPosition(), Asteroid::AsteroidSize::Size::SMALL));
					m_asteroidVector.push_back(Asteroid(m_asteroidVector[j].getPosition(), Asteroid::AsteroidSize::Size::SMALL));
					m_asteroidVector.erase(m_asteroidVector.begin() + j);
					m_score += 50;
					m_lifeScoreCounter += 50;
				}
				else
				{
					soundEngine->play2D("Sounds/bangSmall.wav");
					m_asteroidVector.erase(m_asteroidVector.begin() + j);
					m_score += 100;
					m_lifeScoreCounter += 100;
				}
				break;	
			}
		}

		if (bulletDestroyed)
			break;
	}
}

void Game::updatePlayerCollision()
{
	for (int i = 0; i < m_asteroidVector.size(); i++)
	{
		float distancePlayerAsteroid = mathUtilities.calculateDistance(m_player.getPosition().x, m_player.getPosition().y, m_asteroidVector[i].getPosition().x, m_asteroidVector[i].getPosition().y);
		float radiusPlayerAsteroid = m_player.getRadius() + m_asteroidVector[i].getRadius();
		if (isColliding(distancePlayerAsteroid, radiusPlayerAsteroid) && !m_debuggingOn && m_player.getIsAlive() && !m_player.getRespawning())
		{	
			if (m_asteroidVector[i].GetSize() == Asteroid::AsteroidSize::Size::BIG)
			{
				soundEngine->play2D("Sounds/bangLarge.wav");
				m_asteroidVector.push_back(Asteroid(m_asteroidVector[i].getPosition(), Asteroid::AsteroidSize::Size::MEDIUM));
				m_asteroidVector.push_back(Asteroid(m_asteroidVector[i].getPosition(), Asteroid::AsteroidSize::Size::MEDIUM));
				m_asteroidVector.erase(m_asteroidVector.begin() + i);
			}
			else if (m_asteroidVector[i].GetSize() == Asteroid::AsteroidSize::Size::MEDIUM)
			{
				soundEngine->play2D("Sounds/bangMedium.wav");
				m_asteroidVector.push_back(Asteroid(m_asteroidVector[i].getPosition(), Asteroid::AsteroidSize::Size::SMALL));
				m_asteroidVector.push_back(Asteroid(m_asteroidVector[i].getPosition(), Asteroid::AsteroidSize::Size::SMALL));
				m_asteroidVector.erase(m_asteroidVector.begin() + i);
			}
			else
			{
				soundEngine->play2D("Sounds/bangSmall.wav");
				soundEngine->play2D("Sounds/deathRoblox.mp3");
				m_asteroidVector.erase(m_asteroidVector.begin() + i);
			}
			
			m_player.setIsAlive(false);
		}
	}
}

void Game::drawShipLives()
{
		glLoadIdentity();

		glTranslatef(-(m_width / 2.0f) + 35.0f, (m_height / 2.0f) - 35.0f, 0.0f);

		glColor3f(1.0f, 1.0f, 1.0f);
		int lifePosition = 0;
		
		for (int i = 0; i < m_player.getShipLives(); i++)
		{
			glBegin(GL_LINE_LOOP);
			for (Vector2 i : m_player.getPoints())
			{
				glVertex2f(i.x + lifePosition, i.y);
			}
			glEnd();
			lifePosition += 37;
		}
}

void Game::updateAsteroidsDebugging()
{
	if (m_player.getDebuggingOn())
	{
		for (int i = 0; i < m_asteroidVector.size(); i++)
		{
			m_asteroidVector[i].setDebuggingOn(true);
		}
	}
	else
	{
		for (int i = 0; i < m_asteroidVector.size(); i++)
		{
			m_asteroidVector[i].setDebuggingOn(false);
		}
	}
}

void Game::updateFrameratesGraphic(float deltaTime)
{
	if (m_time >= 250)
		m_time = 0;
	m_framerates[m_time] = deltaTime * 80000;
	m_time++;
}

void Game::updateInputManagerMovement()
{
	if(!m_isPaused)
	{
		if (InputManager::IsKeyDown('w') || InputManager::IsKeyDown('W') && m_player.getIsAlive())
		{
			m_player.MoveForward();
			soundEngine->play2D("Sounds/thrust.wav");
		}

		else if (m_player.getIsAlive())
			m_player.setThrusterOn(false);

		if (InputManager::IsKeyDown('a') || InputManager::IsKeyDown('A')) m_player.RotateLeft(5);
		if (InputManager::IsKeyDown('d') || InputManager::IsKeyDown('D')) m_player.RotateRight(5);
		if (InputManager::IsKeyPressed('y') || InputManager::IsKeyPressed('Y'))
		{
			if (m_debuggingOn)
			{
				m_debuggingOn = false;
				m_player.setDebuggingOn(false);
				for (int i = 0; i < m_asteroidVector.size(); i++)
				{
					m_asteroidVector[i].setDebuggingOn(false);
				}
				for (int i = 0; i < m_bulletVector.size(); i++)
				{
					m_bulletVector[i].setDebuggingOn(false);
				}
			}
			else
			{
				m_debuggingOn = true;
				m_player.setDebuggingOn(true);
				for (int i = 0; i < m_asteroidVector.size(); i++)
				{
					m_asteroidVector[i].setDebuggingOn(true);
				}
				for (int i = 0; i < m_bulletVector.size(); i++)
				{
					m_bulletVector[i].setDebuggingOn(true);
				}
			}
		}

		if ((InputManager::IsKeyDown('n') || InputManager::IsKeyDown('N')) && m_debuggingOn)
			addAsteroid();

		if ((InputManager::IsKeyDown('m') || InputManager::IsKeyDown('M')) && m_debuggingOn)
			removeAsteroid();

		if (InputManager::IsKeyPressed(32))
		{
			if (m_player.getIsAlive())
				playerShoot();
		}

		if (InputManager::IsKeyPressed('g') || InputManager::IsKeyPressed('G'))
		{
			m_gameStarted = true;
			m_resetGame = true;
		}

	}
	if (InputManager::IsKeyPressed('p') || InputManager::IsKeyPressed('P'))
	{
		if (m_isPaused)
			m_isPaused = false;
		else
			m_isPaused = true;

		soundEngine->play2D("Sounds/pause.mp3");
	}
	
}

void Game::drawFrameratesGraphic()
{
	if (m_debuggingOn)
	{
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 1.0f, 1.0f);

		for (int i = 0; i < 250; i++)
		{
			glVertex2f(i + 280.0f, m_framerates[i] - 1600.0f);
		}

		glEnd();
	}
}

void Game::updateBullets(float deltaTime)
{
	for (int i = 0; i<m_bulletVector.size(); i++)
	{
		if (!m_bulletVector[i].shouldRemove())
			m_bulletVector[i].Update(deltaTime);
		else
			m_bulletVector.erase(m_bulletVector.begin() + i);
	}
}

void Game::Update(float deltaTime)
{
	/*INPUT MANAGER MOVEMENT*/
	updateInputManagerMovement();

	if (!m_isPaused)
	{
		if (!m_gameStarted)
		{
			/*ENTITIES UPDATE*/
			updateEntities(deltaTime);
		}
		else
		{
			/*ENTITIES UPDATE*/
			updateEntities(deltaTime);

			/*FRAMERATE UPDATE*/
			updateFrameratesGraphic(deltaTime);

			/*COLLISION*/
			updateAsteroidsDebugging();
			updateBulletCollision();
			updatePlayerCollision();
			updateAsteroidCount();

			/*PLAYER LIVES UPDATE*/
			updatePlayerLives();
		}
	}
}

void Game::updateAsteroidCount()
{
	if (m_asteroidVector.size() == 0 && !m_debuggingOn)
	{
		m_asteroidCount++;
		for(int i = 0; i < m_asteroidCount ; i++)
			m_asteroidVector.push_back(Asteroid(Asteroid::AsteroidSize::Size::BIG));
		m_player.setIsAlive(false);
		m_player.setInitialRespawn(true);
	}
}

void Game::updatePlayerLives()
{
	if (m_lifeScoreCounter >= 1500)
	{
		if (m_player.getShipLives() < 3)
		{
			m_player.setShipLives(m_player.getShipLives() + 1);
			soundEngine->play2D("Sounds/extraShip.wav");
		}
		m_lifeScoreCounter = 0;
	}
}

void Game::updateEntities(float deltaTime)
{
	m_player.Update(deltaTime);

	for (int i = 0; i<m_bulletVector.size(); i++)
	{
		if (!m_bulletVector[i].shouldRemove())
			m_bulletVector[i].Update(deltaTime);
		else
			m_bulletVector.erase(m_bulletVector.begin() + i);
	}

	for (int i = 0; i<m_asteroidVector.size(); i++)
	{
		m_asteroidVector[i].Update(deltaTime);
	}
}

bool Game::isColliding(float distance, float radius)
{
	return(distance < radius);
}
int Game::getWidth()
{
	return m_width;
}
int Game::getHeight()
{
	return m_height;
}
void Game::renderBullets()
{
	for (int i = 0; i<m_bulletVector.size(); i++)
	{
		m_bulletVector[i].Render();
	}
}

void Game::renderGameGUI()
{
	if (m_gameStarted)
	{
		textRenderer.RenderText("SCORE " + std::to_string(m_score), gameFontColor, -(m_player.getScreenWidth() / 2.0f) - m_player.getScreenWidth()*0.45f, (m_player.getScreenHeight() / 2.0f) + m_player.getScreenHeight() * 0.20f, 10);
		if (m_player.getShipLives() == -1 && !m_player.getIsAlive())
		{
			textRenderer.RenderText("GAME OVER", gameFontColor, -125.0f, 0.0f, 80);
			textRenderer.RenderText("PRESS 'G' TO PLAY AGAIN", gameFontColor, -225.0f, -50.0f, 0);
		}

		if (m_player.getShipLives() >= 0 && !m_player.getIsAlive())
		{
			textRenderer.RenderText("RESPAWNING", gameFontColor, -100.0f, 50.0f, 0);
		}

		if (m_isPaused)
			textRenderer.RenderText("GAME IS PAUSED", gameFontColor, -180.0f, 100.0f, 0);
	}
	else
	{
		textRenderer.RenderText("ASTEROIDS PUCMM", gameFontColor, -255.0f, 100.0f, 0);
		textRenderer.RenderText("DESTROY ASTEROIDS TO SCORE POINTS", gameFontColor, -285.0f, 75.0f, 0);
		textRenderer.RenderText("USE W , A , D TO MOVE", gameFontColor, -170.0f, -50.0f, 0);
		textRenderer.RenderText("SPACE TO SHOOT!", gameFontColor, -215.0f, -75.0f, 0);
		textRenderer.RenderText("PRESS 'G' TO START GAME", gameFontColor, -230.0f, -100.0f, 0);
	}	
}

void Game::renderPlayerAsteroidLines()
{
	for (int i = 0; i < m_asteroidVector.size(); i++)
	{
		float distance = mathUtilities.calculateDistance(m_player.getPosition().x, m_player.getPosition().y, m_asteroidVector[i].getPosition().x, m_asteroidVector[i].getPosition().y);
		glLoadIdentity();
		if (m_debuggingOn && distance < 200)
		{
			if (isColliding(distance, m_player.getRadius() + m_asteroidVector[i].getRadius()))
				glColor3f(1.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0f, 1.0f, 0.0f);

			glBegin(GL_LINE_LOOP);
			glVertex2f(m_player.getPosition().x, m_player.getPosition().y);
			glVertex2f(m_asteroidVector[i].getPosition().x, m_asteroidVector[i].getPosition().y);
			glEnd();
		}
	}
}

void Game::renderBulletAsteroidLines()
{
	for (int i = 0; i < m_bulletVector.size(); i++)
	{
		for (int j = 0; j < m_asteroidVector.size(); j++)
		{
			float distance = mathUtilities.calculateDistance(m_bulletVector[i].getPosition().x, m_bulletVector[i].getPosition().y, m_asteroidVector[j].getPosition().x, m_asteroidVector[j].getPosition().y);
			glLoadIdentity();
			if (m_debuggingOn && distance < 200)
			{
				if (isColliding(distance, m_bulletVector[i].getRadius() + m_asteroidVector[j].getRadius()))
					glColor3f(1.0f, 0.0f, 0.0f);
				else
					glColor3f(0.0f, 0.0f, 1.0f);

				glBegin(GL_LINE_LOOP);
				glVertex2f(m_bulletVector[i].getPosition().x, m_bulletVector[i].getPosition().y);
				glVertex2f(m_asteroidVector[j].getPosition().x, m_asteroidVector[j].getPosition().y);
				glEnd();
			}
		}
	}
}
void Game::Render()
{
	glLoadIdentity();

	drawFrameratesGraphic();

	m_player.Render();

	renderAsteroids();

	renderBullets();
	
	renderPlayerAsteroidLines();

	renderBulletAsteroidLines();

	drawShipLives();
	
	renderGameGUI();
}

void Game::renderAsteroids()
{
	for (int i = 0; i < m_asteroidVector.size(); i++) {
		m_asteroidVector[i].Render();
	}
}

void Game::addAsteroid()
{
	if (m_debuggingOn)
	{
		m_asteroidVector.push_back(Asteroid());
		SDL_Log("Added Asteroid");
	}
	else
		SDL_Log("Debugger mode is OFF");
}

void Game::removeAsteroid()
{
	if (m_debuggingOn)
	{
		if (m_asteroidVector.size() != 0)
		{
			m_asteroidVector.pop_back();
			SDL_Log("Removed Asteroid");
		}
	}
	else
		SDL_Log("Debugger mode is OFF");
}

Player Game::getPlayer()
{
	return m_player;
}


void Game::updateFrames(float width, float height)
{
	m_width = (int)width;
	m_height = (int)height;

	m_player.updateFrame((int)(width/2), (int)(height/2));
	
	for (int i = 0; i < m_bulletVector.size(); i++)
	{
		m_bulletVector[i].updateFrame((int)(width/2), (int)(height/2));
	}
	
	for (int i = 0; i < m_asteroidVector.size(); i++)
	{
		m_asteroidVector[i].updateFrame((int)(width/2), (int)(height/2));
	}
}



