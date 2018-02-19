#include "Entity.h"


Entity::Entity()
{
	position = Vector2();
	orientation = 0.0f;
	mass = 1.0f;
	
}

void Entity::addPosition(Vector2 positionToMove)
{
	position += positionToMove;
}

void Entity::addOrientation(float orientationToAdd)
{
	orientation += orientationToAdd;
}


Vector2 Entity::getPosition()
{
	return position;
}

void Entity::setPosition(Vector2 newPosition)
{
	position = newPosition;
}

Vector2 Entity::getVelocity()
{
	return velocity;
}

float Entity::getOrientation()
{
	return orientation;
}


void Entity::setPoints(std::vector<Vector2> newPoints)
{
	points = newPoints;
}

std::vector<Vector2> Entity::getPoints()
{
	return points;
}

void Entity::Warping() {

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

void Entity::Update(float deltaTime)
{
	
}


Entity::~Entity()
{
}
