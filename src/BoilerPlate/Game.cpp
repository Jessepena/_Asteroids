#include "Game.hpp"


Game::Game()
{
	asteroidVector.push_back(Asteroid(Asteroid::AsteroidSize::Size::BIG));
	bulletReset = 0.0f;
	bulletDeleteCount = 0;
}
Game::~Game()
{

}

void Game::playerShoot()
{
	bulletVector.push_back(player.Shoot());
}

void Game::setDebug()
{
	if (debuggingOn)
	{
		debuggingOn = false;
		player.setDebuggingOn(false);
		for (int i = 0; i < asteroidVector.size(); i++)
		{
			asteroidVector[i].setDebuggingOn(false);
		}
		for (int i = 0; i < bulletVector.size(); i++)
		{
			bulletVector[i].setDebuggingOn(false);
		}
		
	}
	else
	{
		debuggingOn = true;
		player.setDebuggingOn(true);
		for (int i = 0; i < asteroidVector.size(); i++)
		{
			asteroidVector[i].setDebuggingOn(true);
		}
		for (int i = 0; i < bulletVector.size(); i++)
		{
			bulletVector[i].setDebuggingOn(true);
		}
	}
}

void Game::updateBulletCollision()
{
	bool bulletDestroyed = false;
	for (int i = 0; i < bulletVector.size(); i++)
	{
		for (int j = 0; j < asteroidVector.size(); j++)
		{
			float distanceBulletAsteroid = mathUtilities.calculateDistance(bulletVector[i].getPosition().x, bulletVector[i].getPosition().y, asteroidVector[j].getPosition().x, asteroidVector[j].getPosition().y);
			float radiusBulletAsteroid = bulletVector[i].getRadius() + asteroidVector[j].getRadius();

			if (isColliding(distanceBulletAsteroid, radiusBulletAsteroid) && !debuggingOn)
			{
				bulletVector.erase(bulletVector.begin() + i);
				bulletDestroyed = true;
				if (asteroidVector[j].GetSize() == Asteroid::AsteroidSize::Size::BIG)
				{
					asteroidVector.push_back(Asteroid(asteroidVector[j].getPosition(), Asteroid::AsteroidSize::Size::MEDIUM));
					asteroidVector.push_back(Asteroid(asteroidVector[j].getPosition(), Asteroid::AsteroidSize::Size::MEDIUM));
					asteroidVector.erase(asteroidVector.begin() + j);
				}
				else if (asteroidVector[j].GetSize() == Asteroid::AsteroidSize::Size::MEDIUM)
				{
					asteroidVector.push_back(Asteroid(asteroidVector[j].getPosition(), Asteroid::AsteroidSize::Size::SMALL));
					asteroidVector.push_back(Asteroid(asteroidVector[j].getPosition(), Asteroid::AsteroidSize::Size::SMALL));
					asteroidVector.erase(asteroidVector.begin() + j);
				}
				else
					asteroidVector.erase(asteroidVector.begin() + j);

				break;	
			}
		}

		if (bulletDestroyed)
			break;
	}
}

void Game::updatePlayerCollision()
{
	for (int i = 0; i < asteroidVector.size(); i++)
	{
		float distancePlayerAsteroid = mathUtilities.calculateDistance(player.getPosition().x, player.getPosition().y, asteroidVector[i].getPosition().x, asteroidVector[i].getPosition().y);
		float radiusPlayerAsteroid = player.getRadius() + asteroidVector[i].getRadius();
		if (isColliding(distancePlayerAsteroid, radiusPlayerAsteroid) && !debuggingOn)
		{
			player.setPosition(Vector2());
			if (asteroidVector[i].GetSize() == Asteroid::AsteroidSize::Size::BIG)
			{
				asteroidVector.push_back(Asteroid(asteroidVector[i].getPosition(), Asteroid::AsteroidSize::Size::MEDIUM));
				asteroidVector.push_back(Asteroid(asteroidVector[i].getPosition(), Asteroid::AsteroidSize::Size::MEDIUM));
				asteroidVector.erase(asteroidVector.begin() + i);
			}
			else if (asteroidVector[i].GetSize() == Asteroid::AsteroidSize::Size::MEDIUM)
			{
				asteroidVector.push_back(Asteroid(asteroidVector[i].getPosition(), Asteroid::AsteroidSize::Size::SMALL));
				asteroidVector.push_back(Asteroid(asteroidVector[i].getPosition(), Asteroid::AsteroidSize::Size::SMALL));
				asteroidVector.erase(asteroidVector.begin() + i);
			}
			else
				asteroidVector.erase(asteroidVector.begin() + i);
		}
	}
	
}
//alloo que paso? 
// perate que creo que lo toy resolviendo.. quedate viendo
//pero no creo que a roa le guste eso asi en el update mira

