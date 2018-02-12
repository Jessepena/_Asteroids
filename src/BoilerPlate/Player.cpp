#include "Player.hpp"
// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

const int screenWidth = 568;
const int screenHeight = 320;

Player::Player()
{
	position = Vector2();
	thrusterOn = false;

}


void Player::move(Vector2 positionToMove, SDL_KeyboardEvent event)
{
	Warping();
	Player::position += positionToMove;
	
}
void Player::Update(SDL_KeyboardEvent keyBoardEvent){}

void Player::Render()
{
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);
	
	//Draw ship
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0f, 20.0f);
	glVertex2f(12.0f, -10.0f);
	glVertex2f(6.0f, -4.0f);
	glVertex2f(-6.0f, -4.0f);
	glVertex2f(-12.0f, -10.0f);
	glEnd();
	Thruster();
}

void Player::Thruster() {

	if (thrusterOn) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(-5.0, -4.0);
		glVertex2f(5.0, -4.0);
		glVertex2f(0.0, -15.0);
		glEnd();
	}
}

void Player::Warping() {

	// X axis warping
	if (position.x < -screenWidth)
	{
		position.x = screenWidth;
	}
	else if (position.x > screenWidth) 
	{
		position.x = -screenWidth;
	}

	// Y axis warping
	if (position.y < -screenHeight) 
	{
		position.y = screenHeight;
	}
	else if (position.y > screenHeight) 
	{
		position.y = -screenHeight;
	}
}


void Player::MoveForward() {}

void Player::RotateLeft() {}

void Player::RotateRight() {}
