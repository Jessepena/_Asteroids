#include "Asteroid.hpp"
// OpenGL includes
#include <GL/glew.h>
#include <SDL_opengl.h>

const size_t NUM_POINTS = 16;
const float MIN_SIZE = 25.0f;
const float MAX_SIZE = 45.0f;
MathUtilities mathUtilities;

Asteroid::Asteroid() : Entity()
{
	std::vector<Vector2> pointsToPush;
	pointsToPush.push_back(Vector2(0.0f*(2.00), 30.0f*(2.00)));
	pointsToPush.push_back(Vector2(15.0f*(2.00), 20.0f*(2.00)));
	pointsToPush.push_back(Vector2(25.0f*(2.00), 10.0f*(2.00)));
	pointsToPush.push_back(Vector2(20.0f*(2.00), 5.0f*(2.00)));
	pointsToPush.push_back(Vector2(25.0f*(2.00), 0.0f*(2.00)));
	pointsToPush.push_back(Vector2(25.0f*(2.00), -10.0f*(2.00)));
	pointsToPush.push_back(Vector2(15.0f*(2.00), -20.0f*(2.00)));
	pointsToPush.push_back(Vector2(0.0f*(2.00), -25.0f*(2.00)));
	pointsToPush.push_back(Vector2(-15.0f*(2.00), -20.0f*(2.00)));
	pointsToPush.push_back(Vector2(-25.0f*(2.00), -10.0f*(2.00)));
	pointsToPush.push_back(Vector2(-20.0f*(2.00), -5.0f*(2.00)));
	pointsToPush.push_back(Vector2(-25.0f*(2.00), 0.0f*(2.00)));
	pointsToPush.push_back(Vector2(-25.0f*(2.00), 10.0f*(2.00)));
	pointsToPush.push_back(Vector2(-15.0f*(2.00), 20.0f*(2.00)));
	setPoints(pointsToPush);
	setPosition(Vector2(mathUtilities.randInRange(0,1000), mathUtilities.randInRange(0, 1000)));
	angle = 45;
	setOrientation(mathUtilities.randInRange(1, 360));
	size = Asteroid::AsteroidSize::BIG;
	setMass(3);
	move();
	setRadius(55);
}

