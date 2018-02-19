#include "Asteroid.hpp"
// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

const size_t NUM_POINTS = 16;
const float MIN_SIZE = 25.0f;
const float MAX_SIZE = 45.0f;
MathUtilities mathUtilities;

Asteroid::Asteroid() : Entity()
{
	std::vector<Vector2> pointsToPush;
	pointsToPush.push_back(Vector2(25.0f, 50.0f));
	pointsToPush.push_back(Vector2(25.0f, 25.0f));
	pointsToPush.push_back(Vector2(-30.0f, -25.0f));
	pointsToPush.push_back(Vector2(-50.0f, -25.0f));
	pointsToPush.push_back(Vector2(-30.0f, -40.0f));
	pointsToPush.push_back(Vector2(50.0f, -60.0f));
	pointsToPush.push_back(Vector2(40.0f, -40.0f));
	pointsToPush.push_back(Vector2(60.0f, -30.0f));
	pointsToPush.push_back(Vector2(60.0f, 30.0f));
	pointsToPush.push_back(Vector2(35.0f, 45.0f));
	setPoints(pointsToPush);
	angle = 45;
	size = Asteroid::AsteroidSize::BIG;

}

Asteroid::Asteroid(AsteroidSize::Size newSize) : Entity()
{
	size = newSize;
	std::vector<Vector2> pointsToPush;
	if (size == 4)
	{
		pointsToPush.push_back(Vector2(25.0f, 50.0f));
		pointsToPush.push_back(Vector2(25.0f, 25.0f));
		pointsToPush.push_back(Vector2(-30.0f, -25.0f));
		pointsToPush.push_back(Vector2(-50.0f, -25.0f));
		pointsToPush.push_back(Vector2(-30.0f, -40.0f));
		pointsToPush.push_back(Vector2(50.0f, -60.0f));
		pointsToPush.push_back(Vector2(40.0f, -40.0f));
		pointsToPush.push_back(Vector2(60.0f, -30.0f));
		pointsToPush.push_back(Vector2(60.0f, 30.0f));
		pointsToPush.push_back(Vector2(35.0f, 45.0f));
		
	
		setPoints(pointsToPush);
	}
	else if (size == 2)
	{
		pointsToPush.push_back(Vector2(25.0f*(0.5), 50.0f*(0.5)));
		pointsToPush.push_back(Vector2(25.0f*(0.5), 25.0f*(0.5)));
		pointsToPush.push_back(Vector2(-30.0f*(0.5), -25.0f*(0.5)));
		pointsToPush.push_back(Vector2(-50.0f*(0.5), -25.0f*(0.5)));
		pointsToPush.push_back(Vector2(-30.0f*(0.5), -40.0f*(0.5)));
		pointsToPush.push_back(Vector2(50.0f*(0.5), -60.0f*(0.5)));
		pointsToPush.push_back(Vector2(40.0f*(0.5), -40.0f*(0.5)));
		pointsToPush.push_back(Vector2(60.0f*(0.5), -30.0f*(0.5)));
		pointsToPush.push_back(Vector2(60.0f*(0.5), 30.0f*(0.5)));
		pointsToPush.push_back(Vector2(35.0f*(0.5), 45.0f*(0.5)));
		setPoints(pointsToPush);

	}
	else if (size == 1)
	{
		pointsToPush.push_back(Vector2(25.0f*(0.25), 50.0f*(0.25)));
		pointsToPush.push_back(Vector2(25.0f*(0.25), 25.0f*(0.25)));
		pointsToPush.push_back(Vector2(-30.0f*(0.25), -25.0f*(0.25)));
		pointsToPush.push_back(Vector2(-50.0f*(0.25), -25.0f*(0.25)));
		pointsToPush.push_back(Vector2(-30.0f*(0.25), -40.0f*(0.25)));
		pointsToPush.push_back(Vector2(50.0f*(0.25), -60.0f*(0.25)));
		pointsToPush.push_back(Vector2(40.0f*(0.25), -40.0f*(0.25)));
		pointsToPush.push_back(Vector2(60.0f*(0.25), -30.0f*(0.25)));
		pointsToPush.push_back(Vector2(60.0f*(0.25), 30.0f*(0.25)));
		pointsToPush.push_back(Vector2(35.0f*(0.25), 45.0f*(0.25)));
		setPoints(pointsToPush);
	}
	angle = 45;
}

