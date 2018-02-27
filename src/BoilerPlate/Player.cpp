#include "Player.hpp"
// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

const float maxVelocity = 350.0f;
const float frictionFactor = 0.98f;

Player::Player() : Entity()
{
	thrusterOn = false;
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
	
	 if (!thrusterOn)
	 {
		 setVelocity(getVelocity() * frictionFactor);
	 }

	Entity::Update(deltaTime);
}

void Player::Render()
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

void Player::setThrusterOn(bool newThrusterOn)
{
	thrusterOn = newThrusterOn;
}

bool Player::getThrusterOn()
{
	return thrusterOn;
}

Bullet Player::Shoot()
{
	return Bullet(getPosition(), getOrientation());
}

void Player::Thruster() 
{
	if (thrusterOn) 
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
	thrusterOn = true;
	MathUtilities mathUtilities;
	float shipOrientation = getOrientation();
	if (getMass() > 0)
	{
		Vector2 velocityToAdd(-((5 / getMass()) * sinf(mathUtilities.degreesToRadians(shipOrientation))), (5 / getMass()) * cosf(mathUtilities.degreesToRadians(shipOrientation)));
		addVelocity(velocityToAdd);
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
