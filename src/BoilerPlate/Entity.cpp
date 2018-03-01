#include "Entity.h"

MathUtilities math;

Entity::Entity()
{
	m_position = Vector2();	
	m_orientation = 0.0f;
	m_mass = 1.0f;
	m_debuggingOn = false;
	m_screenWidth = 568;
	m_screenHeight = 320;
}


void Entity::addPosition(Vector2 positionToMove)
{
	m_position += positionToMove;
}


Vector2 Entity::getPosition()
{
	return m_position;
}

void Entity::setPosition(Vector2 newPosition)
{
	m_position = newPosition;
}

Vector2 Entity::getVelocity()
{
	return m_velocity;
}

void Entity::setVelocity(Vector2 newVelocity)
{
	m_velocity = newVelocity;
}

void Entity::addVelocity(Vector2 newVelocity)
{
	m_velocity += newVelocity;
}

float Entity::getOrientation()
{
	return m_orientation;
}

void Entity::addOrientation(float orientationToAdd)
{
	m_orientation += orientationToAdd;
}

void Entity::setOrientation(float newOrientation)
{
	m_orientation = newOrientation;
}

void Entity::setPoints(std::vector<Vector2> newPoints)
{
	m_points = newPoints;
}

bool Entity::getDebuggingOn()
{
	return m_debuggingOn;
}

void Entity::setDebuggingOn(bool newDebuggingOn)
{
	m_debuggingOn = newDebuggingOn;
}

int Entity::getScreenWidth()
{
	return m_screenWidth;
}

int Entity::getScreenHeight()
{
	return m_screenHeight;
}

std::vector<Vector2> Entity::getPoints()
{
	return m_points;
}

void Entity::Warping() {

	// X axis warping
	if (m_position.x < -m_screenWidth)
	{
		m_position.x = m_screenWidth;
	}
	else if (m_position.x > m_screenWidth)
	{
		m_position.x = -m_screenWidth;
	}

	// Y axis warping
	if (m_position.y < -m_screenHeight)
	{
		m_position.y = m_screenHeight;
	}
	else if (m_position.y > m_screenHeight)
	{
		m_position.y = -m_screenHeight;
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
	return m_mass;
}

void Entity::setMass(float newMass)
{
	m_mass = newMass;
}

void Entity::setRadius(float newRadius)
{
	m_radius = newRadius;
}

float Entity::getRadius()
{
	return m_radius;
}

void Entity::Update(float deltaTime)
{
	Warping();
	addPosition(Vector2(m_velocity.x * deltaTime, m_velocity.y * deltaTime));
}


void Entity::updateFrame(int newScreenWidth, int newScreenHeigth)
{
	m_screenWidth = newScreenWidth;
	m_screenHeight = newScreenHeigth;
}

Entity::~Entity()
{
}