Asteroid::Asteroid(AsteroidSize::Size newSize) : Entity()
{
	size = newSize;
	std::vector<Vector2> pointsToPush;
	if (size == 4)
	{
		pointsToPush.push_back(Vector2(0.0f*(2.00), 30.0f*(2.00)));
		pointsToPush.push_back(Vector2(15.0f*(2.00), 20.0f*(2.00)));
		pointsToPush.push_back(Vector2(25.0f*(2.00), 10.0f*(2.00)));
		pointsToPush.push_back(Vector2(20.0f*(2.00), 5.0f*(2.00)));
		pointsToPush.push_back(Vector2(25.0f*(2.00), 0.0f*(2.00)));
		pointsToPush.push_back(Vector2(25.0f*(2.00), -10.0f*(2.00)));
		pointsToPush.push_back(Vector2(15.0f*(2.00), -20.0f*(2.00)));
		pointsToPush.push_back(Vector2(0.0f*(2.00), -25.0f*(2.00)));
		pointsToPush.push_back(Vector2(-15.0f*(2.00), -20.0f*(2.00)));
		pointsToPush.push_back(Vector2(-25.0f*(2.00), -10.0f*(2.00)));
		pointsToPush.push_back(Vector2(-20.0f*(2.00), -5.0f*(2.00)));
		pointsToPush.push_back(Vector2(-25.0f*(2.00), 0.0f*(2.00)));
		pointsToPush.push_back(Vector2(-25.0f*(2.00), 10.0f*(2.00)));
		pointsToPush.push_back(Vector2(-15.0f*(2.00), 20.0f*(2.00)));
		setPoints(pointsToPush);
		setMass(3);
		angle = 45;
		setRadius(55);
	}
	else if (size == 2)
	{
		pointsToPush.push_back(Vector2(0.0f*(1.35), 30.0f*(1.35)));
		pointsToPush.push_back(Vector2(15.0f*(1.35), 20.0f*(1.35)));
		pointsToPush.push_back(Vector2(25.0f*(1.35), 10.0f*(1.35)));
		pointsToPush.push_back(Vector2(20.0f*(1.35), 5.0f*(1.35)));
		pointsToPush.push_back(Vector2(25.0f*(1.35), 0.0f*(1.35)));
		pointsToPush.push_back(Vector2(25.0f*(1.35), -10.0f*(1.35)));
		pointsToPush.push_back(Vector2(15.0f*(1.35), -20.0f*(1.35)));
		pointsToPush.push_back(Vector2(0.0f*(1.35), -25.0f*(1.35)));
		pointsToPush.push_back(Vector2(-15.0f*(1.35), -20.0f*(1.35)));
		pointsToPush.push_back(Vector2(-25.0f*(1.35), -10.0f*(1.35)));
		pointsToPush.push_back(Vector2(-20.0f*(1.35), -5.0f*(1.35)));
		pointsToPush.push_back(Vector2(-25.0f*(1.35), 0.0f*(1.35)));
		pointsToPush.push_back(Vector2(-25.0f*(1.35), 10.0f*(1.35)));
		pointsToPush.push_back(Vector2(-15.0f*(1.35), 20.0f*(1.35)));
		setPoints(pointsToPush);
		setMass(2);
		angle = 80; 
		setRadius(27.5);

	}
	else if (size == 1)
	{
		pointsToPush.push_back(Vector2(0.0f*(0.75), 30.0f*(0.75)));
		pointsToPush.push_back(Vector2(15.0f*(0.75), 20.0f*(0.75)));
		pointsToPush.push_back(Vector2(25.0f*(0.75), 10.0f*(0.75)));
		pointsToPush.push_back(Vector2(20.0f*(0.75), 5.0f*(0.75)));
		pointsToPush.push_back(Vector2(25.0f*(0.75), 0.0f*(0.75)));
		pointsToPush.push_back(Vector2(25.0f*(0.75), -10.0f*(0.75)));
		pointsToPush.push_back(Vector2(15.0f*(0.75), -20.0f*(0.75)));
		pointsToPush.push_back(Vector2(0.0f*(0.75), -25.0f*(0.75)));
		pointsToPush.push_back(Vector2(-15.0f*(0.75), -20.0f*(0.75)));
		pointsToPush.push_back(Vector2(-25.0f*(0.75), -10.0f*(0.75)));
		pointsToPush.push_back(Vector2(-20.0f*(0.75), -5.0f*(0.75)));
		pointsToPush.push_back(Vector2(-25.0f*(0.75), 0.0f*(0.75)));
		pointsToPush.push_back(Vector2(-25.0f*(0.75), 10.0f*(0.75)));
		pointsToPush.push_back(Vector2(-15.0f*(0.75), 20.0f*(0.75)));
		setPoints(pointsToPush);
		setMass(1);
		angle = 120;
		setRadius(20);
	}
	setPosition(Vector2(mathUtilities.randInRange(0, 1000), mathUtilities.randInRange(0, 1000)));
	setOrientation(mathUtilities.randInRange(1, 360));
	move();
}

