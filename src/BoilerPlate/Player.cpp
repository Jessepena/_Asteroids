#include "Player.hpp"
// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


Player::Player() : Entity()
{
	thrusterOn = false;
	std::vector<Vector2> pointsToPush;
	pointsToPush.push_back(Vector2(0.0f, 20.0f));
	pointsToPush.push_back(Vector2(12.0f, -10.0f));
	pointsToPush.push_back(Vector2(6.0f, -4.0f));
	pointsToPush.push_back(Vector2(-6.0f, -4.0f));
	pointsToPush.push_back(Vector2(-12.0f, -10.0f));
	setPoints(pointsToPush);
	thrusterPoints.push_back(Vector2(-5.0f, -4.0f));
	thrusterPoints.push_back(Vector2(5.0f, -4.0f));
	thrusterPoints.push_back(Vector2(0.0f, -15.0f));
	
}


void Player::Update(SDL_KeyboardEvent keyBoardEvent){}


void Player::Render()
{
	
	Vector2 position = getPosition();
	std::vector<Vector2> points = getPoints();
	float shipOrientation = getOrientation();
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);
	glRotatef(shipOrientation, 0.0f, 0.0f, 1.0f);

	//Draw ship
	glBegin(GL_LINE_LOOP);
	for (Vector2 i : points)
	{
		glVertex2f(i.x, i.y);
	}
	glEnd();
	Thruster();
	
}
/*
void Player::move(Vector2 positionToMove)
{
	Warping();
	addPosition(positionToMove);
}
*/
void Player::setThrusterOn(bool newThrusterOn)
{
	thrusterOn = newThrusterOn;
}

void Player::Thruster() {

	if (thrusterOn) {
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
	Vector2 positionToAdd;
	MathUtilities mathUtilities;
	float shipOrientation = getOrientation();
	Warping(); 
	positionToAdd.x = -(10 * sinf(mathUtilities.degreesToRadians(shipOrientation)));
	positionToAdd.y = 10 * cosf(mathUtilities.degreesToRadians(shipOrientation));
	addPosition(positionToAdd);
	
}

void Player::RotateLeft(float angle)
{
	addOrientation(angle);
}

void Player::RotateRight(float angle)
{
	addOrientation(-angle);
}
