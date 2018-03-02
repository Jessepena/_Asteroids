#include "Player.hpp"
// OpenGL includes
#include <GL/glew.h>
#include <SDL_opengl.h>

const float maxVelocity = 350.0f;
const float frictionFactor = 0.98f;
MathUtilities maths;

Player::Player() : Entity()
{
	m_thrusterOn = false;
	m_isAlive = false;
	m_initialRespawn = true;
	m_respawning = false;
	m_respawnCounter = 0;
	m_shipLives = 3;
	std::vector<Vector2> pointsToPush;
	pointsToPush.push_back(Vector2(0.0f, 20.0f));
	pointsToPush.push_back(Vector2(12.0f, -10.0f));
	pointsToPush.push_back(Vector2(6.0f, -4.0f));
	pointsToPush.push_back(Vector2(-6.0f, -4.0f));
	pointsToPush.push_back(Vector2(-12.0f, -10.0f));
	thrusterPoints.push_back(Vector2(-5.0f, -4.0f));
	thrusterPoints.push_back(Vector2(5.0f, -4.0f));
	thrusterPoints.push_back(Vector2(0.0f, -15.0f));
	setPoints(pointsToPush);
	setRadius(16);
}

void Player::Update(float deltaTime)
{
	float speed = std::fabs(std::sqrtf(getVelocity().x * getVelocity().x + getVelocity().y * getVelocity().y));

	 if(speed > maxVelocity)
		setVelocity(Vector2((getVelocity().x/speed) * maxVelocity, (getVelocity().y / speed) * maxVelocity));
	
	 if (!m_thrusterOn)
	 {
		 setVelocity(getVelocity() * frictionFactor);
	 }
 
	 respawn();
	 
	Entity::Update(deltaTime);
}

void Player::Render()
{
	if (m_isAlive)
	{
		Vector2 position = getPosition();
		std::vector<Vector2> points = getPoints();
		float shipOrientation = getOrientation();
		glLoadIdentity();

		// Translate a vector
		glTranslatef(position.x, position.y, 0.0f);

		// Changes the orientation
		glRotatef(shipOrientation, 0.0f, 0.0f, 1.0f);

		glColor3f(0.235, 0.702, 0.443);

		//Draw ship
		glBegin(GL_POLYGON);
		for (Vector2 i : points)
		{
			glVertex2f(i.x, i.y);
		}
		glEnd();

		glLoadIdentity();

		// Translate a vector
		glTranslatef(position.x, position.y, 0.0f);

		// Changes the orientation
		glRotatef(shipOrientation, 0.0f, 0.0f, 1.0f);

		glColor3f(1.0f, 1.0f, 1.0f);

		glBegin(GL_LINE_LOOP);
		for (Vector2 i : points)
		{
			glVertex2f(i.x, i.y);
		}
		glEnd();

		if (getDebuggingOn())
			drawHollowCircle(position.x, position.y, getRadius());

		Thruster();
	}
	
}

void Player::setThrusterOn(bool newThrusterOn)
{
	m_thrusterOn = newThrusterOn;
}

bool Player::getThrusterOn()
{
	return m_thrusterOn;
}


void Player::setIsAlive(bool newValue)
{
	m_isAlive = newValue;
}

bool Player::getIsAlive()
{
	return m_isAlive;
}

bool Player::getRespawning()
{
	return m_respawning;
}

int Player::getShipLives()
{
	return m_shipLives;
}

void Player::setShipLives(int newShipLife)
{
	m_shipLives = newShipLife;
}

void Player::respawn()
{

	if ((m_initialRespawn || m_shipLives >= 0) && (!m_isAlive && !m_respawning))
	{
		if (m_shipLives > 0)
		{
			m_respawning = true;
			setVelocity(Vector2());
			setPosition(Vector2());
			setOrientation(0);
			if (m_initialRespawn)
				m_initialRespawn = false;
			else
				m_shipLives--;
		}
		else 
			m_shipLives = -1;
	}

	if (m_respawning)
		m_respawnCounter++;
		
	if (m_respawning && m_respawnCounter == 110)
		m_isAlive = true;
	if (m_respawning && m_respawnCounter == 120)
		m_isAlive = false;
	if (m_respawning && m_respawnCounter == 130)
		m_isAlive = true;
	if (m_respawning && m_respawnCounter == 140)
		m_isAlive = false;
	if (m_respawning && m_respawnCounter == 150)
		m_isAlive = true;
	if (m_respawning && m_respawnCounter == 160)
		m_isAlive = false;
	if (m_respawning && m_respawnCounter == 170)
		m_isAlive = true;
	if (m_respawning && m_respawnCounter == 180)
		m_isAlive = false;
	if (m_respawning && m_respawnCounter == 190)
		m_isAlive = true;
	if (m_respawning && m_respawnCounter == 200)
		m_isAlive = false;
	if (m_respawning && m_respawnCounter == 210)
		m_isAlive = true;
	if (m_respawnCounter == 220)
	{
		m_respawning = false;
		m_respawnCounter = 0;
	}

}

void Player::setInitialRespawn(bool newInitialRespawn)
{
	m_initialRespawn = newInitialRespawn;
}

Bullet Player::Shoot()
{
	float orientation = getOrientation();
	float radius = getRadius();
	Vector2 position = getPosition();
	float x = position.x + ((cosf(maths.degreesToRadians(orientation)) + radius) * (-sinf(maths.degreesToRadians(orientation))));
	float y = position.y + ((-sinf(maths.degreesToRadians(orientation)) + radius) * (cosf(maths.degreesToRadians(orientation))));
	Vector2 positionInTip = Vector2(x, y);
	return Bullet(positionInTip, orientation);
}

void Player::Thruster() 
{
	if (m_thrusterOn) 
	{
		glLoadIdentity();
		glTranslatef(getPosition().x, getPosition().y, 0.0f);
		glRotatef(getOrientation(), 0.0f, 0.0f, 1.0f);

		glColor3f(1.0f, 0.647f, 0.0f);
		
		glBegin(GL_POLYGON);
		for (Vector2 i : thrusterPoints)
		{
			glVertex2f(i.x, i.y);
		}
		glEnd();
		
		glColor3f(1.0f, 0.0f, 0.0f);

		glBegin(GL_LINE_LOOP);
		for (Vector2 i : thrusterPoints)
		{
			glVertex2f(i.x, i.y);
		}
		glEnd();
	}
}

void Player::MoveForward()
{
	if (m_isAlive)
	{
		m_thrusterOn = true;
		MathUtilities mathUtilities;
		float shipOrientation = getOrientation();
		if (getMass() > 0)
		{
			Vector2 velocityToAdd(-((7 / getMass()) * sinf(mathUtilities.degreesToRadians(shipOrientation))), (7 / getMass()) * cosf(mathUtilities.degreesToRadians(shipOrientation)));
			addVelocity(velocityToAdd);
		}
	}
}

void Player::RotateLeft(float angle)
{
	addOrientation(angle);
}

void Player::RotateRight(float angle)
{
	addOrientation(-angle);
}