Asteroid::Asteroid(Vector2 newPosition, AsteroidSize::Size newSize) : Entity()
{
	setPosition(newPosition);
	size = newSize;
	std::vector<Vector2> pointsToPush;
	if (size == 4)
	{
		pointsToPush.push_back(Vector2(0.0f*(2.00), 30.0f*(2.00)));
		pointsToPush.push_back(Vector2(15.0f*(2.00), 20.0f*(2.00)));
		pointsToPush.push_back(Vector2(25.0f*(2.00), 10.0f*(2.00)));
		pointsToPush.push_back(Vector2(20.0f*(2.00), 5.0f*(2.00)));
		pointsToPush.push_back(Vector2(25.0f*(2.00), 0.0f*(2.00)));
		pointsToPush.push_back(Vector2(25.0f*(2.00), -10.0f*(2.00)));
		pointsToPush.push_back(Vector2(15.0f*(2.00), -20.0f*(2.00)));
		pointsToPush.push_back(Vector2(0.0f*(2.00), -25.0f*(2.00)));
		pointsToPush.push_back(Vector2(-15.0f*(2.00), -20.0f*(2.00)));
		pointsToPush.push_back(Vector2(-25.0f*(2.00), -10.0f*(2.00)));
		pointsToPush.push_back(Vector2(-20.0f*(2.00), -5.0f*(2.00)));
		pointsToPush.push_back(Vector2(-25.0f*(2.00), 0.0f*(2.00)));
		pointsToPush.push_back(Vector2(-25.0f*(2.00), 10.0f*(2.00)));
		pointsToPush.push_back(Vector2(-15.0f*(2.00), 20.0f*(2.00)));
		setPoints(pointsToPush);
		setMass(3);
		angle = 45;
		setRadius(55);
	}
	else if (size == 2)
	{
		pointsToPush.push_back(Vector2(0.0f*(1.35), 30.0f*(1.35)));
		pointsToPush.push_back(Vector2(15.0f*(1.35), 20.0f*(1.35)));
		pointsToPush.push_back(Vector2(25.0f*(1.35), 10.0f*(1.35)));
		pointsToPush.push_back(Vector2(20.0f*(1.35), 5.0f*(1.35)));
		pointsToPush.push_back(Vector2(25.0f*(1.35), 0.0f*(1.35)));
		pointsToPush.push_back(Vector2(25.0f*(1.35), -10.0f*(1.35)));
		pointsToPush.push_back(Vector2(15.0f*(1.35), -20.0f*(1.35)));
		pointsToPush.push_back(Vector2(0.0f*(1.35), -25.0f*(1.35)));
		pointsToPush.push_back(Vector2(-15.0f*(1.35), -20.0f*(1.35)));
		pointsToPush.push_back(Vector2(-25.0f*(1.35), -10.0f*(1.35)));
		pointsToPush.push_back(Vector2(-20.0f*(1.35), -5.0f*(1.35)));
		pointsToPush.push_back(Vector2(-25.0f*(1.35), 0.0f*(1.35)));
		pointsToPush.push_back(Vector2(-25.0f*(1.35), 10.0f*(1.35)));
		pointsToPush.push_back(Vector2(-15.0f*(1.35), 20.0f*(1.35)));
		setPoints(pointsToPush);
		setMass(2);
		angle = 80;
		setRadius(27.5);
	}
	else if (size == 1)
	{
		pointsToPush.push_back(Vector2(0.0f*(0.75), 30.0f*(0.75)));
		pointsToPush.push_back(Vector2(15.0f*(0.75), 20.0f*(0.75)));
		pointsToPush.push_back(Vector2(25.0f*(0.75), 10.0f*(0.75)));
		pointsToPush.push_back(Vector2(20.0f*(0.75), 5.0f*(0.75)));
		pointsToPush.push_back(Vector2(25.0f*(0.75), 0.0f*(0.75)));
		pointsToPush.push_back(Vector2(25.0f*(0.75), -10.0f*(0.75)));
		pointsToPush.push_back(Vector2(15.0f*(0.75), -20.0f*(0.75)));
		pointsToPush.push_back(Vector2(0.0f*(0.75), -25.0f*(0.75)));
		pointsToPush.push_back(Vector2(-15.0f*(0.75), -20.0f*(0.75)));
		pointsToPush.push_back(Vector2(-25.0f*(0.75), -10.0f*(0.75)));
		pointsToPush.push_back(Vector2(-20.0f*(0.75), -5.0f*(0.75)));
		pointsToPush.push_back(Vector2(-25.0f*(0.75), 0.0f*(0.75)));
		pointsToPush.push_back(Vector2(-25.0f*(0.75), 10.0f*(0.75)));
		pointsToPush.push_back(Vector2(-15.0f*(0.75), 20.0f*(0.75)));
		setPoints(pointsToPush);
		setMass(1);
		angle = 120;
		setRadius(20);
	}

	setOrientation(mathUtilities.randInRange(1, 360));
	move();

}
Asteroid::AsteroidSize::Size Asteroid::GetSize()
{
	return size;
}

void Asteroid::Update(float deltaTime)
{
	
	angle += mathUtilities.randInRange(120, 150) * deltaTime;
	
	Entity::Update(deltaTime);

}

void Asteroid::Render()
{
	Vector2 position = getPosition();

	std::vector<Vector2> points = getPoints();

	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);

	glColor3f(1.0f, 1.0f, 1.0f);

	// e que points size siempre va a ser lo mismo
	glBegin(GL_LINE_LOOP);
	for (Vector2 i : points)
	{
		glVertex2f(i.x, i.y);
	}
	glEnd();

	if(getDebuggingOn())
		drawHollowCircle(position.x, position.y, getRadius());

}

void Asteroid::move()
{
	MathUtilities mathUtilities;
	float asteroidOrientation = getOrientation();
	if (getMass() > 0)
	{
		Vector2 velocityToAdd(-((mathUtilities.randInRange(100,200) / getMass()) * sinf(mathUtilities.degreesToRadians(asteroidOrientation))), (mathUtilities.randInRange(100,200) / getMass()) * cosf(mathUtilities.degreesToRadians(asteroidOrientation)));
		setVelocity(velocityToAdd);
	}
}


Asteroid::~Asteroid()
{
}