void Game::updateAsteroidsDebugging()
{
	if (player.getDebuggingOn())
	{
		for (int i = 0; i < asteroidVector.size(); i++)
		{
			asteroidVector[i].setDebuggingOn(true);
		}
	}
	else
	{
		for (int i = 0; i < asteroidVector.size(); i++)
		{
			asteroidVector[i].setDebuggingOn(false);
		}
	}
}

void Game::updateBullets(float deltaTime)
{
	for (int i = 0; i<bulletVector.size(); i++)
	{
		if (!bulletVector[i].shouldRemove())
			bulletVector[i].Update(deltaTime);
		else
			bulletVector.erase(bulletVector.begin() + i);
	}
}
void Game::Update(float deltaTime)
{
	updateAsteroidsDebugging();
	updateBulletCollision();
	updatePlayerCollision();

	
	player.Update(deltaTime);

	for (int i = 0; i<bulletVector.size(); i++)
	{
		if (!bulletVector[i].shouldRemove())
			bulletVector[i].Update(deltaTime);
		else
			bulletVector.erase(bulletVector.begin() + i);
	}

	for (int i=0; i<asteroidVector.size(); i++)
	{
		asteroidVector[i].Update(deltaTime);
	}
}

bool Game::isColliding(float distance, float radius)
{
	return(distance < radius);
}
void Game::Render()
{
	player.Render();

	for (int i = 0; i<asteroidVector.size(); i++)
	{
		asteroidVector[i].Render();
	}
	
	for (int i = 0; i<bulletVector.size(); i++)
	{
		bulletVector[i].Render();
	}

	for (int i = 0; i < asteroidVector.size(); i++)
	{
		float distance = mathUtilities.calculateDistance(player.getPosition().x, player.getPosition().y, asteroidVector[i].getPosition().x, asteroidVector[i].getPosition().y);
		glLoadIdentity();
		if (debuggingOn && distance < 200)
		{
			if(isColliding(distance,player.getRadius() + asteroidVector[i].getRadius()))
				glColor3f(1.0f, 0.0f, 0.0f);
			else
				glColor3f(0.0f, 1.0f, 0.0f);

			glBegin(GL_LINE_LOOP);
				glVertex2f(player.getPosition().x, player.getPosition().y);
				glVertex2f(asteroidVector[i].getPosition().x, asteroidVector[i].getPosition().y);
			glEnd();
		}
	}

	for (int i = 0; i < bulletVector.size(); i++)
	{
		for (int j = 0; j < asteroidVector.size(); j++)
		{
			float distance = mathUtilities.calculateDistance(bulletVector[i].getPosition().x, bulletVector[i].getPosition().y, asteroidVector[j].getPosition().x, asteroidVector[j].getPosition().y);
			glLoadIdentity();
			if (debuggingOn && distance < 200)
			{
				if (isColliding(distance, bulletVector[i].getRadius() + asteroidVector[j].getRadius()))
					glColor3f(1.0f, 0.0f, 0.0f);
				else
					glColor3f(0.0f, 0.0f, 1.0f);

				glBegin(GL_LINE_LOOP);
				glVertex2f(bulletVector[i].getPosition().x, bulletVector[i].getPosition().y);
				glVertex2f(asteroidVector[j].getPosition().x, asteroidVector[j].getPosition().y);
				glEnd();
			}
		}
	}
}