Asteroid::Asteroid(Vector2 newPosition, AsteroidSize::Size newSize) : Entity()
{
	setPosition(newPosition);
	size = newSize;
	std::vector<Vector2> pointsToPush;
	if (size == 4)
	{
		pointsToPush.push_back(Vector2(25.0f, 50.0f));
		pointsToPush.push_back(Vector2(25.0f, 25.0f));
		pointsToPush.push_back(Vector2(-30.0f, -25.0f));
		pointsToPush.push_back(Vector2(-50.0f, -25.0f));
		pointsToPush.push_back(Vector2(-30.0f, -40.0f));
		pointsToPush.push_back(Vector2(50.0f, -60.0f));
		pointsToPush.push_back(Vector2(40.0f, -40.0f));
		pointsToPush.push_back(Vector2(60.0f, -30.0f));
		pointsToPush.push_back(Vector2(60.0f, 30.0f));
		pointsToPush.push_back(Vector2(35.0f, 45.0f));
		setPoints(pointsToPush);
	}
	else if (size == 2)
	{
		pointsToPush.push_back(Vector2(25.0f*(0.5), 50.0f*(0.5)));
		pointsToPush.push_back(Vector2(25.0f*(0.5), 25.0f*(0.5)));
		pointsToPush.push_back(Vector2(-30.0f*(0.5), -25.0f*(0.5)));
		pointsToPush.push_back(Vector2(-50.0f*(0.5), -25.0f*(0.5)));
		pointsToPush.push_back(Vector2(-30.0f*(0.5), -40.0f*(0.5)));
		pointsToPush.push_back(Vector2(50.0f*(0.5), -60.0f*(0.5)));
		pointsToPush.push_back(Vector2(40.0f*(0.5), -40.0f*(0.5)));
		pointsToPush.push_back(Vector2(60.0f*(0.5), -30.0f*(0.5)));
		pointsToPush.push_back(Vector2(60.0f*(0.5), 30.0f*(0.5)));
		pointsToPush.push_back(Vector2(35.0f*(0.5), 45.0f*(0.5)));
		setPoints(pointsToPush);

	}
	else if (size == 1)
	{
		pointsToPush.push_back(Vector2(25.0f*(0.25), 50.0f*(0.25)));
		pointsToPush.push_back(Vector2(25.0f*(0.25), 25.0f*(0.25)));
		pointsToPush.push_back(Vector2(-30.0f*(0.25), -25.0f*(0.25)));
		pointsToPush.push_back(Vector2(-50.0f*(0.25), -25.0f*(0.25)));
		pointsToPush.push_back(Vector2(-30.0f*(0.25), -40.0f*(0.25)));
		pointsToPush.push_back(Vector2(50.0f*(0.25), -60.0f*(0.25)));
		pointsToPush.push_back(Vector2(40.0f*(0.25), -40.0f*(0.25)));
		pointsToPush.push_back(Vector2(60.0f*(0.25), -30.0f*(0.25)));
		pointsToPush.push_back(Vector2(60.0f*(0.25), 30.0f*(0.25)));
		pointsToPush.push_back(Vector2(35.0f*(0.25), 45.0f*(0.25)));
		setPoints(pointsToPush);

	}
	angle = 45;

}

Asteroid::AsteroidSize::Size Asteroid::GetSize()
{
	return size;
}

void Asteroid::Update() 
{

}

void Asteroid::Render()
{
	Vector2 position = getPosition();
	std::vector<Vector2> points = getPoints();
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);

	glBegin(GL_LINE_LOOP);
	for (Vector2 i : points)
	{
		glVertex2f(i.x, i.y);
	}
	glEnd();

}

void Asteroid::move()
{
	
}


Asteroid::~Asteroid()
{
}
