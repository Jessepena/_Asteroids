#include "Bullet.h"

Bullet::Bullet(Vector2 newVelocity, Vector2 newPosition, float newOrientation)
{
	setVelocity(newVelocity);
	setPosition(newPosition);
	setOrientation(newOrientation);
	std::vector<Vector2> pointsToPush;
	pointsToPush.push_back(Vector2(0.0f*(0.10), 30.0f*(0.10)));
	pointsToPush.push_back(Vector2(15.0f*(0.10), 20.0f*(0.10)));
	pointsToPush.push_back(Vector2(25.0f*(0.10), 10.0f*(0.10)));
	pointsToPush.push_back(Vector2(20.0f*(0.10), 5.0f*(0.10)));
	pointsToPush.push_back(Vector2(25.0f*(0.10), 0.0f*(0.10)));
	pointsToPush.push_back(Vector2(25.0f*(0.10), -10.0f*(0.10)));
	pointsToPush.push_back(Vector2(15.0f*(0.10), -20.0f*(0.10)));
	pointsToPush.push_back(Vector2(0.0f*(0.10), -25.0f*(0.10)));
	pointsToPush.push_back(Vector2(-15.0f*(0.10), -20.0f*(0.10)));
	pointsToPush.push_back(Vector2(-25.0f*(0.10), -10.0f*(0.10)));
	pointsToPush.push_back(Vector2(-20.0f*(0.10), -5.0f*(0.10)));
	pointsToPush.push_back(Vector2(-25.0f*(0.10), 0.0f*(0.10)));
	pointsToPush.push_back(Vector2(-25.0f*(0.10), 10.0f*(0.10)));
	pointsToPush.push_back(Vector2(-15.0f*(0.10), 20.0f*(0.10)));
	setPoints(pointsToPush);
	setRadius(10);
}


Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime)
{

	Entity::Update(deltaTime);
}

void Bullet::Render()
{
	Vector2 position = getPosition();
	std::vector<Vector2> points = getPoints();

	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);
	
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_LINE_LOOP);
	for (Vector2 i : points)
	{
		glVertex2f(i.x, i.y);
	}
	glEnd();

	if (getDebuggingOn())
		drawHollowCircle(position.x, position.y, getRadius());
}

//que paso? mira