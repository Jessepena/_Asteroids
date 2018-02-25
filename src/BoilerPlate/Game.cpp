#include "Game.hpp"


Game::Game()
{
	asteroidVector.push_back(Asteroid(Asteroid::AsteroidSize::Size::BIG));
}
Game::~Game()
{

}


void Game::Update(float deltaTime)
{
	player.Update(deltaTime);
	
	for (int i=0; i<asteroidVector.size(); i++)
	{
		asteroidVector[i].Update(deltaTime);
	}
}


void Game::Render()
{
	player.Render();

	for (int i = 0; i<asteroidVector.size(); i++)
	{
		asteroidVector[i].Render();
	}
	
	for (int i = 0; i < asteroidVector.size(); i++)
	{

		float distance = mathUtilities.calculateDistance(player.getPosition().x, player.getPosition().y, asteroidVector[i].getPosition().x, asteroidVector[i].getPosition().y);

		if (debuggingOn && distance < 200)
		{
			glBegin(GL_LINE_LOOP);
				glVertex2f(player.getPosition().x, player.getPosition().y);
				glVertex2f(asteroidVector[i].getPosition().x, asteroidVector[i].getPosition().y);
			glEnd();
		}
	}
}