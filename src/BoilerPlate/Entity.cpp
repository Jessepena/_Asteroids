#include "Entity.h"

MathUtilities math;

Entity::Entity()
{
	position = Vector2();
	orientation = 0.0f;
	mass = 1.0f;
	debuggingOn = false;
	screenWidth = 568;
	screenHeight = 320;
	
}

void Entity::addPosition(Vector2 positionToMove)
{
	position += positionToMove;
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

void Entity::setVelocity(Vector2 newVelocity)
{
	velocity = newVelocity;
}

void Entity::addVelocity(Vector2 newVelocity)
{
	velocity += newVelocity;
}

float Entity::getOrientation()
{
	return orientation;
}

void Entity::addOrientation(float orientationToAdd)
{
	orientation += orientationToAdd;
}

void Entity::setOrientation(float newOrientation)
{
	orientation = newOrientation;
}

void Entity::setPoints(std::vector<Vector2> newPoints)
{
	points = newPoints;
}

bool Entity::getDebuggingOn()
{
	return debuggingOn;
}

void Entity::setDebuggingOn(bool newDebuggingOn)
{
	debuggingOn = newDebuggingOn;
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

void Entity::drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius) 
{
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * M_PI;

	glLoadIdentity();

	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
}

float Entity::getMass()
{
	return mass;
}

void Entity::setMass(float newMass)
{
	mass = newMass;
}

void Entity::setRadius(float newRadius)
{
	radius = newRadius;
}

float Entity::getRadius()
{
	return radius;
}

void Entity::Update(float deltaTime)
{
	Warping();
	addPosition(Vector2(velocity.x * deltaTime, velocity.y * deltaTime));
}


void Entity::updateFrame(int newScreenWidth, int newScreenHeigth)
{
	screenWidth = newScreenWidth;
	screenHeight = newScreenHeigth;
}

Entity::~Entity()
{
}
